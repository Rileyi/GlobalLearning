#include "UsableGraph.h"

using namespace std;

UsableGraph::UsableGraph(PreGraph* preGraph, unsigned int length, unsigned int maxWidth,
                         const Module& asked, const Module& authorizedDifferences) :
    m_nodes(new vector<std::list<ModuleNode*>>()), m_currentNode(nullptr),
    m_length(length), m_maxWidth(maxWidth), m_numberOfPaths(0),
    m_asked(asked), m_authorizedDifferences(authorizedDifferences), m_min(INT_MAX), m_max(INT_MIN),
    m_maxDifference(0), m_averageDifference(0),
    m_errors("")
{
    cout << "\n\nTransforming the pre-graph in usable graph.\n";

    map<const GraphElement*, twoInts*>* geMap = new map<const GraphElement*, twoInts*>();
    string validityErrors = "";

    cout << "Getting the GE map and checking for validity.\n";
    int* w = new int(0);
    preGraph->getContenu()->distanceAndValidity(geMap, nullptr, 0, w, &validityErrors);
    delete w;

    if (validityErrors.compare("") != 0)
    {
        cout << "\nError(s) detected when checking the graph validity:\n" << validityErrors << '\n';
        return;
    }

    cout << "The pre-graph is valid.\n\n";

    m_nodes->insert(m_nodes->end(), length+2, list<ModuleNode*>());

    map<const ModuleGE*, ModuleNode*> mgeToMn;
    map<ModuleNode*, const ModuleGE*> mnToMge;

    for(map<const GraphElement*, twoInts*>::const_iterator it = geMap->begin();
        it != geMap->end(); it++)
    {
        const ModuleGE* mge;
        if ((mge = dynamic_cast<const ModuleGE*>(it->first)) != nullptr)
        {
            cout << "Insertion of node " << mge->toString();
            cout << '(' << it->second->fst << ',' << it->second->snd << ")\n";

            if (static_cast<unsigned>(it->second->fst) >= length+2)
            {
                validityErrors += "Graph is too long.\n";
                cout <<validityErrors;
                cout << it->second->fst  << ">" << length+1 << "\n";
                return;
            }

            ModuleNode* mn = new ModuleNode(mge);
            mgeToMn[mge] = mn;
            mnToMge[mn] = mge;

            for (list<ModuleNode*>::iterator it2 = (*m_nodes)[it->second->fst].begin(); ; it2++)
            {
                if (it2 == (*m_nodes)[it->second->fst].end()  ||
                    ((*geMap)[mnToMge[*it2]])->snd  >  it->second->snd)
                {
                    (*m_nodes)[it->second->fst].insert(it2, mn);
                    break;
                }
            }
        }
    }

    cout << "\n\nAdded the list of node to the graph.\n";

    cout << "\nLinking parent nodes to children nodes:";
    for(map<const ModuleGE*, ModuleNode*>::iterator it = mgeToMn.begin(); it != mgeToMn.end(); it++)
    {
        cout << '\n' << it->first->toString() << "->";
        for (const ModuleGE* mge : *(it->first->getNextModuleGEs()))
        {
            cout << " " << mge->toString();
            ModuleNode* mn = mgeToMn[mge];
            it->second->addNext(mn);
            mn->addPrevious(it->second);
        }
    }

    if (getWidth() > getMaxWidth())
    {
        validityErrors += "Graph is too wide.\n";
        cout << validityErrors;
    }

    m_currentNode = m_nodes->front().front();

    cout << "\n\nUsable graph completely generated.\n";

    cout << "\nComputing the graph data.\n";

    if (m_currentNode->calculatePathData(m_asked, m_authorizedDifferences, &m_min, &m_max,
                                           &m_numberOfPaths, &m_maxDifference, &m_averageDifference))
    {
        cout << "Graph matches with the asked learnings values.\n";
    }
    else
    {
        validityErrors += "Graph does not meet the demanded learnings values.\n";
        cout << validityErrors;
    }
}

UsableGraph::UsableGraph(const UsableGraph& other) :
    m_nodes(new vector<std::list<ModuleNode*>>(*(other.m_nodes))),
    m_currentNode(other.m_currentNode),
    m_length(other.m_length), m_maxWidth(other.m_maxWidth), m_numberOfPaths(other.m_numberOfPaths),
    m_asked(other.m_asked), m_authorizedDifferences(other.m_authorizedDifferences),
    m_min(other.m_min), m_max(other.m_max),
    m_maxDifference(other.m_maxDifference), m_averageDifference(other.m_averageDifference),
    m_errors(other.m_errors)
{}

UsableGraph::~UsableGraph()
{
    delete m_nodes;
}

UsableGraph& UsableGraph::operator=(const UsableGraph& other)
{
    if (other.m_nodes != m_nodes)
    {
        delete m_nodes;
        m_nodes = new vector<std::list<ModuleNode*>>(*(other.m_nodes));
    }
    return *this;
}


void UsableGraph::display() const
{
    for(list<ModuleNode*> column : *m_nodes)
    {
        for(ModuleNode* mn : column)
        {
            mn->display();
            cout << '(' << mn->getNext()->size() << ")     ";
        }
        cout << '\n';
    }
}


bool UsableGraph::moveForward(unsigned int k)
{
    if (k >= m_currentNode->getNext()->size()) return false;
    m_currentNode = m_currentNode->getNext()->at(k);
    return true;
}

bool UsableGraph::moveForwardTo(ModuleNode* mn)
{
    for (ModuleNode* next : (*m_currentNode->getNext()))
    {
        if (mn == next)
        {
            m_currentNode = next;
            return true;
        }
    }

    return false;
}

bool UsableGraph::moveBackward(unsigned int k)
{
    if (k >= m_currentNode->getPrevious()->size()) return false;
    m_currentNode = m_currentNode->getPrevious()->at(k);
    return true;
}

bool UsableGraph::moveBackwardTo(ModuleNode* mn)
{
    for (ModuleNode* previous : (*m_currentNode->getNext()))
    {
        if (mn == previous)
        {
            m_currentNode = previous;
            return true;
        }
    }

    return false;
}

unsigned int UsableGraph::getWidth() const
{
    unsigned int width = 0;
    for (list<ModuleNode*> column : (*m_nodes))
    {
        if (width < column.size()) width = column.size();
    }
    return width;
}
