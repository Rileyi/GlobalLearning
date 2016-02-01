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

RequirementList::RequirementList(const RequirementList& other) : _data(other._data)
{
}

RequirementList& RequirementList::operator=(const RequirementList& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    _data = rhs._data;
    return *this;
}

bool RequirementList::loadFromXML(const tinyxml2::XMLElement *element)
{
    if (element == nullptr)
        return false;
    if (element->Name() != XML_ELEMENT)
        return false;
    // Loop over all the children elements
    for (const tinyxml2::XMLElement* child = element->FirstChildElement(); child != nullptr; child = child->NextSiblingElement())
    {
        /*
        TODO

        Load data from the XML nodes
        */
        if (child->Name() == LevelRequirement::XML_ELEMENT)
        {
			loadLevelRequirementFromXML(child);

        }
        else if (child->Name() == MoveRequirement::XML_ELEMENT)
        {

        }
        else
        {

        }
    }
    return true;
}

void RequirementList::loadLevelRequirementFromXML(const tinyxml2::XMLElement *child)
{
	const tinyxml2::XMLAttribute *classAttribute = child->FindAttribute("class");
	const tinyxml2::XMLAttribute *valueAttribute = child->FindAttribute("value");
	if (classAttribute == nullptr or valueAttribute == nullptr)
	{
		#ifdef DEBUG
			std::cerr << "Unable to find attribute" << std::endl;
		#endif // DEBUG
		return;
	}
	else
	{
		ExerciceClass exerciceClass = Parser::exerciceClass(classAttribute->Value());
		if (exerciceClass == ExerciceClass::Undefined)
		{
			#ifdef DEBUG
				std::cerr << "Exercice class requirement undefined" << classAttribute->Value() << std::endl;
			#endif // DEBUG
			return;
		}
		unsigned int value;
		if (valueAttribute->QueryUnsignedValue(&value) != tinyxml2::XML_NO_ERROR)
		{
			#ifdef DEBUG
				std::cerr << "Exercice level requirement undefined" << classAttribute->Value() << std::endl;
			#endif // DEBUG
			return;
		}
		_data.push_back(LevelRequirement(exerciceClass, value));
	}
}

void RequirementList::loadMoveRequirementFromXML(const tinyxml2::XMLElement *child)
{
	const tinyxml2::XMLAttribute *typeAttribute = child->FindAttribute("type");
	const tinyxml2::XMLAttribute *valueAttribute = child->FindAttribute("value");
	if (typeAttribute == nullptr or valueAttribute == nullptr)
	{
		#ifdef DEBUG
			std::cerr << "Unable to find attribute" << std::endl;
		#endif // DEBUG
		return;
	}
	else
	{
		MoveType moveType = Parser::moveType(typeAttribute->Value());
		if (moveType == MoveType::Undefined)
		{
			#ifdef DEBUG
				std::cerr << "Move type requirement undefined" << typeAttribute->Value() << std::endl;
			#endif // DEBUG
			return;
		}
		unsigned int value;
		if (valueAttribute->QueryUnsignedValue(&value) != tinyxml2::XML_NO_ERROR)
		{
			#ifdef DEBUG
				std::cerr << "Move level requirement undefined" << typeAttribute->Value() << std::endl;
			#endif // DEBUG
			return;
		}
		_data.push_back(MoveRequirement(moveType, value));
	}
}

void RequirementList::add(ExerciceClass category, unsigned int level)
{
    _data.push_back(LevelRequirement(category, level));
}

void RequirementList::add(MoveType category, unsigned int level)
{
    _data.push_back(MoveRequirement(category, level));
}
