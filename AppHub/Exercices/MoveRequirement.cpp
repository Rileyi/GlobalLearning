#include "MoveRequirement.h"

const std::string MoveRequirement::XML_ELEMENT = "move";

MoveRequirement::MoveRequirement(MoveType category, unsigned int level) : Requirement(level), _type(category)
{
}

MoveRequirement::~MoveRequirement()
{
}

MoveRequirement::MoveRequirement(const MoveRequirement& other) : Requirement(other), _type(other._type)
{
}

MoveRequirement& MoveRequirement::operator=(const MoveRequirement& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    Requirement::operator=(rhs);
    _type = rhs._type;
    return *this;
}

MoveRequirement* MoveRequirement::clone() const
{
	return new MoveRequirement(*this);
}

std::string MoveRequirement::toXML() const
{
}
