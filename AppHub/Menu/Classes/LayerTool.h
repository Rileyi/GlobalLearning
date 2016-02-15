#pragma once
#include "C:\Cocos\Cocos2d-x\cocos2d-x-3.10\cocos\2d\CCLayer.h"
#include "cocos2d.h"
#include "MySprite.h"
#include "LayerMenu.h"
/*
*	Auteur : Franck Cussac
*	
*
*	Cette objet doit être rajouter à chaque module du projet. Elle permet d'avoir
*	la toolbar pour retourner à l'écran de sélection, demander de l'aide...
*/

using namespace cocos2d;



class LayerTool : public cocos2d::Layer
{
private:

	// groupe de sprite
	std::vector<Node*> nodes;

	// sauvegarde la taille de la fenètre.
	Size size;

	// taille de notre tool bar
	const float X = Director::getInstance()->getWinSize().width;
	const float Y = 50;

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
	Node* getTouchingSprite(Touch* touch);

	// Les methods évènements qu'il faut implémenter pour gérer les actions user
	// elles sont en mode multi-ouch
	void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
	void onTouchesMoved(const std::vector<Touch*>& touches, Event* event);
	void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);

	// method pour créer + lancer des animations
	void playAnimation(MySprite* sprite, const std::string FILE_NAME, const float IMG_SIZE_X, const float IMG_SIZE_Y, const int NB_FRAME_X, const int NB_FRAME_Y);

public:
	LayerTool();
	~LayerTool();
};

