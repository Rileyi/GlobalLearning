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
        static const std::string XML_CONTENT_ELEMENT;

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

        void loadFromFile(const std::string &path);

    protected:
        void loadRequirements(const tinyxml2::XMLElement *root);
        void loadLearnings(const tinyxml2::XMLElement *root);
        virtual void loadContent(const tinyxml2::XMLElement *root) = 0;

    // Attributes
    protected:
        Exercice::Type _type;
        RequirementList _requirements;
        LearningList _learnings;
};

#endif // EXERCICE_H
