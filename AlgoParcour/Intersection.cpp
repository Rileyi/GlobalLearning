#include "Intersection.h"

Intersection::Intersection() : m_left(nullptr), m_right(nullptr)
{}

Intersection::Intersection(GraphElement* left, GraphElement* right) :
    m_left(left), m_right(right)
{}

Intersection::Intersection(Link& l) : m_left(nullptr), m_right(nullptr)
{
    l.getAfter()->changePrevious(l.getBefore(), this);
    l.getBefore()->changeNext(l.getAfter(), this);
}

Intersection::Intersection(const Intersection& other) :
    m_left(other.m_left), m_right(other.m_right)
{}

Intersection& Intersection::operator=(const Intersection& rhs)
{
    if (this == &rhs) return *this;
    m_left = rhs.m_left;
    m_right = rhs.m_right;
    return *this;
}
