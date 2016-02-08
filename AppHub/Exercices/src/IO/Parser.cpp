#include "Parser.h"

Exercice::Type Parser::exerciceType(const std::string &str)
{
	if (str == "dot-to-dot")
		return Exercice::Type::DotToDot;
	else
		return Exercice::Type::Undefined;
}

SubjectType Parser::subjectType(const std::string &str)
{
	if (str == "arithmetic")
		return SubjectType::Arithmetic;
	else if (str == "reading")
		return SubjectType::Reading;
	else if (str == "writing")
		return SubjectType::Writing;
	else
		return SubjectType::Undefined;
}

MoveType Parser::moveType(const std::string &str)
{
	if (str == "drag-and-drop")
		return MoveType::DragAndDrop;
	else
		return MoveType::Undefined;
}

std::string Parser::toText(const Exercice::Type &type)
{
	if (type == Exercice::Type::DotToDot)
		return "dot-to-dot";
	else
		return "undefined";
}

std::string Parser::toText(const SubjectType &category)
{
	if (category == SubjectType::Arithmetic)
		return "arithmetic";
	else if (category == SubjectType::Reading)
		return "reading";
	else if (category == SubjectType::Writing)
		return "writing";
	else
		return "undefined";
}

std::string Parser::toText(const MoveType &type)
{
	if (type == MoveType::DragAndDrop)
		return "drag-and-drop";
	else
		return "undefined";
}
