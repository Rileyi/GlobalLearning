#ifndef REQUIREMENT_H
#define REQUIREMENT_H

#include "I_Cloneable.h"
#include "I_Saveable.h"
#include <string>

class Requirement : public I_Cloneable, public I_Saveable
{
	// Constants
    public:
		static const std::string XML_VALUE_ATTRIBUTE;

    // Methods
    public:
        Requirement(unsigned int level = 0);
        virtual ~Requirement();
        Requirement(const Requirement& other);
        Requirement& operator=(const Requirement& other);

        virtual Requirement* clone() const = 0;

    // Attributes
    protected:
        unsigned int _level;
};

#endif // REQUIREMENT_H
