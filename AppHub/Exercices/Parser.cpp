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
