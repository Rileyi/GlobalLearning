#include "RequirementList.h"

#include <iostream>
#include "IO/Parser.h"
#include "Exception.h"

const std::string RequirementList::XML_ELEMENT = "requirements";

RequirementList::RequirementList() : _data()
{
}

RequirementList::~RequirementList()
{
}

RequirementList::RequirementList(const RequirementList& other) : _data()
{
	// Loop over the vector and "deep copy" each data
    for (auto it = other._data.begin(); it != other._data.end(); it++)
    {
		/* this use the copy constructor of the data in the smart pointer
		   it then creates a smart pointer for the copied data
		   and stores the pointer in the array */
        _data.push_back(RequirementPtr(it->get()->clone()));
    }
}

RequirementList& RequirementList::operator=(const RequirementList& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
	_data.clear();
	// see copy constructor for explanations
	for (auto it = rhs._data.begin(); it != rhs._data.end(); it++)
	{
        _data.push_back(RequirementPtr(it->get()->clone()));
	}
    return *this;
}

void RequirementList::loadFromXML(const tinyxml2::XMLElement *element)
{
    if (element == nullptr)
		throw Exception(Exception::Type::Parser, "RequirementList::loadFromXML: given element is nullptr");

    if (element->Name() != XML_ELEMENT)
		throw Exception(Exception::Type::Parser, "RequirementList::loadFromXML: " + std::string(element->Name()) + " is not a valid element name");
    // Loop over all the children elements
    for (const tinyxml2::XMLElement* child = element->FirstChildElement(); child != nullptr; child = child->NextSiblingElement())
    {
        // Load requirement
        if (child->Name() == SubjectRequirement::XML_ELEMENT)
			loadLevelRequirementFromXML(child);
        else if (child->Name() == MoveRequirement::XML_ELEMENT)
			loadMoveRequirementFromXML(child);
        else
        {
			throw Exception(Exception::Type::Parser, "RequirementList::loadFromXML: " + std::string(child->Name()) + " is not a valid element name");
        }
    }
}

void RequirementList::loadLevelRequirementFromXML(const tinyxml2::XMLElement *child)
{
	const tinyxml2::XMLAttribute *classAttribute = child->FindAttribute("class");
	const tinyxml2::XMLAttribute *valueAttribute = child->FindAttribute("value");
	if (classAttribute == nullptr)
	{
		throw Exception(Exception::Type::Parser, "RequirementList::loadLevelRequirementFromXML: unable to find class attribute");
	}
	else if (valueAttribute == nullptr)
	{
		throw Exception(Exception::Type::Parser, "RequirementList::loadLevelRequirementFromXML: unable to find value attribute");
	}
	else
	{
		SubjectType exerciceClass = Parser::subjectType(classAttribute->Value());
		if (exerciceClass == SubjectType::Undefined)
		{
			throw Exception(Exception::Type::Parser, "RequirementList::loadLevelRequirementFromXML: undefined exercice class requirement");
		}
		unsigned int value;
		if (valueAttribute->QueryUnsignedValue(&value) != tinyxml2::XML_NO_ERROR)
		{
			throw Exception(Exception::Type::Parser, "RequirementList::loadLevelRequirementFromXML: unable to read value attribute");
		}
		_data.push_back(RequirementPtr(new SubjectRequirement(exerciceClass, value)));
	}
}

void RequirementList::loadMoveRequirementFromXML(const tinyxml2::XMLElement *child)
{
	const tinyxml2::XMLAttribute *typeAttribute = child->FindAttribute("type");
	const tinyxml2::XMLAttribute *valueAttribute = child->FindAttribute("value");
	if (typeAttribute == nullptr)
	{
		throw Exception(Exception::Type::Parser, "RequirementList::loadMoveRequirementFromXML: unable to find type attribute");
	}
	else if (valueAttribute == nullptr)
	{
		throw Exception(Exception::Type::Parser, "RequirementList::loadMoveRequirementFromXML: unable to find value attribute");
	}
	else
	{
		MoveType moveType = Parser::moveType(typeAttribute->Value());
		if (moveType == MoveType::Undefined)
		{
			throw Exception(Exception::Type::Parser, "RequirementList::loadMoveRequirementFromXML: undefined move type requirement");
		}
		unsigned int value;
		if (valueAttribute->QueryUnsignedValue(&value) != tinyxml2::XML_NO_ERROR)
		{
			throw Exception(Exception::Type::Parser, "RequirementList::loadMoveRequirementFromXML: unable to read value attribute");
		}
		_data.push_back(RequirementPtr(new MoveRequirement(moveType, value)));
	}
}

void RequirementList::appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *parent) const
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

void RequirementList::add(SubjectType category, unsigned int level)
{
    _data.push_back(RequirementPtr(new SubjectRequirement(category, level)));
}

void RequirementList::add(MoveType category, unsigned int level)
{
    _data.push_back(RequirementPtr(new MoveRequirement(category, level)));
}
