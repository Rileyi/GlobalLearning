#include "DotToDotExercice.h"
#include "Exception.h"

DotToDotExercice::DotToDotExercice() : _dots()
{
	//ctor
}

DotToDotExercice::DotToDotExercice(const DotToDotExercice &other) : Exercice(other), _dots(other._dots)
{
}

DotToDotExercice& DotToDotExercice::operator=(const DotToDotExercice& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    _dots = rhs._dots;
    return *this;
}

DotToDotExercice::~DotToDotExercice()
{
}

void DotToDotExercice::loadContent(const tinyxml2::XMLElement *root)
{
    if (root == nullptr)
		throw Exception(Exception::Type::Parser, "loadContent: root element is null");

	const tinyxml2::XMLElement *element = root->FirstChildElement(Exercice::XML_CONTENT_ELEMENT.c_str());
	if (element == nullptr)
		throw Exception(Exception::Type::Parser, "loadContent: unable to find content element");
    // Loop over all the children elements
    for (const tinyxml2::XMLElement* child = element->FirstChildElement(); child != nullptr; child = child->NextSiblingElement())
    {
        // Load dot
        Dot dot;
		dot.loadFromXML(child);
		_dots.push_back(dot);
    }
}
