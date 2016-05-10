#pragma once
#include "cocos2d.h"
class Color : public cocos2d::Color4F
{
public:
	Color(char r, char v, char b, float a);
	~Color();
};

