#include "MoveRequirement.h"

const std::string MoveRequirement::XML_ELEMENT = "move";

MoveRequirement::MoveRequirement(MoveClass category, unsigned int level) : Requirement(level), _class(category)
{
}

MoveRequirement::~MoveRequirement()
{
}

MoveRequirement::MoveRequirement(const MoveRequirement& other) : Requirement(other), _class(other._class)
{
}

MoveRequirement& MoveRequirement::operator=(const MoveRequirement& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    Requirement::operator=(rhs);
    _class = rhs._class;
    return *this;
}
