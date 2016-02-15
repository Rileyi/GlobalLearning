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
*	source utilis�e : https://github.com/NatWeiss/SpriteDraggerX
*/

using namespace cocos2d;


/*
*	Cette classe permet de cr�er un layer pour pouvoir utiliser les �v�nements sur les sprites.
*	Actuellement elle cr�e un exemple de sprite qui bouge quand on click/touch dessus.
*	Pour l'utiliser, effacez les contenus des methods �v�nements et ajoutez-y ce qu'il
*	vous faut. Changez les membres priv�es sprite et touch_offset � votre
*	convenance et concevez votre layer comme vous le voulez.
*/
class LayerMenu : public Layer
{
private:

	// utilis� pour r�duire des arguments
	class Module
	{
	public:
		std::string name;
		std::string id;
	};

	// sauvegarde la taille de la fen�tre.
	Size size;

	// noms des modules pour les retrouver
	const std::string DOT_LINK = "dot_link";


	// groupe de sprite
	std::vector<Node*> nodes;


	// Le d�callage entre le click et la position du sprite
	// cela permet de cliquer n'importe o� sur le sprite sans
	// le d�placer tout de suite � la position de la souris.
	Point touch_offset;

	// retourne la position du touch/click
	Point touchToPoint(Touch* touch);

	// retourne vrai si on a touch/click le sprite
	bool isTouchingSprite(Touch* touch);

	// retourne le sprite qui vient d'�tre touch�
	// retourne null si aucun sprite n'a �t� touch�
	Node* getTouchingSprite(Touch* touch);

	// Les methods �v�nements qu'il faut impl�menter pour g�rer les actions user
	// elles sont en mode multi-ouch
	void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
	void onTouchesMoved(const std::vector<Touch*>& touches, Event* event);
	void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);

	// afficher un module sur le menu
	void printModule(Module* module);


	// method pour cr�er + lancer des animations
	void playAnimation(MySprite* sprite, const std::string FILE_NAME, const float IMG_SIZE_X, const float IMG_SIZE_Y, const int NB_FRAME_X, const int NB_FRAME_Y);

public:
	LayerMenu();
	~LayerMenu();
};