#ifndef MOVELEARNING_H
#define MOVELEARNING_H

#include <string>
#include "Learning.h"
#include "Definitions.h"

class MoveLearning : public Learning
{
    // Constants
    public:
        static const std::string XML_ELEMENT;
        static const std::string XML_TYPE_ATTRIBUTE;

    public:
        MoveLearning(MoveType category, unsigned int level = 0);
        virtual ~MoveLearning();
        MoveLearning(const MoveLearning& other);
        MoveLearning& operator=(const MoveLearning& other);

        // Cloneable implementation
        MoveLearning* clone() const;
        // Saveable implementation
        void appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *parent) const;

    protected:
        MoveType _type;
};

#endif // MOVELEARNING_H
