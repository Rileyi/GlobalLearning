#include "LevelRequirement.h"
#include "Parser.h"

const std::string LevelRequirement::XML_ELEMENT = "level";
const std::string LevelRequirement::XML_CLASS_ATTRIBUTE = "class";

LevelRequirement::LevelRequirement(ExerciceClass category, unsigned int level) : Requirement(level), _class(category)
{
}

LevelRequirement::~LevelRequirement()
{
    //dtor
}

LevelRequirement::LevelRequirement(const LevelRequirement& other) : Requirement(other), _class(other._class)
{
}

LevelRequirement& LevelRequirement::operator=(const LevelRequirement& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    Requirement::operator=(rhs);
    _class = rhs._class;
    return *this;
}

LevelRequirement* LevelRequirement::clone() const
{
	return new LevelRequirement(*this);
}

void LevelRequirement::appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *parent) const
{
	tinyxml2::XMLElement *element = document.NewElement(XML_ELEMENT.c_str());
	element->SetAttribute(XML_CLASS_ATTRIBUTE.c_str(), Parser::toText(_class).c_str());
	element->SetAttribute(XML_VALUE_ATTRIBUTE.c_str(), _level);
	if (parent == nullptr)
		document.InsertEndChild(element);
	else
		parent->InsertEndChild(element);
}
