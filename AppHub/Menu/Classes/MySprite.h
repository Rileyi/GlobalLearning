#pragma once
#include "cocos2d.h"

/*
*	Auteur : Franck Cussac.
*	
*	Cette classe permet de d�clencher des actions diff�rentes depuis un m�me event
*	sur des instances d'un m�me objet sprite.
*	Pour chaque nouveau type de sprite il suffit de rajouter une valeur � l'enum TYPE.
*/


using namespace cocos2d;


// �num�ration des types de sprite
enum TYPE
{
	// bouton de s�lection de module
	BOUTON,
	// sprite anim�
	ANIMATION,
	// sprite d'acc�s au menu principale
	MENU
};


class MySprite : public Sprite
{
public:
	MySprite();
	~MySprite();

	// surcharge d'autorealese pour conserver le pattern du framework.
	// vous pouvez en rajouter si n�cessaire.
	static MySprite* create(TYPE type);
	static MySprite* create(PolygonInfo pinfo, TYPE type);
	static MySprite* create(std::string filename, TYPE type);
	static MySprite* create(std::string filename, Rect zone, TYPE type);

	// permet de r�cup�rer apr�s le type de sprite appel� dans un �v�nement
	TYPE type;
};

