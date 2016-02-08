#include "MoveLearning.h"

#include "IO/Parser.h"

const std::string MoveLearning::XML_ELEMENT = "move";
const std::string MoveLearning::XML_TYPE_ATTRIBUTE = "type";

MoveLearning::MoveLearning(MoveType category, unsigned int level) : Learning(level), _type(category)
{
}

MoveLearning::~MoveLearning()
{
}

MoveLearning::MoveLearning(const MoveLearning& other) : Learning(other), _type(other._type)
{
}

MoveLearning& MoveLearning::operator=(const MoveLearning& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    Learning::operator=(rhs);
    _type = rhs._type;
    return *this;
}

MoveLearning* MoveLearning::clone() const
{
	return new MoveLearning(*this);
}

void MoveLearning::appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *parent) const
{
	tinyxml2::XMLElement *element = document.NewElement(XML_ELEMENT.c_str());
	element->SetAttribute(XML_TYPE_ATTRIBUTE.c_str(), Parser::toText(_type).c_str());
	element->SetAttribute(XML_EXPERIENCE_ATTRIBUTE.c_str(), _experience);
	if (parent == nullptr)
		document.InsertEndChild(element);
	else
		parent->InsertEndChild(element);
}
