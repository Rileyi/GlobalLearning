#include "SubjectRequirement.h"
#include "IO/Parser.h"

const std::string SubjectRequirement::XML_ELEMENT = "level";
const std::string SubjectRequirement::XML_TYPE_ATTRIBUTE = "type";

SubjectRequirement::SubjectRequirement(SubjectType category, unsigned int level) : Requirement(level), _type(category)
{
}

SubjectRequirement::~SubjectRequirement()
{
    //dtor
}

SubjectRequirement::SubjectRequirement(const SubjectRequirement& other) : Requirement(other), _type(other._type)
{
}

SubjectRequirement& SubjectRequirement::operator=(const SubjectRequirement& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    Requirement::operator=(rhs);
    _type = rhs._type;
    return *this;
}

SubjectRequirement* SubjectRequirement::clone() const
{
	return new SubjectRequirement(*this);
}

void SubjectRequirement::appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *parent) const
{
	tinyxml2::XMLElement *element = document.NewElement(XML_ELEMENT.c_str());
	element->SetAttribute(XML_TYPE_ATTRIBUTE.c_str(), Parser::toText(_type).c_str());
	element->SetAttribute(XML_VALUE_ATTRIBUTE.c_str(), _level);
	if (parent == nullptr)
		document.InsertEndChild(element);
	else
		parent->InsertEndChild(element);
}
