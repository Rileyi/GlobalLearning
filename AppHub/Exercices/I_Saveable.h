#ifndef I_SAVEABLE_H_INCLUDED
#define I_SAVEABLE_H_INCLUDED

#pragma GCC diagnostic ignored "-Weffc++" // disable Weffc++ warnings
#include "tinyxml2.h"
#pragma GCC diagnostic pop // turn the warnings back on

// Saveable to XML file
class I_Saveable
{
    public:
		virtual ~I_Saveable() = 0;
		// Appends the element as the last child of parent
		// If parent is nullptr, appends at the end of the document
        virtual void appendToXML(tinyxml2::XMLDocument &document, tinyxml2::XMLElement *parent = nullptr) const = 0;
};

inline I_Saveable::~I_Saveable()
{
}

#endif // I_SAVEABLE_H_INCLUDED
