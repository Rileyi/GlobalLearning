#ifndef MOVEREQUIREMENT_H
#define MOVEREQUIREMENT_H

#include <string>
#include "Requirement.h"
#include "Definitions.h"

class MoveRequirement : public Requirement
{
    // Constants
    public:
        static const std::string XML_ELEMENT;
        static const std::string XML_TYPE_ATTRIBUTE;

    public:
        MoveRequirement(MoveType category, unsigned int level = 0);
        virtual ~MoveRequirement();
        MoveRequirement(const MoveRequirement& other);
        MoveRequirement& operator=(const MoveRequirement& other);

        MoveRequirement* clone() const;
        tinyxml2::XMLElement* save(tinyxml2::XMLDocument &document) const;

    protected:
        MoveType _type;
};

#endif // MOVEREQUIREMENT_H
