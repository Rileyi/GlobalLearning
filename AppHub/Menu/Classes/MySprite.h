#pragma once
#include "cocos2d.h"

/*
*	Auteur : Franck Cussac.
*	
*	Cette classe permet de déclencher des actions différentes depuis un même event
*	sur des instances d'un même objet sprite.
*	Pour chaque nouveau type de sprite il suffit de rajouter une valeur à l'enum TYPE.
*/


using namespace cocos2d;


// énumération des types de sprite
enum TYPE
{
	// bouton de sélection de module
	BOUTON,
	// sprite animé
	ANIMATION,
	// sprite d'accès au menu principale
	MENU
};


class MySprite : public Sprite
{
public:
	MySprite();
	~MySprite();

	// surcharge d'autorealese pour conserver le pattern du framework.
	// vous pouvez en rajouter si nécessaire.
	static MySprite* create(TYPE type);
	static MySprite* create(PolygonInfo pinfo, TYPE type);
	static MySprite* create(std::string filename, TYPE type);
	static MySprite* create(std::string filename, Rect zone, TYPE type);

	// permet de récupérer après le type de sprite appelé dans un évènement
	TYPE type;
};

