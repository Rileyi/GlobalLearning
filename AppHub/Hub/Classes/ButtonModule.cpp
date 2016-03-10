#include "ButtonModule.h"



cocos2d::ui::Button* ButtonModule::getButton()
{
	return (cocos2d::ui::Button*)getChildByName("Button");
}
