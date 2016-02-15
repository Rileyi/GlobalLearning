#pragma once
#include "PointGame.h"
#include <iostream>
#include <time.h>
#include "cocos2d.h"
/*
*
*
*/

using namespace cocos2d;



class LayerPointAPoint : public Layer
{
private:

	std::vector<PointGame*> liste_Points;
	std::vector<Sprite*> liste_Sprites;
	std::vector<Label*> liste_Labels;
	Sprite* start_button;
	Point touch_offset; // décalage entre Sprite est la position exacte touchée
	int save_last_sprite_tag;



public:

	LayerPointAPoint();
	~LayerPointAPoint();
	void AffichePoints();
	void LoadPoints();
	void RelierPoints(int p1, int p2);
	std::string etiquette(int type, int id); //type 0 : Entier, type 1 : Alphabet, type 2 : Arithmètique 
	// retourne la position du touch/click
	Point touchToPoint(Touch* touch);
	// retourne vrai si on a touch/click le sprite
	bool isTouchingSprite(Touch* touch, Sprite* Sprite_test);
	void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);


};

