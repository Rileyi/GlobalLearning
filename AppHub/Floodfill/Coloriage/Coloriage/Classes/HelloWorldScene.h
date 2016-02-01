#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <GL/gl.h>
#include <GL/glu.h>

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

struct GLPoint {
	GLint x;
	GLint y;
};

bool operator==(GLPoint const& a, GLPoint const& b);



class HelloWorld : public cocos2d::Layer
{

private:

	cocos2d::Sprite* background;
	cocos2d::Size windowSize;
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;
	GLuint vertexbuffer;

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	Color getPixelColor(GLint x, GLint y);
	void setPixelColor(GLint x, GLint y, Color color);
	void floodFill(GLint x, GLint y, Color oldColor, Color newColor);

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);

};



#endif // __HELLOWORLD_SCENE_H__
