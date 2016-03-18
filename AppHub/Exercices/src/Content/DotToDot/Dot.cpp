#include "Dot.h"
#include <iostream>

const std::string Dot::XML_ELEMENT = "dot";
const std::string Dot::XML_X_ATTRIBUTE = "x";
const std::string Dot::XML_Y_ATTRIBUTE = "y";
const std::string Dot::XML_NUMBER_ATTRIBUTE = "number";

Dot::Dot() : _x(0), _y(0), _number(0)
{
}

Dot::~Dot()
{
}

Dot::Dot(const Dot& other) : _x(other._x), _y(other._y), _number(other._number)
{
}

Dot& Dot::operator=(const Dot& other)
{
	_x = other._x;
	_y = other._y;
	_number = other._number;
	return *this;
}

bool Dot::loadFromXML(const tinyxml2::XMLElement *element)
{
	if (element->Name() != XML_ELEMENT)
	{
        #ifdef DEBUG
            std::cerr << "Error while loading Dot: " << element->Name() << " is an incorrect element name" << std::endl;
        #endif // DEBUG
		return false;
	}
	const tinyxml2::XMLAttribute *xAttribute = element->FindAttribute(XML_X_ATTRIBUTE.c_str());
	const tinyxml2::XMLAttribute *yAttribute = element->FindAttribute(XML_Y_ATTRIBUTE.c_str());
	const tinyxml2::XMLAttribute *numberAttribute = element->FindAttribute(XML_NUMBER_ATTRIBUTE.c_str());

	if (xAttribute == nullptr or yAttribute == nullptr or numberAttribute == nullptr)
	{
		#ifdef DEBUG
			std::cerr << "Error while loading Dot: Unable to find attribute" << std::endl;
		#endif // DEBUG
		return false;
	}
	if (xAttribute->QueryUnsignedValue(&_x) != tinyxml2::XML_NO_ERROR)
	{
		#ifdef DEBUG
			std::cerr << "Error while loading Dot: no x attribute" << std::endl;
		#endif // DEBUG
		return false;
	}
	if (yAttribute->QueryUnsignedValue(&_y) != tinyxml2::XML_NO_ERROR)
	{
		#ifdef DEBUG
			std::cerr << "Error while loading Dot: no y attribute" << std::endl;
		#endif // DEBUG
		return false;
	}

	if (numberAttribute->QueryIntValue(&_number) != tinyxml2::XML_NO_ERROR)
	{
		#ifdef DEBUG
			std::cerr << "Error while loading Dot: no number attribute" << std::endl;
		#endif // DEBUG
		return false;
	}
	return true;
}

unsigned int Dot::getX() const
{
	return _x;
}

unsigned int Dot::getY() const
{
	return _y;
}

int Dot::getNumber() const
{
	return _number;
}
