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
    {
        #ifdef DEBUG
            std::cerr << "Error while loading: " << root->Name() << " is an incorrect root element name" << std::endl;
        #endif // DEBUG
        return false;
    }
    /* Check exercice type */
    const char *type = root->Attribute(XML_TYPE_ATTRIBUTE.c_str());
    if (type == nullptr)
        return false;
    _type = Parser::exerciceType(type);
    if (_type == Exercice::Type::Undefined)
    {
        #ifdef DEBUG
            std::cerr << "Error while loading: undefined exercice type" << std::endl;
        #endif // DEBUG
        return false;
    }
    /* Load requirements */
    if (loadRequirements(root) == false)
    {
        #ifdef DEBUG
            std::cerr << "Error while loading exercice requirements" << std::endl;
        #endif // DEBUG
        return false;
    }
    /* Load learnings */
    if (loadLearnings(root) == false)
    {
        #ifdef DEBUG
            std::cerr << "Error while loading exercice learnings" << std::endl;
        #endif // DEBUG
        return false;
    }
    /* Load content */
    if (loadContent(root) == false)
    {
        #ifdef DEBUG
            std::cerr << "Error while loading exercice content" << std::endl;
        #endif // DEBUG
        return false;
    }

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
    const tinyxml2::XMLElement *element = root->FirstChildElement(LearningList::XML_ELEMENT.c_str());
    if (element == nullptr)
    {
        #ifdef DEBUG
            std::cerr << "Not a learning element" << std::endl;
        #endif // DEBUG
        return false;
    }
    return _learnings.loadFromXML(element);
}
