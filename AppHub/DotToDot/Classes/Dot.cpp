#include "Dot.h"


Dot::Dot(int x, int y, int  id)
{
	_x = x;
	_y = y;
	_id = id;
}

Dot::~Dot()
{
}
int Dot::getX()
{
	return _x;
}

int Dot::getY()
{
	return _y;
}

int Dot::getId()
{
	return _id;
}

Sprite* Dot::getSprite()
{
	return _sprite;
}

void Dot::setSprite(Sprite* sprite)
{
	_sprite = sprite;
}
