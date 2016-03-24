#include "UsableGraph.h"

using namespace std;

UsableGraph::UsableGraph(PreGraph* preGraph, int length, int maxWidth,
                         int askedReading, int askedWriting, int askedMaths, int askedFun
                         //, int authorizedDifference, int negligibleDifference
                         ) :
    m_nodes(new vector<std::list<ModuleNode*>>()), m_currentNode(nullptr),
    m_length(length), m_maxWidth(maxWidth), //m_width(0), //m_numberOfPaths(0),
    m_askedReading(askedReading), m_askedWriting(askedWriting), m_askedMaths(askedMaths), m_askedFun(askedFun),
    //m_averageReading(0), m_averageWriting(0), m_averageMaths(0), m_averageFun(0),
    //m_minReading(0), m_minWriting(0), m_minMaths(0), m_minFun(0),
    //m_maxReading(0), m_maxWriting(0), m_maxMaths(0), m_maxFun(0),
    //m_authorizedDifference(authorizedDifference), m_negligibleDifference(negligibleDifference),
    //m_maxDifference(0), m_averageDifference(0),
    m_errors("")
{
    cout << "\n\nTransforming the pre-graph in usable graph.\n";

    map<const GraphElement*, twoInts*>* geMap = new map<const GraphElement*, twoInts*>();
    string validityErrors = "";

    cout << "Getting the GE map and checking for validity.\n";
    preGraph->getContenu()->distanceAndValidity(geMap, nullptr, 0, 0, &validityErrors);

    if (validityErrors.compare("") != 0)
    {
        cout << "\nError(s) detected when checking the graph validity:\n" << validityErrors << '\n';
        return;
    }

    cout << "The pre-graph is valid.\n\n";

    m_nodes->insert(m_nodes->end(), length, list<ModuleNode*>());

    map<const ModuleGE*, ModuleNode*> mgeToMn;
    map<ModuleNode*, const ModuleGE*> mnToMge;

    for(map<const GraphElement*, twoInts*>::const_iterator it = geMap->begin();
        it != geMap->end(); it++)
    {
        const ModuleGE* mge;
        cout << "\nEncounter";
        if ((mge = dynamic_cast<const ModuleGE*>(it->first)) != nullptr)
        {
            cout << " and insertion of node " << mge->toString() << '(' << it->second->fst << ',' << it->second->snd << ")";

            if (it->second->fst >= length)
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
                    cout << " there: ";
                    (*m_nodes)[it->second->fst].insert(it2, mn);
                    cout << "done.";
                    break;
                }

                cout << " not there...";
            }
        }
    }

    cout << "\n\nAdded the list of node to the graph.\n";

    for(map<const ModuleGE*, ModuleNode*>::iterator it = mgeToMn.begin(); it != mgeToMn.end(); it++)
    {
        cout << "\nAdding children to node " << it->first->toString() << ":";
        for (const ModuleGE* mge : *(it->first->getNextModuleGEs()))
        {
            cout << " " << mge->toString();
            ModuleNode* mn = mgeToMn[mge];
            it->second->addNext(mn);
            mn->addPrevious(it->second);
        }
    }

    m_currentNode = m_nodes->front().front();

    cout << "\n\nUsable graph completely generated.\n";
}

UsableGraph::UsableGraph(const UsableGraph& other) :
    m_nodes(new vector<std::list<ModuleNode*>>(*(other.m_nodes))),
    m_currentNode(other.m_currentNode),
    m_length(other.m_length), m_maxWidth(other.m_maxWidth), //m_width(other.m_width), //m_numberOfPaths(0),
    m_askedReading(other.m_askedReading), m_askedWriting(other.m_askedWriting), m_askedMaths(other.m_askedMaths), m_askedFun(other.m_askedFun),
    //m_averageReading(other.m_averageReading), m_averageWriting(other.m_averageWriting), m_averageMaths(other.m_averageMaths), m_averageFun(other.m_averageFun),
    //m_minReading(other.m_minReading), m_minWriting(other.m_minWriting), m_minMaths(other.m_minMaths), m_minFun(other.m_minFun),
    //m_maxReading(other.m_maxReading), m_maxWriting(other.m_maxWriting), m_maxMaths(other.m_maxMaths), m_maxFun(other.m_maxFun),
    //m_authorizedDifference(other.m_authorizedDifference), m_negligibleDifference(other.m_negligibleDifference),
    //m_maxDifference(other.m_maxDifference), m_averageDifference(other.m_averageDifference),
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
