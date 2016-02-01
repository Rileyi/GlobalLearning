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

    public:
        MoveRequirement(MoveType category, unsigned int level = 0);
        virtual ~MoveRequirement();
        MoveRequirement(const MoveRequirement& other);
        MoveRequirement& operator=(const MoveRequirement& other);

    protected:
        MoveType _type;
};

#endif // MOVEREQUIREMENT_H
