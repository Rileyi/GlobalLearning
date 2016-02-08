#include "Exercice.h"
#include "IO/Parser.h"

const std::string Exercice::XML_ELEMENT = "exercice";
const std::string Exercice::XML_TYPE_ATTRIBUTE = "type";

Exercice::Exercice() : _type(Exercice::Type::Undefined), _requirements(), _learnings()
{
    //ctor
}

Exercice::~Exercice()
{
    //dtor
}

Exercice::Exercice(const Exercice& other) : _type(other._type), _requirements(other._requirements), _learnings(other._learnings)
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
    if (root->Name() != XML_ELEMENT)
        return false;
    /* Check exercice type */
    const char *type = root->Attribute(XML_TYPE_ATTRIBUTE.c_str());
    if (type == nullptr)
        return false;
    _type = Parser::exerciceType(type);
    if (_type == Exercice::Type::Undefined)
        return false;
    /* Load requirements */
    if (loadRequirements(root) == false)
        return false;

    return true;
}

bool Exercice::loadRequirements(const tinyxml2::XMLElement *root)
{
    if (root == nullptr)
    {
        #ifdef DEBUG
            std::cerr << "Root element is null" << std::endl;
        #endif // DEBUG
        return false;
    }
    const tinyxml2::XMLElement *element = root->FirstChildElement(RequirementList::XML_ELEMENT.c_str());
    if (element == nullptr)
    {
        #ifdef DEBUG
            std::cerr << "Not a requirement element" << std::endl;
        #endif // DEBUG
        return false;
    }
    return _requirements.loadFromXML(element);
}

bool Exercice::loadLearnings(const tinyxml2::XMLElement *root)
{
    if (root == nullptr)
    {
        #ifdef DEBUG
            std::cerr << "Root element is null" << std::endl;
        #endif // DEBUG
        return false;
    }
    const tinyxml2::XMLElement *element = root->FirstChildElement(RequirementList::XML_ELEMENT.c_str());
    if (element == nullptr)
    {
        #ifdef DEBUG
            std::cerr << "Not a learning element" << std::endl;
        #endif // DEBUG
        return false;
    }
    return _learnings.loadFromXML(element);
}

bool Exercice::loadContent(const tinyxml2::XMLDocument &document)
{
    switch(_type)
    {
    case Exercice::Type::Undefined:
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
