#include "Link.h"


Link::Link() : m_before(nullptr), m_after(nullptr) {}

Link::Link(GraphElement* before, GraphElement* after) :
    m_before(before), m_after(after)
{}

Link::~Link() {}

Link::Link(const Link& other) :
    m_before(other.m_before), m_after(other.m_after)
{}

Link& Link::operator=(const Link& rhs)
{
    if (this == &rhs) return *this;
    m_before = rhs.m_before;
    m_after = rhs.m_after;
    return *this;
}

bool Link::isEmpty()
{
    return m_after == nullptr  &&  m_before == nullptr;
}

void Link::makeEmpty()
{
    m_after = m_before = nullptr;
}

bool operator==(const Link& l, const Link& r)
{
    return l.getBefore() == r.getBefore()  &&  l.getAfter() == r.getAfter();
}
