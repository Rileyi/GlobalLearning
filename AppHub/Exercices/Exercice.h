#ifndef EXERCICE_H
#define EXERCICE_H

#pragma GCC diagnostic ignored "-Weffc++" // disable Weffc++ warnings
#include "tinyxml2.h"
#pragma GCC diagnostic pop // turn the warnings back on

#include <iostream>

#include "RequirementList.h"

class Exercice
{
    // Public
    public:
        static const std::string XML_ELEMENT;
        static const std::string XML_TYPE_ATTRIBUTE;

        enum class Type
        {
            None, DotToDot
        };

    // Methods
    public:
        Exercice();
        virtual ~Exercice();
        Exercice(const Exercice& other);
        Exercice& operator=(const Exercice& other);

        bool loadFromFile(const std::string &path);

    protected:
        bool setType(const std::string &type);
        bool loadRequirements(const tinyxml2::XMLElement *element);
        bool loadContent(const tinyxml2::XMLDocument &document);
        bool loadDotToDotContent(const tinyxml2::XMLDocument &document);

    // Attributes
    protected:
        Exercice::Type _type;
        RequirementList _requirements;
};

#endif // EXERCICE_H
