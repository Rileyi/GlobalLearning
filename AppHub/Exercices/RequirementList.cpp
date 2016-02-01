#include "RequirementList.h"

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

void RequirementList::add(ExerciceClass category, unsigned int level)
{
    _data.push_back(LevelRequirement(category, level));
}

void RequirementList::add(MoveClass category, unsigned int level)
{
    _data.push_back(MoveRequirement(category, level));
}
