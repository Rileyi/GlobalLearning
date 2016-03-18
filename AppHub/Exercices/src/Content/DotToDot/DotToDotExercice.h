#ifndef DOTTODOTEXERCICE_H
#define DOTTODOTEXERCICE_H

#include "Exercice/Exercice.h"
#include <vector>
#include "Content/DotToDot/Dot.h"

class DotToDotExercice : public Exercice
{
	public:
		DotToDotExercice();
		DotToDotExercice(const DotToDotExercice &other);
		virtual ~DotToDotExercice();

		DotToDotExercice& operator=(const DotToDotExercice& rhs);

	protected:
		bool loadContent(const tinyxml2::XMLElement *root);
		std::vector<Dot> _dots;
};

#endif // DOTTODOTEXERCICE_H
