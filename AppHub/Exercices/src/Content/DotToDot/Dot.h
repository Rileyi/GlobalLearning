#ifndef DOT_H
#define DOT_H

#include "IO/I_Loadable.h"
#include <string>

class Dot : public I_Loadable //, public I_Saveable
{
	public:
		static const std::string XML_ELEMENT;
		static const std::string XML_X_ATTRIBUTE;
		static const std::string XML_Y_ATTRIBUTE;
		static const std::string XML_NUMBER_ATTRIBUTE;

	public:
		Dot();
		virtual ~Dot();
		Dot(const Dot& other);
        Dot& operator=(const Dot& other);

		// I_Loadable implementation
        bool loadFromXML(const tinyxml2::XMLElement *element);
        // Getters
        unsigned int getX() const;
        unsigned int getY() const;
        int getNumber() const;

	protected:
		unsigned int _x, _y;
		int _number;
};

#endif // DOT_H
