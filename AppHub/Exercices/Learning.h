#ifndef LEARNING_H
#define LEARNING_H

#include "I_Cloneable.h"
#include "I_Saveable.h"
#include <string>

class Learning : public I_Cloneable, public I_Saveable
{
	// Constants
    public:
		static const std::string XML_EXPERIENCE_ATTRIBUTE;

    // Methods
    public:
        Learning(unsigned int level = 0);
        virtual ~Learning();
        Learning(const Learning& other);
        Learning& operator=(const Learning& other);

        virtual Learning* clone() const = 0;

    // Attributes
    protected:
        unsigned int _experience;
};

#endif // LEARNING_H
