#include "RequirementList.h"

#include <iostream>
#include "Parser.h"

const std::string RequirementList::XML_ELEMENT = "requirements";

RequirementList::RequirementList() : _data()
{
}

RequirementList::~RequirementList()
{
}

RequirementList::RequirementList(const RequirementList& other) : _data()
{
	// Loop over the vector and deep copy each data
    for (auto it = other._data.begin(); it != other._data.end(); it++)
    {
		// this use the copy constructor of the data in the smart pointer
		// it then creates a smart pointer for the copied data
		// and stores the pointer in the array
        _data.push_back(RequirementPtr(new Requirement(**it)));
    }
}

RequirementList& RequirementList::operator=(const RequirementList& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
	_data.clear();
	// see copy constructor for explanations
	for (auto it = rhs._data.begin(); it != rhs._data.end(); it++)
		_data.push_back(RequirementPtr(new Requirement(**it)));
    return *this;
}

bool RequirementList::loadFromXML(const tinyxml2::XMLElement *element)
{
    if (element == nullptr)
        return false;
    if (element->Name() != XML_ELEMENT)
        return false;
    // Loop over all the children elements
    bool success;
    for (const tinyxml2::XMLElement* child = element->FirstChildElement(); child != nullptr; child = child->NextSiblingElement())
    {
        // Load requirement
        if (child->Name() == LevelRequirement::XML_ELEMENT)
			success = loadLevelRequirementFromXML(child);
        else if (child->Name() == MoveRequirement::XML_ELEMENT)
			success = loadMoveRequirementFromXML(child);
        else
        {
			#ifdef DEBUG
				std::cerr << child->Name() << " is not a valid requirement" << std::endl;
			#endif // DEBUG
			success = false;
        }
        if (success == false)
			return false;
    }
    return true;
}

bool RequirementList::loadLevelRequirementFromXML(const tinyxml2::XMLElement *child)
{
	const tinyxml2::XMLAttribute *classAttribute = child->FindAttribute("class");
	const tinyxml2::XMLAttribute *valueAttribute = child->FindAttribute("value");
	if (classAttribute == nullptr or valueAttribute == nullptr)
	{
		#ifdef DEBUG
			std::cerr << "Unable to find attribute" << std::endl;
		#endif // DEBUG
		return false;
	}
	else
	{
		ExerciceClass exerciceClass = Parser::exerciceClass(classAttribute->Value());
		if (exerciceClass == ExerciceClass::Undefined)
		{
			#ifdef DEBUG
				std::cerr << "Exercice class requirement undefined" << classAttribute->Value() << std::endl;
			#endif // DEBUG
			return false;
		}
		unsigned int value;
		if (valueAttribute->QueryUnsignedValue(&value) != tinyxml2::XML_NO_ERROR)
		{
			#ifdef DEBUG
				std::cerr << "Exercice level requirement undefined" << classAttribute->Value() << std::endl;
			#endif // DEBUG
			return false;
		}
		_data.push_back(RequirementPtr(new LevelRequirement(exerciceClass, value)));
	}
	return true;
}

bool RequirementList::loadMoveRequirementFromXML(const tinyxml2::XMLElement *child)
{
	const tinyxml2::XMLAttribute *typeAttribute = child->FindAttribute("type");
	const tinyxml2::XMLAttribute *valueAttribute = child->FindAttribute("value");
	if (typeAttribute == nullptr or valueAttribute == nullptr)
	{
		#ifdef DEBUG
			std::cerr << "Unable to find attribute" << std::endl;
		#endif // DEBUG
		return false;
	}
	else
	{
		MoveType moveType = Parser::moveType(typeAttribute->Value());
		if (moveType == MoveType::Undefined)
		{
			#ifdef DEBUG
				std::cerr << "Move type requirement undefined" << typeAttribute->Value() << std::endl;
			#endif // DEBUG
			return false;
		}
		unsigned int value;
		if (valueAttribute->QueryUnsignedValue(&value) != tinyxml2::XML_NO_ERROR)
		{
			#ifdef DEBUG
				std::cerr << "Move level requirement undefined" << typeAttribute->Value() << std::endl;
			#endif // DEBUG
			return false;
		}
		_data.push_back(RequirementPtr(new MoveRequirement(moveType, value)));
	}
	return true;
}

void RequirementList::add(ExerciceClass category, unsigned int level)
{
    _data.push_back(RequirementPtr(new LevelRequirement(category, level)));
}

void RequirementList::add(MoveType category, unsigned int level)
{
    _data.push_back(RequirementPtr(new MoveRequirement(category, level)));
}
