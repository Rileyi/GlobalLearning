#include "Requirement.h"

const std::string Requirement::XML_VALUE_ATTRIBUTE = "value";

Requirement::Requirement(unsigned int level) : _level(level)
{
}

Requirement::~Requirement()
{
}

Requirement::Requirement(const Requirement& other) : _level(other._level)
{
}

Requirement& Requirement::operator=(const Requirement& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    _level = rhs._level;
    return *this;
}
