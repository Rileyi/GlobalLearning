#include "Exercice.h"
#include "IO/Parser.h"
#include "Exception.h"

const std::string Exercice::XML_ELEMENT = "exercice";
const std::string Exercice::XML_TYPE_ATTRIBUTE = "type";
const std::string Exercice::XML_CONTENT_ELEMENT = "content";

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

void Exercice::loadFromFile(const std::string &path)
{
    tinyxml2::XMLDocument document;

    /* Open the XML document */
    if (document.LoadFile(path.c_str()) != tinyxml2::XML_NO_ERROR)
    {
		throw Exception(Exception::Type::Parser, "Exercice::loadFromFile: error while opening " + path);
    }
    /* Check document structure */
    tinyxml2::XMLElement *root = document.RootElement();
    if (root->Name() != XML_ELEMENT)
    {
		throw Exception(Exception::Type::Parser, "Exercice::loadFromFile: " + std::string(root->Name()) + " is not a valid root element name");
    }
    /* Check exercice type */
    const char *type = root->Attribute(XML_TYPE_ATTRIBUTE.c_str());
    if (type == nullptr)
		throw Exception(Exception::Type::Parser, "Exercice::loadFromFile: unable to find type attribute");
    _type = Parser::exerciceType(type);
    if (_type == Exercice::Type::Undefined)
    {
		throw Exception(Exception::Type::Parser, "Exercice::loadFromFile: undefined exercice type");
    }
    /* Load requirements */
    loadRequirements(root);
    /* Load learnings */
    loadLearnings(root);
    /* Load content */
    loadContent(root);
}

void Exercice::loadRequirements(const tinyxml2::XMLElement *root)
{
    if (root == nullptr)
    {
		throw Exception(Exception::Type::Parser, "Exercice::loadRequirements: given root element is nullptr");
    }
    const tinyxml2::XMLElement *element = root->FirstChildElement(RequirementList::XML_ELEMENT.c_str());
    if (element == nullptr)
    {
		throw Exception(Exception::Type::Parser, "Exercice::loadRequirements: unable to find " + RequirementList::XML_ELEMENT + " element");
    }
    _requirements.loadFromXML(element);
}

void Exercice::loadLearnings(const tinyxml2::XMLElement *root)
{
    if (root == nullptr)
    {
		throw Exception(Exception::Type::Parser, "Exercice::loadLearnings: given root element is nullptr");
    }
    const tinyxml2::XMLElement *element = root->FirstChildElement(LearningList::XML_ELEMENT.c_str());
    if (element == nullptr)
    {
		throw Exception(Exception::Type::Parser, "Exercice::loadLearnings: unable to find " + LearningList::XML_ELEMENT + " element");
    }
    _learnings.loadFromXML(element);
}
