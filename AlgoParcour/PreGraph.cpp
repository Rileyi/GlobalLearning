#include "PreGraph.h"

using namespace std;

PreGraph::PreGraph(map<const Module*, int>& modules) :
    m_contenu(new Node(nullptr))
{
    Node* currentNode = m_contenu;
    for(map<const Module*, int>::iterator it = modules.begin();
        it != modules.end(); ++it)
    {
        while(--(it->second) >= 0)
        {
            Node* newNode = new Node(it->first, currentNode, nullptr);
            currentNode->setNext(newNode);
            currentNode = newNode;
        }
    }

    currentNode->setNext(new Node(nullptr, currentNode, nullptr));

    m_contenu->display();
    cout <<'\n';
}


void PreGraph::add(map<const Module*, int>*& modules)
{
    cout <<"add->start\n";
    Link* forkPlace = new Link();
    m_contenu->bestFork(&modules, forkPlace);
    cout <<"add->after bestFork\n";
    for (map<const Module*, int>::iterator it = modules->begin(); it!=modules->end(); ++it)
    {
        cout << it->second << '*' << *(it->first) << '\n';
    }
    if (forkPlace->isEmpty()) return;
    forkPlace->getAfter()->display();
    cout <<'\n';
    Link* junctionPlace = new Link();
    Side junctionSide = Side::both;
    int distance = 0;

    Side forkSide = forkPlace->getAfter()->bestJunction(&modules, junctionPlace, &junctionSide,
                                            forkPlace->getBefore(), &distance);
    cout <<"add->afterBestJunction\n";
    if (junctionPlace->isEmpty()) return;

    junctionPlace->getAfter()->display();
    cout <<'\n';

    Fork* fork = new Fork(*forkPlace, forkSide);
    Junction* junction =  new Junction(*junctionPlace, junctionSide);

    if (modules->empty())
    {
        //Cas particulier dans lequel on a interet a inverser l'ordre entre fourche et jonction
        cout <<"add->no modules\n";

        forkPlace->getBefore()->changeNext(fork, junction);
        junctionPlace->getAfter()->changePrevious(junction, fork);

        fork->setPrevious(junction);
        junction->setNext(fork);

        if (forkSide == Side::left)
        {
            junction->setRight(forkPlace->getBefore());
            fork->setLeft(junctionPlace->getAfter());
        }
        else
        {
            junction->setLeft(forkPlace->getBefore());
            fork->setRight(junctionPlace->getAfter());
        }

    }
    else
    {
        cout <<"add->path\n";
        cout <<"add->Modules left:\n";
        for (map<const Module*, int>::iterator it = modules->begin(); it!=modules->end(); ++it)
        {
            cout << it->second << '*' << *(it->first) << '\n';
        }
        map<const Module*, int>::iterator it = modules->begin();
        Node* firstNode = new Node(it->first, fork, nullptr);

        if (forkSide == Side::left)
        {
            cout <<"add->forking left\n";
            fork->setLeft(firstNode);
        }
        else
        {
            cout <<"add->forking right\n";
            fork->setRight(firstNode);
        }
        cout <<"add->forked first Node: " << *(it->first) << '\n';
        Node* lastNode = firstNode;
        for(--(it->second) ; it != modules->end(); ++it)
        {
            while(--(it->second) >= 0)
            {
                cout <<"add->node " << *(it->first) << '\n';
                Node* newNode = new Node(it->first, lastNode, nullptr);
                lastNode->setNext(newNode);
                lastNode = newNode;
            }
        }
        cout <<"add->pathed\n";

        if (junctionSide == Side::left)
        {
            cout <<"add->junction left\n";
            junction->setLeft(lastNode);
        }
        else
        {
            cout <<"add->junction right\n";
            junction->setRight(lastNode);
        }

        lastNode->setNext(junction);

        cout <<"add->juncted\n";
    }

    delete forkPlace;
    delete junctionPlace;

    m_contenu->display();
    cout <<'\n';
}

PreGraph::~PreGraph()
{
    if (m_contenu != nullptr)
    {
        m_contenu->recursiveDelete();
        delete m_contenu;
    }
    m_contenu = nullptr;
}

PreGraph::PreGraph(const PreGraph& other) :
    m_contenu(other.m_contenu)
{}

PreGraph& PreGraph::operator=(const PreGraph& rhs)
{
    if (this == &rhs) return *this;
    m_contenu = rhs.m_contenu;
    return *this;
}
