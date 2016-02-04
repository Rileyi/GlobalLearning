#ifndef LEVELREQUIREMENT_H
#define LEVELREQUIREMENT_H

#include <string>
#include "Requirement.h"
#include "Definitions.h"

class SubjectRequirement : public Requirement
{
    // Constants
    public:
        static const std::string XML_ELEMENT;
        static const std::string XML_CLASS_ATTRIBUTE;

    public:
        SubjectRequirement(SubjectType category, unsigned int level = 0);
        virtual ~SubjectRequirement();
        SubjectRequirement(const SubjectRequirement& other);
        SubjectRequirement& operator=(const SubjectRequirement& other);

        SubjectRequirement* clone() const;
        void appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *element = nullptr) const;

    // Attributes
    protected:
        SubjectType _class;
};

#endif // LEVELREQUIREMENT_H
