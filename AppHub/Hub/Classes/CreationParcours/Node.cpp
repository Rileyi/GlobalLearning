#include "Node.h"

using namespace std;

int Node::bestFork(map<const Module*, int>** modules, Link* forkPlace)
{
    cout << "Node[" << m_module << "]->bestfork->start\n";

    map<const Module*, int>::iterator it = (*modules)->find(m_module);

    cout << "Node[" << m_module << "]->bestfork>after find\n";

    //Si le module du noeud est trouve
    if (it != (*modules)->end())
    {
        cout << "Node[" << m_module << "]->bestfork->match\n";
        //On le retire de notre map
        if(it->second > 1)
        {
            --(it->second);
        }
        else
        {
            (*modules)->erase(it);
        }

        cout << "Node[" << m_module << "]->bestfork->module erased\n";

        //On sauve this->n_next car il va etre modifie lorsque va deplacer le module
        GraphElement* next = m_next;

        //Si le point de fourche est deja trouve, on replace le module avant le point de fourche:
        if (!forkPlace->isEmpty())
        {
            cout << "Node[" << m_module << "]->bestfork->moving\n";
            moveBefore(*forkPlace);
        }

        cout << "Node[" << m_module << "]->bestfork->recursive call and exit\n";

        //Puis on continue a iterer

        return 1 + next->bestFork(modules, forkPlace);
    }

    cout << "Node[" << m_module << "]->bestfork->no match\n";
    //le module n'a pas ete trouve dans la liste
    if (forkPlace->isEmpty()  &&  m_module != nullptr)
    {
        //Si le point de fourche n'est pas encore trouve
        cout << "Node[" << m_module << "]->bestfork->new fork place\n";
        forkPlace->setBefore(m_previous);
        forkPlace->setAfter(this);
        //Maintenant il est trouve
    }

    return m_next == nullptr ? 0 : m_next->bestFork(modules, forkPlace);
}


Side Node::bestJunction(map<const Module*, int>** modules, Link* junctionPlace, Side* side,
                        GraphElement* callingNode, int* distance)
{
    cout << "Node[" << m_module << "]->bestJunction->start\n";

    map<const Module*, int>::iterator it = (*modules)->find(m_module);

    if (callingNode == m_previous)
    {
        cout << "Node[" << m_module << "]->bestJunction->forward\n";

        ++*distance;

        if (m_module == nullptr || it != (*modules)->end())
        {
            cout << "Node[" << m_module << "]->bestJunction->module found or nullptr\n";

            if (it != (*modules)->end())
            {
                cout << "Node[" << m_module << "]->bestJunction->removing module\n";
                if(it->second > 1)
                {
                    --(it->second);
                }
                else
                {
                    (*modules)->erase(it);
                }
            }

            if (junctionPlace->isEmpty())
            {
                cout << "Node[" << m_module << "]->bestJunction->new junction place\n";
                junctionPlace->setBefore(m_previous);
                junctionPlace->setAfter(this);
            }

            cout << "Node[" << m_module << "]->bestJunction->recursive call\n";
            GraphElement* previousJunctionGE = junctionPlace->getAfter();
            Side returnSide = m_next == nullptr ? *side
                    : m_next->bestJunction(modules, junctionPlace, side, this, distance);

            if (junctionPlace->getAfter() == previousJunctionGE)
            {
                cout << "Node[" << m_module << "]->bestJunction->junctionPlace still on this path\n";
                --*distance;
            }
            else
            {
                cout << "Node[" << m_module << "]->bestJunction->junctionPlace was moved to another area\n";
                cout << "Node[" << m_module << "]->bestJunction->replacing module in the list\n";
                it = (*modules)->find(m_module);
                if (it == (*modules)->end())
                {
                    (**modules)[m_module] = 1;
                }
                else
                {
                    ++(it->second);
                }
            }

            cout << "Node[" << m_module << "]->bestJunction->exit\n";
            return returnSide;
        }
        else
        {
            cout << "Node[" << m_module << "]->bestJunction->module not found\n";

            if (!junctionPlace->isEmpty())
            {
                GraphElement* next = m_next;
                GraphElement* previous = this;
                previous = m_previous;
                cout << "Node[" << m_module << "]->bestJunction->moving node\n";
                moveBefore(*junctionPlace);
                cout << "Node[" << m_module << "]->bestJunction->recursive call and exit\n";
                return next->bestJunction(modules, junctionPlace, side, previous, distance);
            }
            else
            {
                return m_next->bestJunction(modules, junctionPlace, side, this, distance);
            }
        }
    }
    else
    {
        cout << "Node[" << m_module << "]->bestJunction->backward\n";

        --*distance;

        if (it != (*modules)->end())
        {
            cout << "Node[" << m_module << "]->bestJunction->module found, removing module\n";
            if(it->second > 1)
            {
                --(it->second);
            }
            else
            {
                (*modules)->erase(it);
            }

            GraphElement* previous = m_previous;
            GraphElement* next = junctionPlace->getBefore() == this  ?  this  :  m_next;

            cout << "Node[" << m_module << "]->moving node\n";
            moveAfter(*junctionPlace);

            cout << "Node[" << m_module << "]->bestJunction->recursive call\n";
            previous->bestJunction(modules, junctionPlace, side, next, distance);
        }
        else
        {
            cout << "Node[" << m_module << "]->bestJunction->module not found, recursive call\n";
            m_previous->bestJunction(modules, junctionPlace, side, this, distance);

            ++*distance;
        }
        cout << "Node[" << m_module << "]->bestJunction->exit\n";
        return *side == Side::left ? Side::right : Side::left;
    }
}

bool Node::contains(map<const Module*, int>** modules) const
{
    if (m_module != nullptr)
    {
        map<const Module*, int>::iterator it = (*modules)->find(m_module);
        if (it == (*modules)->end())
        {
            return false;
        }
        if (--(it->second) <= 0)
        {
            (*modules)->erase(it);
        }
    }

    return  m_next == nullptr  ?  true  :  m_next->contains(modules);
}


void Node::moveAt(const Link& link)
{
    //On commence par retirer le node de ses deux voisins directs
    if (m_previous != nullptr)
    {
        m_previous->changeNext(this, m_next);
    }
    if (m_next != nullptr)
    {
        m_next->changePrevious(this, m_previous);
    }

    //Puis on l'insere entre les 2 GraphElements n et son predecesseur
    m_previous = link.getBefore();
    m_next = link.getAfter();
    m_previous->changeNext(link.getAfter(), this);
    m_next->changePrevious(link.getBefore(), this);
}

void Node::moveBefore(Link& link)
{
    if (link.getBefore() != this)
    {
        if (link.getAfter() != this)
        {
            moveAt(link);
        }
        else
        {
            link.setAfter(m_next);
        }
        link.setBefore(this);
    }
}

void Node::moveAfter(Link& link)
{
    if (link.getAfter() != this)
    {
        if (link.getBefore() != this)
        {
            moveAt(link);
        }
        else
        {
            link.setBefore(m_previous);
        }
        link.setAfter(this);
    }
}

void Node::display(GraphElement* /*callingGE unused*/, int l)
{
    cout << '-';
    if (m_module == nullptr)
    {
        cout << "####";
    }
    else
    {
        cout << *m_module;
    }
    cout << '-';
    if (m_next != nullptr)
    {
        m_next->display(this, l+6);
    }
}

Node::Node(const Module* module) :
    InGE(nullptr), OutGE(nullptr), m_module(module)
{}


Node::Node(const Module* module, GraphElement* previous, GraphElement* next) :
    InGE(previous), OutGE(next), m_module(module)
{}

Node::~Node()
{}

Node::Node(const Node& other) :
    InGE(other.m_previous), OutGE(other.m_next), m_module(other.m_module)
{}

Node& Node::operator=(const Node& rhs)
{
    if (this == &rhs) return *this;
    m_module = rhs.m_module;
    return *this;
}
