#include "Junction.h"

using namespace std;

int Junction::bestFork(map<const Module*, int>** modules, Link* forkPlace)
{
    //si le point de fourche est deja trouve on s'arrete sinon on continue la recursion
    cout <<"Junction->bestFork\n";
    return forkPlace->isEmpty()  ?  m_next->bestFork(modules, forkPlace)  :  0;
}

Side Junction::bestJunction(map<const Module*, int>** modules, Link* junctionPlace, Side* side,
                  GraphElement* callingNode, int* distance)
{

    cout <<"Junction->bestJunction\n";
    if (callingNode == m_next)
    {
        cout <<"Junction->bestJunction->moving backward\n";

        if (*distance <= 0  ||  this != junctionPlace->getBefore())
        {
            cout << "distance negative or junction place far away, exit\n";
            return *side == Side::left  ?  Side::right  :  Side::left;
        }

        cout <<"Junction->bestJunction->junctionPlace = this => junctionPlace=nullptr\n";

        junctionPlace->setAfter(this);

        if (*side == Side::left)
        {
            junctionPlace->setBefore(m_left);
            cout <<"Junction->bestJunction->recursive call (left)\n";
            m_left->bestJunction(modules, junctionPlace, side, this, distance);
            cout <<"Junction->bestJunction->back from recursive call (left), exit\n";
            return Side::right;
        }
        else
        {
            junctionPlace->setBefore(m_right);
            cout <<"Junction->bestJunction->recursive call (right)\n";
            m_right->bestJunction(modules, junctionPlace, side, this, distance);
            cout <<"Junction->bestJunction->back from recursive call (right), exit\n";
            return Side::left;
        }
    }
    else
    {
        cout <<"Junction->bestJunction->moving forward\n";
        map<const Module*, int>** modules2 =
                new map<const Module*, int>*(new map<const Module*, int>(**modules));

        cout <<"Junction->bestJunction->contains() call\n";
        if (m_next->contains(modules2))
        {
            cout <<"Junction->bestJunction->contains() returned true (good result)\n";

            delete *modules;
            *modules = *modules2;
            if (junctionPlace->isEmpty())
            {
                cout <<"Junction->bestJunction->new junction place\n";
                junctionPlace->setBefore(callingNode);
                junctionPlace->setAfter(this);
            }

            if (!((*side == Side::left  &&  callingNode == m_left)  ||
                  (*side == Side::right  &&  callingNode == m_right)))
            {
                cout <<"Junction->bestJunction->side != calling side => back recursive call\n";

                *modules2 = new map<const Module*, int>(**modules);
                Link* junctionPlace2 = new Link((callingNode == m_left  ?  m_right  :  m_left), this);
                Side* side2 = new Side(callingNode == m_left  ?  Side::left  :  Side::right);
                int* distance2 = new int(*distance);

                if (callingNode == m_left)
                {
                    cout <<"Junction->bestJunction->right recursive call\n";
                    m_right-> bestJunction(modules2, junctionPlace2, side2, this, distance2);
                }
                else
                {
                    cout <<"Junction->bestJunction->left recursive call\n";
                    m_left-> bestJunction(modules2, junctionPlace2, side2, this, distance2);
                }
                cout <<"Junction->bestJunction->back from back recursive call\n";

                if (*distance <= *distance2)
                {
                    cout <<"Junction->bestJunction->old junction chosen\n";
                    delete *modules2;
                    delete junctionPlace2;
                    delete side2;
                    delete distance2;
                }
                else
                {
                    cout <<"Junction->bestJunction->new junction chosen\n";
                    delete modules;
                    *modules = *modules2;
                    *junctionPlace = *junctionPlace2;
                    *side = *side2;
                    *distance = *distance2;
                    delete modules2;
                    delete junctionPlace2;
                    delete side2;
                    delete distance2;
                    return callingNode == m_left  ?  Side::right  :  Side::left;
                }
            }
        }
        else
        {
            cout <<"Junction->bestJunction->contains() returned false=> junction place is bad\n";
            delete *modules2;
            junctionPlace->makeEmpty();

            if ((callingNode == m_left  &&  *side != Side::right)  ||
                  (callingNode == m_right  &&  *side != Side::left))
            {
                cout <<"Junction->bestJunction->compatible side => forward recursive call\n";
                *side  =  callingNode == m_left  ?  Side::left  :  Side::right;
                m_next->bestJunction(modules, junctionPlace, side, this, distance);
                cout <<"Junction->bestJunction->back from recursive call, exit\n";
                return callingNode == m_left ? Side::left : Side::right;
            }
            cout <<"Junction->bestJunction->not compatible side\n";
            *distance = 999;
        }
        cout <<"Junction->bestJunction->exit\n";
        delete modules2;
        return *side;
    }
}

bool Junction::contains(map<const Module*, int>** modules) const
{
    return m_next->contains(modules);
}


void Junction::recursiveDelete()
{
    OutGE::recursiveDelete();

    m_left->changeNext(this, nullptr);
    m_right->changeNext(this, nullptr);
}

void Junction::changePrevious(GraphElement* oldGE, GraphElement* newGE)
{
    if (oldGE == m_left)
    {
        m_left = newGE;
    }
    else if (oldGE == m_right)
    {
        m_right = newGE;
    }
}

void Junction::display(GraphElement* callingGE, int l)
{
    cout << '>';
    if (callingGE == m_left)
    {
        m_next->display(this, l+1);
    }
}


void Junction::distanceAndValidity(std::map<const GraphElement*, twoInts*>* distancesMap,
        const GraphElement* callingGE, int distance, int w,
        std::string* errors) const
{
    cout << "Junction->distance and validity check\n";

    if (distancesMap->find(this) != distancesMap->end())
    {
        *errors += "Same junction reached twice (cycle?).\n";
        cout << "Junction->Error: " << *errors;
    }

    if (m_next == nullptr)
    {
        *errors += "No next GE at a junction.\n";
        cout << "Junction->Error: " << *errors;
    }
    if (m_right == nullptr)
    {
        *errors += "No right GE at a junction.\n";
        cout << "Junction->Error: " << *errors;
    }
    if (m_left == nullptr)
    {
        *errors += "No left GE at a junction.\n";
        cout << "Junction->Error: " << *errors;
    }

    (*distancesMap)[this] = new twoInts(distance, w);
    cout << "Junction->added to the map (d=" << distance  << ")\n";

    if (callingGE == m_left)
    {
        if (m_right != nullptr)
        {
            cout << "Junction->right recursive call\n";
            m_right->distanceAndValidity(distancesMap, this, distance, w, errors);
            cout << "Junction->back from recursive call\n";
            ++w;
        }
        if (m_next != nullptr)
        {
            cout << "Junction->next recursive call\n";
            m_next->distanceAndValidity(distancesMap, this, distance, w, errors);
            cout << "Junction->back from recursive call\n";
        }
    }

    else if (callingGE == m_right)
    {
        *errors += "Reaching a junction by the right (crossing?).\n";
        cout << "Junction->Error: " << *errors;

        if (m_left != nullptr)
        {
            cout << "Junction->left recursive call\n";
            m_left->distanceAndValidity(distancesMap, this, distance, w, errors);
            cout << "Junction->back from recursive call\n";
            ++w;
        }
        if (m_next != nullptr)
        {
            cout << "Junction->next recursive call\n";
            m_next->distanceAndValidity(distancesMap, this, distance, w, errors);
            cout << "Junction->back from recursive call\n";
        }
    }

    else if (callingGE == m_next)
    {
        if (m_left != nullptr)
        {
            cout << "Junction->left recursive call\n";
            m_left->distanceAndValidity(distancesMap, this, distance, w, errors);
            cout << "Junction->back from recursive call\n";
            ++w;
        }
        if (m_next != nullptr)
        {
            cout << "Junction->right recursive call\n";
            m_right->distanceAndValidity(distancesMap, this, distance, w, errors);
            cout << "Junction->back from recursive call\n";
        }
    }

    else
    {
        *errors += "Broken link at a junction.\n";
        cout << "Junction->Error: " << *errors;
    }
}


Junction::Junction() : Intersection(), OutGE(nullptr) {}

Junction::Junction(GraphElement* left, GraphElement* right, GraphElement* next) :
    Intersection(left, right), OutGE(next)
{}

Junction::Junction(Link& l, const Side& s) : Intersection(l), OutGE(l.getAfter())
{
    (s == Side::left  ?  m_right  :  m_left) = l.getBefore();
    l.setBefore(this);
}

Junction::~Junction()
{}

Junction::Junction(const Junction& other) :
    Intersection(other.m_left, other.m_right), OutGE(other.m_next)
{}

Junction& Junction::operator=(const Junction& rhs)
{
    if (this == &rhs) return *this;
    Intersection::operator=(rhs);
    OutGE::operator=(rhs);
    return *this;
}
