#ifndef DOTTODOTEXERCICE_H
#define DOTTODOTEXERCICE_H

#include "Content/DotToDot/DotToDotLayer.h"
#include "Exercice/Exercice.h"
#include <vector>
#include "Exception.h"
//#include "Content/DotToDot/Dot.h"

class DotToDotExercice : public Exercice
{
	public:
		DotToDotExercice();
		DotToDotExercice(const DotToDotExercice &other);
		virtual ~DotToDotExercice();

		DotToDotExercice& operator=(const DotToDotExercice& rhs);
		cocos2d::Scene* getScene();
	protected:
		void loadContent(const tinyxml2::XMLElement *root);
		std::vector<Dot> _dots;
		cocos2d::Scene *scene;
		DotToDotLayer *dotToDotLayer;
		
};

#endif // DOTTODOTEXERCICE_H
