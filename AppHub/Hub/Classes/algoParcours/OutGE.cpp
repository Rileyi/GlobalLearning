#include "OutGE.h"

OutGE::OutGE(GraphElement* next) : m_next(next)
{}

OutGE::OutGE(const OutGE& other) : m_next(other.m_next)
{}

OutGE& OutGE::operator=(const OutGE& rhs)
{
    if (this == &rhs) return *this;
    m_next = rhs.m_next;
    return *this;
}


void OutGE::changeNext(GraphElement* oldGE, GraphElement* newGE)
{
    if (oldGE == m_next)
    {
        m_next = newGE;
    }
}

std::vector<const ModuleGE*>* OutGE::getNextModuleGEs() const
{
    if (m_next == nullptr) return new std::vector<const ModuleGE*>();
    const ModuleGE* mge = m_next->getModuleGE();
    if (mge != nullptr)
    {
        return new std::vector<const ModuleGE*>(1, mge);
    }
    return m_next->getNextModuleGEs();
}

void OutGE::recursiveDelete()
{
    if (m_next != nullptr)
    {
        GraphElement* e = m_next;
        e->recursiveDelete();
        delete e;
    }
}
