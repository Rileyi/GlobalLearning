#include "cocos2d.h"

using namespace cocos2d;

class Dot 
{
private:
	int _x, _y;
	int _id;
	Sprite* _sprite;


public:


	Dot(int x, int y, int  id);
	~Dot();
	int getX();
	int getY();
	int getId();
	void setSprite(Sprite* sprite);
	Sprite* getSprite();
};

