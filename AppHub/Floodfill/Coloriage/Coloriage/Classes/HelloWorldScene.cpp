#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
	
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	origin     = Director::getInstance()->getVisibleOrigin();
	visibleSize = Director::getInstance()->getVisibleSize();
	windowSize = Director::getInstance()->getWinSize();
    
	background = Sprite::create("image.jpg");
	background->setPosition({ windowSize.width / 2, windowSize.height / 2 });
	background->setAnchorPoint({ 0.5,0.5 });

    this->addChild(background);

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
	// Generate 1 buffer, put the resulting identifier in vertexbuffer

	//glGenBuffers(1, &vertexbuffer);

	// The following commands will talk about our 'vertexbuffer' buffer
	//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	
/*
static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};
*/
	// Give our vertices to OpenGL.
	//glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    return true;
}


Color HelloWorld::getPixelColor(GLint x, GLint y) {

	Color color;
	float pixels[3];
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, pixels);
	color.r = pixels[0];
	color.g = pixels[1];
	color.b = pixels[2];

	return color;
}

void HelloWorld::setPixelColor(GLint x, GLint y, Color color) {

	cocos2d::log("Setting pixel color");

	float pixels[3];
	pixels[0] = color.r;
	pixels[1] = color.g;
	pixels[2] = color.b;



	//glEnableVertexAttribArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	/*
	auto* texture = RenderTexture::create(windowSize.width, windowSize.height);
	
	texture->begin();
	glRasterPos2i(x, y);
	glDrawPixels(windowSize.width, windowSize.height, GL_RGB, GL_FLOAT, pixels);
	texture->end();

	auto sprite = Sprite::create();
	sprite->initWithTexture(texture->getSprite()->getTexture());
	addChild(sprite);
	*/

	/*glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glRasterPos2i(x, y);
	glEnd();
	glFlush();
	*/

	/*
	//glRasterPos2i(x, y);
	//glDrawPixels(1, 1, GL_RGB, GL_FLOAT, pixels);
	*/

	//glDisableVertexAttribArray(0);
}

void HelloWorld::floodFill(GLint x, GLint y, Color oldColor, Color newColor)
{
	Color color;

	DrawNode* node = DrawNode::create();
	Color4F* colorToPrint = new Color4F (newColor.r, newColor.g, newColor.b, 1.0f);
	node->setContentSize(visibleSize);
	node->setPosition(Vec2::ZERO);
	node->setAnchorPoint(Vec2::ZERO);
	
	this->addChild(node);

	int w = Director::getInstance()->getVisibleSize().width;
	int h = Director::getInstance()->getVisibleSize().height;

	cocos2d::log("Floodfill begins");

	if (x < 0 || y < 0 || x > windowSize.width || y >  windowSize.height)
	{
		cocos2d::log("Out of bounds");
		return;
	}

	std::stack<GLPoint> stack;
	GLPoint clickedPoint = { x, y };
	stack.push(clickedPoint);

	// just for test.
	std::vector<GLPoint> evaluated;
	while (!stack.empty())
	{
		GLPoint point = stack.top();
		stack.pop();
		if (point.x < 0 || point.y < 0 || point.x > windowSize.width || point.y >  windowSize.height)
			continue;

		bool test = false;

		// temporary for test
		for (std::vector<GLPoint>::iterator itr = evaluated.end(); itr > evaluated.begin();itr--)
		{
			if (point == *itr)
			{
				test = true;
				break;
			}
		}
		color = getPixelColor(point.x, point.y);

		if (color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b && test != true)
		{

			cocos2d::log("Non evaluated white pixel");

			cocos2d::Vec2 pos;
			pos.x = point.x;
			pos.y = point.y;
			node->drawDot(pos, 1, *colorToPrint);

			stack.push({ point.x + 1, point.y });
			stack.push({ point.x - 1, point.y });
			stack.push({ point.x , point.y + 1 });
			stack.push({ point.x, point.y - 1});

			evaluated.push_back(point);
		}
		// temporary for test
		else if (test == true)
		{
			cocos2d::log("Already evaluated");
		}
		else
		{
			cocos2d::log("Black pixel");
		}
		test = false;
	}
	cocos2d::log("End of Floodfill");
}

/* HIGH RISK OF STACK OVERFLOW
void HelloWorld::floodFill(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	cocos2d::log("YAY");
	if (x < 0 || y < 0 || x > Director::getInstance()->getVisibleSize().width || y > Director::getInstance()->getVisibleSize().height)
	{

		cocos2d::log("Wololo");
		return;
	}
	if (color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		cocos2d::log("lolz");
		setPixelColor(x, y, newColor);
		floodFill(x + 1, y, oldColor, newColor);
		floodFill(x, y + 1, oldColor, newColor);
		floodFill(x - 1, y, oldColor, newColor);
		floodFill(x, y - 1, oldColor, newColor);
	}
	else
	{
		cocos2d::log("snif");
	}
	return;
}
*/


bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	cocos2d::Vec2 touchPosition = touch->getLocation();
	touchPosition = Director::getInstance()->convertToGL(touchPosition);

	Color whiteColor = { 1.0f, 1.0f, 1.0f };
	Color newColorTest = { 1.0f, 0.0f, 0.0f };
	
	floodFill(touchPosition.x, touchPosition.y, whiteColor, newColorTest);

	return true;
}


bool operator==(GLPoint const& a, GLPoint const& b)
{
	if (a.x == b.x && a.y == b.y) 
	{
		return true;
	}
	else
	{ 
		return false;
	}
}