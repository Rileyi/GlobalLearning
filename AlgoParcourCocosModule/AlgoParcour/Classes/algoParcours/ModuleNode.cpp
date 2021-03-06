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

void ModuleNode::recursiveDelete()
{
    for(ModuleNode* next : *m_next)
    {
        next->recursiveDelete();
    }

    delete m_next;
}
