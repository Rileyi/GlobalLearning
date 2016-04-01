#include "Fork.h"

using namespace std;

int Fork::bestFork(map<const Module*, int>** modules, Link* forkPlace)
{
    cout <<"Fork->bestFork->start\n";
    if (!forkPlace->isEmpty())
    {
        //point de fourche deja trouve
        cout <<"Fork->bestFork->fork place already found, exit\n";
        return 0;
    }

    //L'appel de bestFork sur les 2 successeurs va nesseciter une copie de la
    //liste de modules et un deuxieme pointer forkPlace
    map<const Module*, int>** modulesBis =
        new map<const Module*, int>*(new map<const Module*, int>(**modules));
    Link* forkPlaceBis = new Link();

    //appels recursifs
    cout <<"Fork->bestFork->right recursive call\n";
    int distanceRight = m_right->bestFork(modulesBis, forkPlaceBis);
    cout <<"Fork->bestFork->left recursive call\n";
    int distanceLeft = m_left->bestFork(modules, forkPlace);
    cout <<"Fork->bestFork->back from recursive calls\n";

    if (distanceLeft >= distanceRight)
    {
        //si le cote gauche ofre le point de fourche le plus lointain
        //il suffit de liberer la memoire alouee pour le cote droit
        cout <<"Fork->bestFork->left>=right, delete and exit\n";
        delete *modulesBis;
        delete modulesBis;
        delete forkPlaceBis;
        return distanceLeft;
    }

    //sinon il faut changer forkPlace et modules avant cote avant de desalouer
    cout <<"Fork->bestFork->left<right, delete and exit\n";
    delete *modules;
    *modules = *modulesBis;
    delete modulesBis;
    *forkPlace = *forkPlaceBis;
    delete forkPlaceBis;
    return distanceRight;
}

Side Fork::bestJunction(map<const Module*, int>** modules, Link* junctionPlace, Side* side,
                GraphElement* callingNode,  int* distance)
{
    cout <<"Fork->bestJunction->start\n";
    if (callingNode == m_previous)
    {
        cout <<"Fork->bestJunction->moving forward\n";
        if (!junctionPlace->isEmpty())
        {
            cout <<"Fork->bestJunction->junctionPlace already found\n";
            map<const Module*, int>** modules2 =
                        new map<const Module*, int>*(new map<const Module*, int>(**modules));

            if (*side != Side::right)
            {
                cout <<"Fork->bestJunction->left contains() call\n";

                if (m_left->contains(modules2))
                {
                    cout <<"Fork->bestJunction->left contains() success, junction place is good, exit\n";
                    delete *modules;
                    *modules = *modules2;
                    delete modules2;
                    return Side::left;
                }
                cout <<"Fork->bestJunction->left contains() fails\n";
            }

            if (*side == Side::both)
            {
                cout <<"Fork->bestJunction->side=both\n";
                delete *modules2;
                *modules2 = new map<const Module*, int>(**modules);
            }

            if (*side != Side::left)
            {
                cout <<"Fork->bestJunction->right contains() call\n";
                if (m_right->contains(modules2))
                {
                    cout <<"Fork->bestJunction->right bestFork success, junction place is good, exit\n";
                    delete *modules;
                    *modules = *modules2;
                    delete modules2;
                    return Side::right;
                }
                cout <<"Fork->bestJunction->right bestFork fails\n";
            }

            cout <<"Fork->bestJunction->this junction place is bad => junction place not found\n";
            delete *modules2;
            delete modules2;
        }

        junctionPlace->makeEmpty();
        Side returnSide;

        if (*side == Side::left)
        {
            cout <<"Fork->bestJunction->side = left => left recursive call\n";
            returnSide = m_left->bestJunction(modules, junctionPlace, side, this, distance);
            cout <<"Fork->bestJunction->back from left recursive call\n";
        }
        else if(*side == Side::right)
        {
            cout <<"Fork->bestJunction->side = right => right recursive call\n";
            returnSide = m_right->bestJunction(modules, junctionPlace, side, this, distance);
            cout <<"Fork->bestJunction->back from right recursive call\n";
        }

        else
        {
            cout <<"Fork->bestJunction->side = both\n";
            map<const Module*, int>** modules2 =
                    new map<const Module*, int>*(new map<const Module*, int>(**modules));
            Link* junctionPlace2 = new Link();
            int* distance2 = new int(*distance);
            Side leftSide = Side::left;
            Side rightSide = Side::right;

            cout <<"Fork->bestJunction->left recursive call\n";
            Side rl = m_left->bestJunction(modules, junctionPlace, &leftSide, this, distance);
            cout <<"Fork->bestJunction->right recursive call\n";
            Side rr = m_right->bestJunction(modules2, junctionPlace2, &rightSide, this, distance2);
            cout <<"Fork->bestJunction->back from recursive calls\n";

            if (*distance <= *distance2)
            {
                cout <<"Fork->bestJunction->choosing left\n";
                delete *modules2;
                *side = leftSide;
                returnSide = rl;

            }
            else
            {
                cout <<"Fork->bestJunction->choosing right\n";
                delete *modules;
                *modules = *modules2;
                *junctionPlace = *junctionPlace2;
                *distance = *distance2;
                *side = rightSide;
                returnSide = rr;
            }

            delete modules2;
            delete junctionPlace2;
            delete distance2;
        }

        if (junctionPlace->getBefore() == this)
        {
            junctionPlace->setBefore(m_previous);
            junctionPlace->setAfter(this);
        }
        cout <<"Fork->bestJunction->exit\n";
        return returnSide;
    }
    else
    {
        cout <<"Fork->bestJunction->moving backward\n";
        if (callingNode == junctionPlace->getAfter())
        {
            cout <<"Fork->bestJunction->recursive call\n";
            junctionPlace->makeEmpty();
            m_previous->bestJunction(modules, junctionPlace, side, this, distance);
        }
        cout <<"Fork->bestJunction->exit\n";
        return callingNode == m_left ? Side::right : Side::left;
    }
}

bool Fork::contains(map<const Module*, int>** modules) const
{
    map<const Module*, int>** modules2 =
        new map<const Module*, int>*(new map<const Module*, int>(**modules));
    if (m_left->contains(modules2))
    {
        delete *modules;
        *modules = *modules2;
        delete modules2;
        return true;
    }
    delete *modules2;
    delete modules2;
    return m_right->contains(modules);
}


void Fork::recursiveDelete()
{
    if (m_left != nullptr)
    {
        GraphElement* e = m_left;
        e->recursiveDelete();
        delete e;
    }

    if (m_right != nullptr)
    {
        GraphElement* e = m_right;
        e->recursiveDelete();
        delete e;
    }
}

void Fork::changeNext(GraphElement* oldGE, GraphElement* newGE)
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

void Fork::display(GraphElement* /*callingGE unused*/, int l)
{
    cout << '<';
    m_left->display(this, l+1);
    cout <<'\n';
    for (int i=0; i<l; ++i)
    {
        cout <<' ';
    }
    cout << '<';
    m_right->display(this, l+1);
}

vector<const ModuleGE*>* Fork::getNextModuleGEs() const
{
    vector<const ModuleGE*>* l = new vector<const ModuleGE*>();

    if (m_left != nullptr)
    {
        const ModuleGE* mge = m_left->getModuleGE();
        if (nullptr != mge) l->push_back(mge);
        else
        {
            cout << " FLREC";
            vector<const ModuleGE*>* ll = m_left->getNextModuleGEs();
            l->insert(l->end(), ll->begin(), ll->end());
            delete ll;
        }
    }

    if (m_right != nullptr)
    {
        const ModuleGE* mge = m_right->getModuleGE();
        if (nullptr != mge) l->push_back(mge);
        else
        {
            cout << " FRREC";
            vector<const ModuleGE*>* lr = m_right->getNextModuleGEs();
            l->insert(l->end(), lr->begin(), lr->end());
            delete lr;
        }
    }

    cout << " FRET";
    return l;
}

void Fork::distanceAndValidity(std::map<const GraphElement*, twoInts*>* distancesMap,
        const GraphElement* callingGE, int distance, int* w,
        std::string* errors) const
{
    cout << "Fork->distance and validity check\n";

    if (m_previous == nullptr)
    {
        *errors += "No previous GE at a fork.\n";
        cout << "Fork->Error: " << *errors;
    }
    if (m_right == nullptr)
    {
        *errors += "No right GE at a fork.\n";
        cout << "Fork->Error: " << *errors;
    }
    if (m_left == nullptr)
    {
        *errors += "No left GE at a fork.\n";
        cout << "Fork->Error: " << *errors;
    }

    if (distancesMap->find(this) == distancesMap->end())
    {
        cout << "Fork->fork not found in the map\n";

        (*distancesMap)[this] = new twoInts(distance, *w);
        cout << "Fork->fork added to the map\n";

        if (callingGE == m_previous)
        {
            (*distancesMap)[this] = new twoInts(distance, *w);
            cout << "Fork->fork added to the map (d=" << distance  << ")\n";

            if (m_left != nullptr)
            {
                cout << "Fork->recursive call on left GE\n";
                m_left->distanceAndValidity(distancesMap, this, distance, w, errors);
                cout << "Fork->back from recursive call\n";
            }

            return;
        }

        else if (callingGE == m_right)
        {
            *errors += "Unexpected new left fork while moving backward (crossing?).\n";
            cout << "Fork->Error: " << *errors;
        }

        else if (callingGE != m_left)
        {
            *errors += "Broken link at a fork.\n";
            cout << "Fork->Error: " << *errors;
        }

        if (m_previous != nullptr)
        {
            cout << "Fork->recursive call on previous GE\n";
            m_previous->distanceAndValidity(distancesMap, this, distance, w, errors);
            cout << "Fork->back from recursive call\n";
        }

        /*if (m_left != callingGE  &&  m_left != nullptr)
        {
            cout << "Fork->recursive call on left GE\n";
            m_left->distanceAndValidity(distancesMap, this, distance, w, errors);
            cout << "Fork->back from recursive call\n";
        }

        if (m_right != callingGE  &&  m_right != nullptr)
        {
            cout << "Fork->recursive call on right GE\n";
            m_right->distanceAndValidity(distancesMap, this, distance, w, errors);
            cout << "Fork->back from recursive call\n";
        }*/
    }

    else
    {
        if ((*distancesMap)[this]->fst != distance)
        {
            *errors += "Unequal distances between paths.\n";
            cout << "Fork->Error: " << *errors;
            cout << "(" << distance  << "/" << (*distancesMap)[this]->fst << ")\n";
        }

        if (callingGE == m_previous)
        {
            *errors += "Already encountered fork while moving forward (cycle?).\n";
            cout << "Fork->Error: " << *errors;
        }

        else if (callingGE == m_left)
        {
            *errors += "Already encountered right fork while moving backward (WTF?).\n";
            cout << "Fork->Error: " << *errors;
        }

        else if (callingGE != m_right)
        {
            *errors += "Broken link at a fork.\n";
            cout << "Fork->Error: " << *errors;
        }

        else if ((*distancesMap)[this]->fst < 0)
        {
            *errors += "Fork encountered 3 times (cycle?).\n";
            cout << "Fork->Error: " << *errors;
        }

        else
        {
            (*distancesMap)[this]->fst *= -1;
            cout << "Fork->fork already encountered once\n";
        }
    }
}

Fork::Fork() : Intersection(), InGE(nullptr) {}

Fork::Fork(GraphElement* left, GraphElement* right, GraphElement* previous) :
    Intersection(left, right), InGE(previous)
{}

Fork::Fork(Link& l, const Side& s) : Intersection(l), InGE(l.getBefore())
{
    (s == Side::left ? m_right : m_left) = l.getAfter();
    l.setAfter(this);
}

Fork::Fork(const Fork& other) :
    Intersection(other.m_left, other.m_right), InGE(other.m_previous)
{}

Fork& Fork::operator=(const Fork& rhs)
{
    if (this == &rhs) return *this;
    InGE::operator=(rhs);
    Intersection::operator=(rhs);
    return *this;
}
