#include "Learning.h"

const std::string Learning::XML_EXPERIENCE_ATTRIBUTE = "value";

Learning::Learning(unsigned int experience) : _experience(experience)
{
}

Learning::~Learning()
{
}

Learning::Learning(const Learning& other) : _experience(other._experience)
{
}

Learning& Learning::operator=(const Learning& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    _experience = rhs._experience;
    return *this;
}
