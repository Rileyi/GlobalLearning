#include "LearningList.h"

#include <iostream>
#include "IO/Parser.h"

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

bool LearningList::loadFromXML(const tinyxml2::XMLElement *element)
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
        if (child->Name() == SubjectLearning::XML_ELEMENT)
			success = loadLevelLearningFromXML(child);
        else if (child->Name() == MoveLearning::XML_ELEMENT)
			success = loadMoveLearningFromXML(child);
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

bool LearningList::loadLevelLearningFromXML(const tinyxml2::XMLElement *child)
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
		SubjectType exerciceClass = Parser::subjectType(classAttribute->Value());
		if (exerciceClass == SubjectType::Undefined)
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
		_data.push_back(LearningPtr(new SubjectLearning(exerciceClass, value)));
	}
	return true;
}

bool LearningList::loadMoveLearningFromXML(const tinyxml2::XMLElement *child)
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
		_data.push_back(LearningPtr(new MoveLearning(moveType, value)));
	}
	return true;
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
