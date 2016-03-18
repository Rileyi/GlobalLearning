#include "SubjectLearning.h"
#include "IO/Parser.h"

const std::string SubjectLearning::XML_ELEMENT = "subject";
const std::string SubjectLearning::XML_TYPE_ATTRIBUTE = "type";

SubjectLearning::SubjectLearning(SubjectType category, unsigned int level) : Learning(level), _type(category)
{
}

SubjectLearning::~SubjectLearning()
{
    //dtor
}

SubjectLearning::SubjectLearning(const SubjectLearning& other) : Learning(other), _type(other._type)
{
}

SubjectLearning& SubjectLearning::operator=(const SubjectLearning& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    Learning::operator=(rhs);
    _type = rhs._type;
    return *this;
}

SubjectLearning* SubjectLearning::clone() const
{
	return new SubjectLearning(*this);
}

void SubjectLearning::appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *parent) const
{
	tinyxml2::XMLElement *element = document.NewElement(XML_ELEMENT.c_str());
	element->SetAttribute(XML_TYPE_ATTRIBUTE.c_str(), Parser::toText(_type).c_str());
	element->SetAttribute(XML_EXPERIENCE_ATTRIBUTE.c_str(), _experience);
	if (parent == nullptr)
		document.InsertEndChild(element);
	else
		parent->InsertEndChild(element);
}
