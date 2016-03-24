#include "ModuleNode.h"

using namespace std;

ModuleNode::ModuleNode(const ModuleGE* m) : m_module(m->getModule()),
    m_previous(new vector<ModuleNode*>()), m_next(new vector<ModuleNode*>())
{}

ModuleNode::~ModuleNode()
{}

ModuleNode::ModuleNode(const ModuleNode& other) : m_module(other.getModule()),
    m_previous(other.getPrevious()), m_next(other.getNext())
{}

ModuleNode& ModuleNode::operator=(const ModuleNode& other)
{
    if (this != &other)
    {
        m_module = other.getModule();
        m_previous = other.getPrevious();
        m_next = other.getNext();
    }
    return *this;
}

void ModuleNode::display() const
{
    if (m_module != nullptr) cout << *m_module;
    else cout << "####";
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
