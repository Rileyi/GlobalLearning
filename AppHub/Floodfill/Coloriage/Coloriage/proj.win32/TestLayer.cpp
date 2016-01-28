#include "TestLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


bool TestLayer::init() {

	if (!Layer::init()) {

		cocos2d::log("you should not see this");
		return false;
	}
	return true;
}

