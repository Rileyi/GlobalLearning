#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "Definitions.h"
#include "Exercice.h"

class Parser
{
	public:
		static Exercice::Type exerciceType(const std::string&);
		static SubjectType subjectType(const std::string &);
		static MoveType moveType(const std::string &);

		static std::string toText(const Exercice::Type&);
		static std::string toText(const SubjectType&);
		static std::string toText(const MoveType&);

	private:
		Parser();
};

#endif // PARSER_H
