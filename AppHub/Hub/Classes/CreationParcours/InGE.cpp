#include "InGE.h"

InGE::InGE(GraphElement* previous) : m_previous(previous)
{}

InGE::InGE(const InGE& other) : m_previous(other.m_previous)
{}

InGE& InGE::operator=(const InGE& rhs)
{
    if (this == &rhs) return *this;
    m_previous = rhs.m_previous;
    return *this;
}



void InGE::changePrevious(GraphElement* oldGE, GraphElement* newGE)
{
    if (oldGE == m_previous)
    {
        m_previous = newGE;
    }
}



