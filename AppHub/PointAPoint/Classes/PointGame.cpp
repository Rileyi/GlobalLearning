#include "PointGame.h"

PointGame::PointGame(int x, int y, int  id)
	{
		_x = x;
		_y = y;
		_id = id;
	}

PointGame::~PointGame()
	{
	}
int PointGame::getX()
{
	return _x;
}

int PointGame::getY()
{
	return _y;
}
