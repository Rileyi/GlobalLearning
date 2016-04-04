#include "ModuleNode.h"

using namespace std;

ModuleNode::ModuleNode(const ModuleGE* m) : Module(*(m->getModule())),
    m_previous(new vector<ModuleNode*>()), m_next(new vector<ModuleNode*>())
{
    if (m->getPrevious() == nullptr)
    {
        setModuleName("depart");
    }
    else if (m->getNext() == nullptr)
    {
        setModuleName("arrivee");
    }
}

ModuleNode::~ModuleNode()
{}

ModuleNode::ModuleNode(const ModuleNode& other) : Module(other),
    m_previous(other.getPrevious()), m_next(other.getNext())
{}

ModuleNode& ModuleNode::operator=(const ModuleNode& other)
{
    if (this != &other)
    {
        Module::operator=(other);
        m_previous = other.getPrevious();
        m_next = other.getNext();
    }
    return *this;
}

void ModuleNode::display() const
{
    cout << *this;
}


void ModuleNode::addNext(ModuleNode* moduleNode)
{
    m_next->push_back(moduleNode);
}

void ModuleNode::addNext(std::vector<ModuleNode*>& moduleNodes)
{
    for(ModuleNode* moduleNode : moduleNodes)
    {
        addNext(moduleNode);
    }
}

void ModuleNode::addPrevious(ModuleNode* moduleNode)
{
    m_previous->push_back(moduleNode);
}

void ModuleNode::addPrevious(std::vector<ModuleNode*>& moduleNodes)
{
    for(ModuleNode* moduleNode : moduleNodes)
    {
        addPrevious(moduleNode);
    }
}

bool ModuleNode::calculatePathData(const Module& asked, const Module& authorizedDifference,
                                   Module* totalMin, Module* totalMax, unsigned int* numberOfPaths,
                                   unsigned int* maxDifference, float* averageDifference) const
{
    if (m_next->empty())
    {
        ++*numberOfPaths;
        *averageDifference = *maxDifference = max(asked, -asked).totalValue();
        *totalMax = *totalMin = 0;
        return (min(asked,authorizedDifference)==asked  &&  max(asked,-authorizedDifference)==asked);
    }
    else
    {
        bool b=true;
        for (ModuleNode* mn : *m_next)
        {
            unsigned int numberOfPaths2 = 0;
            Module totalMin2(INT_MAX);
            Module totalMax2(INT_MIN);
            unsigned int maxDifference2 = 0;
            float averageDifference2 = 0;

            b &= mn->calculatePathData(asked-*this, authorizedDifference, &totalMin2, &totalMax2,
                                         &numberOfPaths2, &maxDifference2, &averageDifference2);

            *totalMin = min(*totalMin, totalMin2);
            *totalMax = max(*totalMax, totalMax2);
            *maxDifference = std::max(*maxDifference, maxDifference2);
            *averageDifference = (*numberOfPaths * *averageDifference + numberOfPaths2 * averageDifference2)
                                / (*numberOfPaths + numberOfPaths2);
            *numberOfPaths += numberOfPaths2;
        }
        *totalMin += *this;
        *totalMax += *this;
        return b;
    }
}

void ModuleNode::recursiveDelete()
{
    for(ModuleNode* next : *m_next)
    {
        next->recursiveDelete();
    }

    delete m_next;
}
