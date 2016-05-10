#include "Dot.h"
#include <iostream>
#include "Exception.h"

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

void Dot::loadFromXML(const tinyxml2::XMLElement *element)
{
	if (element->Name() != XML_ELEMENT)
		throw Exception(Exception::Type::Parser, std::string(element->Name()) + " is an incorrect element name");

	const tinyxml2::XMLAttribute *xAttribute = element->FindAttribute(XML_X_ATTRIBUTE.c_str());
	const tinyxml2::XMLAttribute *yAttribute = element->FindAttribute(XML_Y_ATTRIBUTE.c_str());
	const tinyxml2::XMLAttribute *numberAttribute = element->FindAttribute(XML_NUMBER_ATTRIBUTE.c_str());

	if (xAttribute == nullptr)
		throw Exception(Exception::Type::Parser, "Error while loading Dot: unable to find x attribute");
	if (yAttribute == nullptr)
		throw Exception(Exception::Type::Parser, "Error while loading Dot: unable to find y attribute");
	if (numberAttribute == nullptr)
		throw Exception(Exception::Type::Parser, "Error while loading Dot: unable to find number attribute");
	if (xAttribute->QueryUnsignedValue(&_x) != tinyxml2::XML_NO_ERROR)
		throw Exception(Exception::Type::Parser, "Error while loading Dot: unable to read x attribute");
	if (yAttribute->QueryUnsignedValue(&_y) != tinyxml2::XML_NO_ERROR)
		throw Exception(Exception::Type::Parser, "Error while loading Dot: unable to read y attribute");
	if (numberAttribute->QueryIntValue(&_number) != tinyxml2::XML_NO_ERROR)
		throw Exception(Exception::Type::Parser, "Error while loading Dot: unable to read number attribute");
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

cocos2d::Sprite* Dot::getSprite()
{
	return _sprite;
}

void Dot::setSprite(cocos2d::Sprite* sprite)
{
	_sprite = sprite;
}
