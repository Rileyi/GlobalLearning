#ifndef REQUIREMENTLIST_H
#define REQUIREMENTLIST_H

#include <memory>
#include <vector>
#include <string>
#include "Definitions.h"
#include "I_Loadable.h"
#include "Requirement.h"
#include "LevelRequirement.h"
#include "MoveRequirement.h"

class RequirementList : public I_Loadable
{
    typedef std::unique_ptr<Requirement> RequirementPtr;
    // Constants
    public:
        static const std::string XML_ELEMENT;

    // Methods
    public:
        RequirementList();
        virtual ~RequirementList();
        RequirementList(const RequirementList& other);
        RequirementList& operator=(const RequirementList& other);

        // I_Loadable implementation
        bool loadFromXML(const tinyxml2::XMLElement *element);
        // Add an exercice class level requirement
        void add(ExerciceClass category, unsigned int level);
        // Add an move class level requirement
        void add(MoveType category, unsigned int level);

    protected:
        bool loadLevelRequirementFromXML(const tinyxml2::XMLElement *element);
        bool loadMoveRequirementFromXML(const tinyxml2::XMLElement *element);

    // Attributes
    protected:
        std::vector<RequirementPtr> _data;
};

#endif // REQUIREMENTLIST_H
