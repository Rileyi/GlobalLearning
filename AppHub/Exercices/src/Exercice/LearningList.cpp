#include "LearningList.h"

#include <iostream>
#include "IO/Parser.h"
#include "Exception.h"

const std::string LearningList::XML_ELEMENT = "learnings";

LearningList::LearningList() : _data()
{
}

LearningList::~LearningList()
{
}

LearningList::LearningList(const LearningList& other) : _data()
{
	// Loop over the vector and "deep copy" each data
    for (auto it = other._data.begin(); it != other._data.end(); it++)
    {
		/* this use the copy constructor of the data in the smart pointer
		   it then creates a smart pointer for the copied data
		   and stores the pointer in the array */
        _data.push_back(LearningPtr(it->get()->clone()));
    }
}

LearningList& LearningList::operator=(const LearningList& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
	_data.clear();
	// see copy constructor for explanations
	for (auto it = rhs._data.begin(); it != rhs._data.end(); it++)
	{
        _data.push_back(LearningPtr(it->get()->clone()));
	}
    return *this;
}

void LearningList::loadFromXML(const tinyxml2::XMLElement *element)
{
    if (element == nullptr)
		throw Exception(Exception::Type::Parser, "LearningList::loadFromXML: nullptr given for element");

    if (element->Name() != XML_ELEMENT)
		throw Exception(Exception::Type::Parser, "LearningList::loadFromXML: " + std::string(element->Name()) + " is not valid as element name");

    // Loop over all the children elements
    for (const tinyxml2::XMLElement* child = element->FirstChildElement(); child != nullptr; child = child->NextSiblingElement())
    {
        // Load requirement
		if (child->Name() == SubjectLearning::XML_ELEMENT)
			loadLevelLearningFromXML(child);
		else if (child->Name() == MoveLearning::XML_ELEMENT)
			loadMoveLearningFromXML(child);
		else
		{
			throw Exception(Exception::Type::Parser, "LearningList::loadFromXML: " + std::string(child->Name()) + " is not valid as element name");
		}
    }
}

void LearningList::loadLevelLearningFromXML(const tinyxml2::XMLElement *child)
{
	const tinyxml2::XMLAttribute *classAttribute = child->FindAttribute("class");
	const tinyxml2::XMLAttribute *experienceAttribute = child->FindAttribute("experience");
	if (classAttribute == nullptr)
	{
		throw Exception(Exception::Type::Parser, "LearningList::loadLevelLearningFromXML: unable to find class attribute");
	}
	else if (experienceAttribute == nullptr)
	{
		throw Exception(Exception::Type::Parser, "LearningList::loadLevelLearningFromXML: unable to find experience attribute");
	}
	else
	{
		SubjectType exerciceClass = Parser::subjectType(classAttribute->Value());
		if (exerciceClass == SubjectType::Undefined)
		{
			throw Exception(Exception::Type::Parser, "LearningList::loadLevelLearningFromXML: exercice class requirement undefined: " + std::string(classAttribute->Value()));
		}
		unsigned int value;
		if (experienceAttribute->QueryUnsignedValue(&value) != tinyxml2::XML_NO_ERROR)
		{
			throw Exception(Exception::Type::Parser, "LearningList::loadLevelLearningFromXML: unable to read experience attribute");
		}
		_data.push_back(LearningPtr(new SubjectLearning(exerciceClass, value)));
	}
}

void LearningList::loadMoveLearningFromXML(const tinyxml2::XMLElement *child)
{
	const tinyxml2::XMLAttribute *typeAttribute = child->FindAttribute("type");
	const tinyxml2::XMLAttribute *experienceAttribute = child->FindAttribute("experience");
	if (typeAttribute == nullptr)
	{
		throw Exception(Exception::Type::Parser, "LearningList::loadMoveLearningFromXML: unable to find class attribute");
	}
	else if (experienceAttribute == nullptr)
	{
		throw Exception(Exception::Type::Parser, "LearningList::loadMoveLearningFromXML: unable to find experience attribute");
	}
	else
	{
		MoveType moveType = Parser::moveType(typeAttribute->Value());
		if (moveType == MoveType::Undefined)
		{
			throw Exception(Exception::Type::Parser, "LearningList::loadMoveLearningFromXML: move type requirement undefined");
		}
		unsigned int value;
		if (experienceAttribute->QueryUnsignedValue(&value) != tinyxml2::XML_NO_ERROR)
		{
			throw Exception(Exception::Type::Parser, "LearningList::loadMoveLearningFromXML: unable to read experience attribute");
		}
		_data.push_back(LearningPtr(new MoveLearning(moveType, value)));
	}
}

void LearningList::appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *parent) const
{
	tinyxml2::XMLElement *element = document.NewElement(XML_ELEMENT.c_str());
	// Add each requirement as a child
	for (auto it = _data.begin(); it != _data.end(); it++)
	{
		it->get()->appendToXML(document, element);
	}
	// Add node to the document
	if (parent == nullptr)
		document.InsertEndChild(element);
	else
		parent->InsertEndChild(element);
}

void LearningList::add(SubjectType category, unsigned int level)
{
    _data.push_back(LearningPtr(new SubjectLearning(category, level)));
}

void LearningList::add(MoveType category, unsigned int level)
{
    _data.push_back(LearningPtr(new MoveLearning(category, level)));
}
