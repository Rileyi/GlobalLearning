#ifndef __DotToDot_SCENE_H__
#define __DotToDot_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Dot.h"

using namespace cocos2d;


enum class GameState
{
	Tutorial,
	Playing,
	Menu,
	GameEnd,
	FinishedDrawing
};

class DotToDotLayer : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	//static cocos2d::Layer* createLayer();
    //static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually

    CREATE_FUNC(DotToDotLayer);

	void pushDot(Dot dot);


	
private : 
	Node*  _rootNode;
	Node* _drawingNode;
	CCDrawNode* _node;
	cocos2d::ui::Button* _buttonGame;
	cocos2d::ui::Button* _buttonTutorial;
	GameState _gameState;
	std::vector <Dot> _dotsList;
	Vec2 _origin;
	Vec2 _destination;
	int _numberOfError;
	int _lastSpriteLinked;
	int _lastSpriteTouched;



protected : 
	void setupTouchHandling();
	void game(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
	void tutorial(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
	void finisshPlaying(Vec2 origin, Vec2 destination, Dot &dot);
	void displayDots();
	bool isTouchingSprite(const Touch* touch, Sprite* Sprite_test);
	Point touchToPoint(const Touch* touch);
	void drawLine(Vec2 origin, Vec2 destination);


	std::string etiquette(int type, int id); //type 0 : Entier, type 1 : Alphabet, type 2 : Arithmètique 


};

#endif // __DotToDot_SCENE_H__
