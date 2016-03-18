#ifndef I_LOADABLE_H_INCLUDED
#define I_LOADABLE_H_INCLUDED

#pragma GCC diagnostic ignored "-Weffc++" // disable Weffc++ warnings
#include "tinyxml2.h"
#pragma GCC diagnostic pop // turn the warnings back on

// Loadable from XML node
class I_Loadable
{
    public:
        virtual ~I_Loadable() = 0;
        virtual void loadFromXML(const tinyxml2::XMLElement *element) = 0;
};

/*
If you derive anything from class A and then try to delete or destroy it, A's destructor will eventually
be called. Since it is pure and doesn't have an implementation, undefined behavior will ensue.
On one popular platform, that will invoke the purecall handler and crash.
source: http://stackoverflow.com/questions/630950/pure-virtual-destructor-in-c
 */
inline I_Loadable::~I_Loadable()
{
}

#endif // I_LOADABLE_H_INCLUDED
