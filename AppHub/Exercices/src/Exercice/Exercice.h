#ifndef EXERCICE_H
#define EXERCICE_H

#pragma GCC diagnostic ignored "-Weffc++" // disable Weffc++ warnings
#include "IO/tinyxml2.h"
#pragma GCC diagnostic pop // turn the warnings back on

#include <iostream>

#include "RequirementList.h"
#include "LearningList.h"

class Exercice
{
    // Public
    public:
        static const std::string XML_ELEMENT;
        static const std::string XML_TYPE_ATTRIBUTE;

        enum class Type
        {
            Undefined, DotToDot
        };

    // Methods
    public:
        Exercice();
        virtual ~Exercice();
        Exercice(const Exercice& other);
        Exercice& operator=(const Exercice& other);

        bool loadFromFile(const std::string &path);

    protected:
        bool loadRequirements(const tinyxml2::XMLElement *element);
        bool loadLearnings(const tinyxml2::XMLElement *element);
        virtual bool loadContent(const tinyxml2::XMLDocument &document) = 0;

    // Attributes
    protected:
        Exercice::Type _type;
        RequirementList _requirements;
        LearningList _learnings;
};

#endif // EXERCICE_H
