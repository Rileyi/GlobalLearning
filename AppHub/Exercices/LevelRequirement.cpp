#include "LevelRequirement.h"

const std::string LevelRequirement::XML_ELEMENT = "level";

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

tinyxml2::XMLElement* LevelRequirement::save(tinyxml2::XMLDocument &document) const
{

}
