#include "point_a_point.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* point_a_point::createScene()
{
	auto scene = Scene::create();
	auto layer = point_a_point::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool point_a_point::init()
{
	auto dirs = Director::getInstance();
	Size visibleSize = dirs->getVisibleSize();

	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto label1 = Label::createWithTTF("My Game", "Marker Felt.ttf", 36);
	label1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	this->addChild(label1);

	return true;
}

