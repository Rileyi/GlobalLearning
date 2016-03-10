#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class ButtonModule : public cocos2d::Node
{
public:
	CREATE_FUNC(ButtonModule);
	cocos2d::ui::Button* getButton();
};

