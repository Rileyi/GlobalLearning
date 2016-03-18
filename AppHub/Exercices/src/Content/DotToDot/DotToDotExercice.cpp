#include "DotToDotExercice.h"

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

bool DotToDotExercice::loadContent(const tinyxml2::XMLElement *root)
{
	const tinyxml2::XMLElement *element = root->FirstChildElement(Exercice::XML_CONTENT_ELEMENT.c_str());
	if (element == nullptr)
	{
		#ifdef DEBUG
			std::cerr << "Error while loading: unable to find content element" << std::endl;
		#endif // DEBUG
		return false;
	}
    // Loop over all the children elements
    for (const tinyxml2::XMLElement* child = element->FirstChildElement(); child != nullptr; child = child->NextSiblingElement())
    {
        // Load dot
        Dot dot;
        if (dot.loadFromXML(child) == false)
        {
			#ifdef DEBUG
				std::cerr << "Error while loading dot" << std::endl;
			#endif // DEBUG
			return false;
        }
        else
        {
			std::cout << "Loaded " << dot.getNumber() << " sucessfully (" << dot.getX() << ";" << dot.getY() << ")" << std::endl;
			_dots.push_back(dot);
        }
    }
	return true;
}
