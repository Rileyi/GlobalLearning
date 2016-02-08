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

        // Cloneable implementation
        MoveRequirement* clone() const;
        // Saveable implementation
        void appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *parent) const;

    protected:
        MoveType _type;
};

#endif // MOVEREQUIREMENT_H
