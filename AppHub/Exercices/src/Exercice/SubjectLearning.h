#ifndef SUBJECTLEARNING_H
#define SUBJECTLEARNING_H

#include <string>
#include "Learning.h"
#include "Definitions.h"

class SubjectLearning : public Learning
{
    // Constants
    public:
        static const std::string XML_ELEMENT;
        static const std::string XML_TYPE_ATTRIBUTE;

    public:
        SubjectLearning(SubjectType category, unsigned int level = 0);
        virtual ~SubjectLearning();
        SubjectLearning(const SubjectLearning& other);
        SubjectLearning& operator=(const SubjectLearning& other);

        SubjectLearning* clone() const;
        void appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *element = nullptr) const;

    // Attributes
    protected:
        SubjectType _type;
};

#endif // SUBJECTLEARNING_H
