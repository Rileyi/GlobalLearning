#ifndef LEVELREQUIREMENT_H
#define LEVELREQUIREMENT_H

#include <string>
#include "Requirement.h"
#include "Definitions.h"

class LevelRequirement : public Requirement
{
    // Constants
    public:
        static const std::string XML_ELEMENT;

    public:
        LevelRequirement(ExerciceClass category, unsigned int level = 0);
        virtual ~LevelRequirement();
        LevelRequirement(const LevelRequirement& other);
        LevelRequirement& operator=(const LevelRequirement& other);

		LevelRequirement* clone() const;
        tinyxml2::XMLElement* save(tinyxml2::XMLDocument &document) const;

    // Attributes
    protected:
        ExerciceClass _class;
};

#endif // LEVELREQUIREMENT_H
