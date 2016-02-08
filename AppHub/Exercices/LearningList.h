#ifndef LEARNINGLIST_H
#define LEARNINGLIST_H

#include <memory>
#include <vector>
#include <string>

#include "Definitions.h"
#include "I_Loadable.h"
#include "I_Saveable.h"
#include "Learning.h"
#include "SubjectLearning.h"
#include "MoveLearning.h"

class LearningList : public I_Loadable, public I_Saveable
{
    typedef std::unique_ptr<Learning> LearningPtr;

    // Constants
    public:
        static const std::string XML_ELEMENT;

    // Methods
    public:
        LearningList();
        virtual ~LearningList();
        LearningList(const LearningList& other);
        LearningList& operator=(const LearningList& other);

        // I_Loadable implementation
        bool loadFromXML(const tinyxml2::XMLElement *element);
        // Saveable implementation
        void appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *parent = nullptr) const;
        // Add an exercice class level requirement
        void add(SubjectType category, unsigned int level);
        // Add an move class level requirement
        void add(MoveType category, unsigned int level);

    protected:
        bool loadLevelLearningFromXML(const tinyxml2::XMLElement *element);
        bool loadMoveLearningFromXML(const tinyxml2::XMLElement *element);

    // Attributes
    protected:
        std::vector<LearningPtr> _data;
};

#endif // LEARNINGLIST_H
