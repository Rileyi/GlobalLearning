#pragma once

#include "tinyxml2.h"
#include <iostream>
#include "MySprite.h"
#include "PointAPoint/LayerPointAPoint.h"
#include "cocos2d.h"
#include "LayerTool.h"

/*
*	Auteur : Franck Cussac.
*	
*	source utilisée : https://github.com/NatWeiss/SpriteDraggerX
*/

using namespace cocos2d;


/*
*	Cette classe permet de créer un layer pour pouvoir utiliser les évènements sur les sprites.
*	Actuellement elle crée un exemple de sprite qui bouge quand on click/touch dessus.
*	Pour l'utiliser, effacez les contenus des methods évènements et ajoutez-y ce qu'il
*	vous faut. Changez les membres privées sprite et touch_offset à votre
*	convenance et concevez votre layer comme vous le voulez.
*/
class LayerMenu : public Layer
{
private:

	// utilisé pour réduire des arguments
	class Module
	{
	public:
		std::string name;
		std::string id;
	};

	// sauvegarde la taille de la fenètre.
	Size size;

	// noms des modules pour les retrouver
	const std::string DOT_LINK = "dot_link";


	// groupe de sprite
	std::vector<Node*> nodes;


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

	// afficher un module sur le menu
	void printModule(Module* module);


	// method pour créer + lancer des animations
	void playAnimation(MySprite* sprite, const std::string FILE_NAME, const float IMG_SIZE_X, const float IMG_SIZE_Y, const int NB_FRAME_X, const int NB_FRAME_Y);

public:
	LayerMenu();
	~LayerMenu();
};