#ifndef REQUIREMENT_H
#define REQUIREMENT_H

#include "I_Saveable.h"

class Requirement //: public I_Saveable
{
    public:
        Requirement(unsigned int level = 0);
        virtual ~Requirement();
        Requirement(const Requirement& other);
        Requirement& operator=(const Requirement& other);

    // Attributes
    protected:
        unsigned int _level;
};

#endif // REQUIREMENT_H
