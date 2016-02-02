#include "MoveRequirement.h"

#include "Parser.h"

const std::string MoveRequirement::XML_ELEMENT = "move";
const std::string MoveRequirement::XML_TYPE_ATTRIBUTE = "type";

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

tinyxml2::XMLElement* MoveRequirement::save(tinyxml2::XMLDocument &document) const
{
	tinyxml2::XMLElement *element = document.NewElement(XML_ELEMENT.c_str());
	element->SetAttribute(XML_TYPE_ATTRIBUTE.c_str(), Parser::toText(_type).c_str());
	return element;
}
