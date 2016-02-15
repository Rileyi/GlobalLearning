#include "MySprite.h"



MySprite::MySprite()
{
}


MySprite::~MySprite()
{
}



MySprite* MySprite::create(TYPE type)
{
	MySprite *sprite = new (std::nothrow) MySprite();

	sprite->type = type;

	if (sprite && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}



MySprite* MySprite::create(PolygonInfo pinfo, TYPE type)
{
	MySprite *sprite = new (std::nothrow) MySprite();

	sprite->type = type;

	if (sprite && sprite->initWithPolygon(pinfo))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}



MySprite* MySprite::create(std::string filename, TYPE type)
{
	MySprite *sprite = new (std::nothrow) MySprite();

	sprite->type = type;

	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}



MySprite* MySprite::create(std::string filename, cocos2d::Rect zone, TYPE type)
{
	MySprite *sprite = new (std::nothrow) MySprite();

	sprite->type = type;

	if (sprite && sprite->initWithFile(filename, zone))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}