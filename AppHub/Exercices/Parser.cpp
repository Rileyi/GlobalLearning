#include "Parser.h"

ExerciceClass Parser::exerciceClass(const std::string &str)
{
	if (str == "arithmetic")
		return ExerciceClass::Arithmetic;
	else if (str == "reading")
		return ExerciceClass::Reading;
	else if (str == "writing")
		return ExerciceClass::Writing;
	else
		return ExerciceClass::Undefined;
}

MoveType Parser::moveType(const std::string &str)
{
	if (str == "drag-and-drop")
		return MoveType::DragAndDrop;
	else
		return MoveType::Undefined;
}

std::string Parser::toText(const ExerciceClass &category)
{
	if (category == ExerciceClass::Arithmetic)
		return "arithmetic";
	else if (category == ExerciceClass::Reading)
		return "reading";
	else if (category == ExerciceClass::Writing)
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
