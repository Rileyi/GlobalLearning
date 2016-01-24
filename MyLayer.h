#pragma once

#include "AppDelegate.h"

/*
*	source : https://github.com/NatWeiss/SpriteDraggerX
*/

/*
*	Cette classe permet de créer un layer pour pouvoir utiliser les évènements sur les sprites.
*	Actuellement elle crée un exemple de sprite qui bouge quand on click/touch dessus.
*	Pour l'utiliser, effacez les contenus des methods évènements et ajoutez-y ce qu'il
*	vous faut. Changez les membres privées sprite et touch_offset à votre
*	convenance et concevez votre layer comme vous le voulez.
*	
*
*	Code minimal pour pouvoir l'utiliser à ajouter dans la method bool AppDelegate::applicationDidFinishLaunching() :
*
*	// create a generic scene
*	auto scene = Scene::create();
*
*	// add the layer
*	auto layer = new MyLayer();
*	scene->addChild(layer, 1);
*	layer->release(); // addChild() retained so we release
*
*	// run the first scene
*	Director::getInstance()->runWithScene(scene);
*/
class MyLayer : public Layer
{
private:

	// Sprite qui montre un déplacement test
	Sprite* sprite;

	// Le décallage entre le click et la position du sprite
	// cela permet de cliquer n'importe où sur le sprite sans
	// le déplacer tout de suite à la position de la souris.
	Point touch_offset;

public:
	MyLayer();
	~MyLayer();

	// retourne la position du touch/click
	Point touchToPoint(Touch* touch);

	// retourne vrai si on a touch/click le sprite
	bool isTouchingSprite(Touch* touch);

	// Les methods évènements qu'il faut implémenter pour gérer les actions user
	// elles sont en mode multi-ouch
	void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
	void onTouchesMoved(const std::vector<Touch*>& touches, Event* event);
	void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);
};
