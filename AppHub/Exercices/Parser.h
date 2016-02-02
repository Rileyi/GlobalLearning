#ifndef PARSER_H
#define PARSER_H

#include "Definitions.h"
#include <string>

class Parser
{
	public:
		static ExerciceClass exerciceClass(const std::string &);
		static MoveType moveType(const std::string &);

		static std::string toText(const ExerciceClass&);
		static std::string toText(const MoveType&);

	private:
		Parser();
};

#endif // PARSER_H
