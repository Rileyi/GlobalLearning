#pragma once

#include "AppDelegate.h"
#include "tinyxml2.h"
#include <iostream>

/*
*	source : https://github.com/NatWeiss/SpriteDraggerX
*/

/*
*	Cette classe permet de créer un layer pour pouvoir utiliser les évènements sur les sprites.
*	Actuellement elle crée un exemple de sprite qui bouge quand on click/touch dessus.
*	Pour l'utiliser, effacez les contenus des methods évènements et ajoutez-y ce qu'il
*	vous faut. Changez les membres privées sprite et touch_offset à votre
*	convenance et concevez votre layer comme vous le voulez.
*/
class MyLayer : public Layer
{
private:

	class Module
	{
	public:
		std::string name;
		std::string id;
	};

	cocos2d::Size size;




	// groupe de sprite
	std::vector<Sprite*> sprites;


	// Le décallage entre le click et la position du sprite
	// cela permet de cliquer n'importe où sur le sprite sans
	// le déplacer tout de suite à la position de la souris.
	Point touch_offset;

	// retourne la position du touch/click
	Point touchToPoint(Touch* touch);

	// retourne vrai si on a touch/click le sprite
	bool isTouchingSprite(Touch* touch);

	// retourne le sprite qui vient d'être touché
	// retourne null si aucun sprite n'a été touché
	cocos2d::Sprite* MyLayer::getTouchingSprite(Touch* touch);

	// Les methods évènements qu'il faut implémenter pour gérer les actions user
	// elles sont en mode multi-ouch
	void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
	void onTouchesMoved(const std::vector<Touch*>& touches, Event* event);
	void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);

	// afficher un module sur le menu
	void printModule(Module* module);

public:
	MyLayer();
	~MyLayer();
};