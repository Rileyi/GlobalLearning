#include "Exercice.h"

const std::string Exercice::XML_ROOT_ELEMENT = "exercice";
const std::string Exercice::XML_TYPE_ATTRIBUTE = "type";
const std::string Exercice::XML_REQUIREMENTS_ELEMENT = "requirements";

Exercice::Exercice() : _type(Exercice::Type::None), _requirements()
{
    //ctor
}

Exercice::~Exercice()
{
    //dtor
}

Exercice::Exercice(const Exercice& other) : _type(other._type), _requirements(other._requirements)
{
    //copy ctor
}

Exercice& Exercice::operator=(const Exercice& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
    _type = rhs._type;
    _requirements = rhs._requirements;
    return *this;
}

bool Exercice::loadFromFile(const std::string &path)
{
    tinyxml2::XMLDocument document;

    /* Open the XML document */
    if (document.LoadFile(path.c_str()) != tinyxml2::XML_NO_ERROR)
    {
        #ifdef DEBUG
            std::cerr << "Error while loading " << path << std::endl;
        #endif // DEBUG
        return false;
    }
    /* Check document structure */
    tinyxml2::XMLElement *root = document.RootElement();
    if (root->Name() != XML_ROOT_ELEMENT)
        return false;
    /* Check exercice type */
    const char *type = root->Attribute(XML_TYPE_ATTRIBUTE.c_str());
    if (type == nullptr)
        return false;
    if (setType(type) == false)
        return false;
    if (loadRequirements(root->FirstChildElement(XML_REQUIREMENTS_ELEMENT.c_str())) == false)
        return false;

    return true;
}

bool Exercice::setType(const std::string &type)
{
    if (type == "dot-to-dot")
        _type = Exercice::Type::DotToDot;
    /* Check if the type has been set */
    if (_type == Exercice::Type::None)
        return false;
    return true;
}

bool Exercice::loadRequirements(const tinyxml2::XMLElement *element)
{
    if (element == nullptr)
        return false;
    if (element->Name() != XML_REQUIREMENTS_ELEMENT)
        return false;
    /*
    TO DO
    Save the requirements for later
    */
    return true;
}

bool Exercice::loadContent(const tinyxml2::XMLDocument &document)
{
    switch(_type)
    {
    case Exercice::Type::None:
        return false;
        break;
    case Exercice::Type::DotToDot:
        return loadDotToDotContent(document);
        break;
    default:
        return false;
        break;
    }
}

bool Exercice::loadDotToDotContent(const tinyxml2::XMLDocument &document)
{
    /*
    TO DO
    Get the data from the file
    A dot has this structure in the XML file :
    <dot number="0" x="x_axis_value" y="y_axis_value"/>
    */
    return true;
}
