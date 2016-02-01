#ifndef I_SAVEABLE_H_INCLUDED
#define I_SAVEABLE_H_INCLUDED

#include <string>

// Saveable to XML file
class I_Saveable
{
    public:
		virtual ~I_Saveable() = 0;
        virtual std::string toXML() const = 0;
};

inline I_Saveable::~I_Saveable()
{
}

#endif // I_SAVEABLE_H_INCLUDED
