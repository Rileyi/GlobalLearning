#ifndef __MainScene_SCENE_H__
#define __MainScene_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ToolBar.h"
#include "tinyxml2.h"
#include "ButtonModule.h"
#include <iostream>
#include "algoParcours/ParcourExos.h"

class MainScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);

	ToolBar* tool_bar;
	cocos2d::Size size;

	void createSelectScreen();
	Node* rootNode;

protected:
	void onEnter() override;
	void buttonAppeared();
	void runToolBar(bool);

private:
	void play(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
	void quit(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
	void goToMenu(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
	void shahootsPop(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
	void shahootsAie(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
	void changeDisplayModule(Ref* pSender, cocos2d::ui::Widget::TouchEventType type);

	int count_shahoots;
	ParcourExos* graph;
	std::vector<ButtonModule*> list;

};

#endif // __MainScene_SCENE_H__
