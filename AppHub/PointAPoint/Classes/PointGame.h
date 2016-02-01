#pragma once
class PointGame
{
private : 
	int _x, _y;
	int _id;
	
public:
	PointGame(int x, int y, int  id);
	~PointGame();
	int getX();
	int getY();
};

