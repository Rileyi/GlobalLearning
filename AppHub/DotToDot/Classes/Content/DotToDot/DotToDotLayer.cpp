#include "DotToDotLayer.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Exception.h"
#include "Color.h"

USING_NS_CC;
using namespace cocostudio::timeline;

/*Scene* DotToDotLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = DotToDotLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}*/

// on "init" you need to initialize your instance
bool DotToDotLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
   _rootNode = CSLoader::createNode("DotToDot.csb");
   _drawingNode = CCDrawNode::create();

   cocos2d::log("debug2");


	Size size = Director::getInstance()->getVisibleSize();
	_rootNode->setContentSize(size);
	ui::Helper::doLayout(_rootNode);

	_gameState = GameState::Menu;



	//Add button
	
	 _buttonGame = _rootNode->getChildByName<cocos2d::ui::Button*>("buttonGame");
	 _buttonTutorial = _rootNode->getChildByName<cocos2d::ui::Button*>("buttonTutorial");
	
	_buttonGame->addTouchEventListener(CC_CALLBACK_2(DotToDotLayer::game, this));
	_buttonTutorial->addTouchEventListener(CC_CALLBACK_2(DotToDotLayer::tutorial, this));
    
	
	addChild(_rootNode);

    return true;
}


void DotToDotLayer::game(Ref* pSender, ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		_buttonGame->setVisible(false);
		_buttonTutorial->setVisible(false);
		_gameState = GameState::Playing;
		_numberOfError = 0;
		displayDots();
		_lastSpriteLinked = 0;
		setupTouchHandling();
	}

}


void DotToDotLayer::pushDot(Dot dot)
{
	_dotsList.push_back(dot);
}



void DotToDotLayer::tutorial(Ref* pSender, ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		_buttonGame->setVisible(false);
		_buttonTutorial->setVisible(false);
		_rootNode->getChildByName("tutorialNode")->setVisible(true);

		_gameState = GameState::Tutorial;
		cocostudio::timeline::ActionTimeline* tutorial = CSLoader::createTimeline("TutorialNode.csb");
		stopAllActions();
		runAction(tutorial);
		tutorial->play("tutorial1", false);
	}
}

void DotToDotLayer::displayDots()
{

	if (_dotsList.empty() )
	{
		throw Exception(Exception::Type::Game, "No Dots find");
	}
	//first Sprite is linked

	Sprite* sprite = Sprite::create("dot-to-dot-button linked.png");
	sprite->setPosition(Vec2(_dotsList[0].getX(), _dotsList[0].getY()));
	_dotsList[0].setSprite(sprite);
	_rootNode->addChild(sprite, 1);

	Label* label = Label::create(etiquette(0, _dotsList[0].getNumber()), "Chalkboard", 30);
	label->setColor(Color3B(255, 255, 255));
	label->setPosition(_dotsList[0].getX(), _dotsList[0].getY() + 50);
	_rootNode->addChild(label);

	_rootNode->getCameraMask();
	// others are unlinked
	for (int i = 1; i < _dotsList.size(); i++)
	{
		
		Sprite* sprite = Sprite::create("dot-to-dot-button unlinked.png");
		sprite->setPosition(Vec2(_dotsList[i].getX(), _dotsList[i].getY()));
		_dotsList[i].setSprite(sprite);
		_rootNode->addChild(sprite,1);
		
		Label* label = Label::create(etiquette(0, _dotsList[i].getNumber()), "Chalkboard", 30);
		label->setColor(Color3B(255, 255, 255));
		label->setPosition(_dotsList[i].getX(), _dotsList[i].getY() + 50);
		_rootNode->addChild(label,1);
	}

	this->addChild(_rootNode);
}


void DotToDotLayer::setupTouchHandling()
{
	auto touchListener = EventListenerTouchOneByOne::create();
	

	touchListener->onTouchBegan = [&](Touch* touch, Event* event)
	{
		for (int i = 0; i < _dotsList.size(); i++)
		{
			if (touch &&  isTouchingSprite(touch, _dotsList[i].getSprite()))
			{
				_origin = Vec2(_dotsList[i].getX(), _dotsList[i].getY());
				_node = CCDrawNode::create();
				_rootNode->addChild(_node,0);
				_lastSpriteTouched = _dotsList[i].getNumber();
				return true;
			}
		}
		return false;
	};

	touchListener->onTouchMoved = [&](Touch* touch, Event* event)
	{
		_node->clear();
		_destination = touch->getLocation();
		drawLine(_origin, _destination);
	};

	touchListener->onTouchEnded = [&](Touch* touch, Event* event)
	{
		_node->clear();
		for (int i = 0; i < _dotsList.size(); i++)
		{
			if ((touch && isTouchingSprite(touch, _dotsList[i].getSprite())))
			{
				
				cocos2d::log("%d", _lastSpriteTouched);
				cocos2d::log("%d", _dotsList[i].getNumber() - 1);
				cocos2d::log("%d /n", _lastSpriteLinked);



				if ((_dotsList[i].getNumber() - 1 == _lastSpriteLinked) && (_lastSpriteTouched == _lastSpriteLinked))
				{
					
					_dotsList[i].getSprite()->removeFromParent();
					//Change sprite to linked 
					Sprite* sprite = Sprite::create("dot-to-dot-button linked.png");
					sprite->setPosition(Vec2(_dotsList[i].getX(), _dotsList[i].getY()));
					_dotsList[i].setSprite(sprite);
					_rootNode->addChild(sprite,1);
					//Draw the line
					_destination = Vec2(_dotsList[i].getX(), _dotsList[i].getY());
					drawLine(_origin, _destination);
					_lastSpriteLinked = _dotsList[i].getNumber();

					if (i == _dotsList.size()-1) //So game is finished
					{
						finisshPlaying(_origin, _destination, _dotsList[i] );
					}
				}
				else
				{
					_numberOfError++;
				}
			}			
		}
	};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void DotToDotLayer::finisshPlaying(Vec2 origin, Vec2 destination, Dot &dot)
{

	_gameState = GameState::FinishedDrawing;

	origin = destination;
	destination = Vec2(_dotsList[0].getX(), _dotsList[0].getY());

	dot.getSprite()->removeFromParent();
	Sprite* sprite = Sprite::create("dot-to-dot-button linked.png");
	sprite->setPosition(Vec2(dot.getX(), dot.getY()));
	dot.setSprite(sprite);
	_rootNode->addChild(sprite, 1);
	drawLine(origin, destination);

}


bool DotToDotLayer::isTouchingSprite(const Touch* touch, Sprite* Sprite_test)
{
	// on compare la distance entre l'endroit où l'utilisateur a cliqué et la position
	// du sprite avec un cercle de rayon 1 histoire d'être "à peu près" dans le sprite.
	return (Sprite_test->getPosition().getDistance(touchToPoint(touch)) < 40.0f);
}

Point DotToDotLayer::touchToPoint(const Touch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}

void DotToDotLayer::drawLine(Vec2 origin, Vec2 destination)
{
	_node->drawSegment(origin, destination, 8, Color(255, 255, 255, 0.1f));
	_node->drawSegment(origin, destination, 7, Color(253, 252, 225, 0.2f));
	_node->drawSegment(origin, destination, 6, Color(250, 249, 195, 0.5f));
	_node->drawSegment(origin, destination, 5, Color(250, 246, 165, 0.6f));
	_node->drawSegment(origin, destination, 4, Color(250, 243, 135, 0.7f));
	_node->drawSegment(origin, destination, 3, Color(246, 237, 101, 1.0f));
}





std::string DotToDotLayer::etiquette(int type, int id) //type 0 : Entier, type 1 : Alphabet, type 2 : Arithmètique 
{
	std::ostringstream oss, oss1;
	std::string temp = "";
	srand(time(NULL)); // initialisation de rand
	char c = 'A';

	int a, b, signe;
	switch (type)
	{
	case  0:

		oss << id;
		return oss.str();
		break;
	case 1:
		temp = c + id;
		return temp;
	case 2:
		if (id == 0)
		{
			oss << id;
			return oss.str();
		}
		a = rand() % 9;
		signe = rand() % 1; // 0 : addition, 1 : soustraction, possibilité 2 : division et 3 multiplication
		if (signe == 0)
		{
			b = id - a;
			oss << a;
			oss1 << abs(b);
			temp = oss.str() + " - " + oss1.str();
		}
		else
		{
			b = id + a;
			oss << a;
			oss1 << abs(b);
			temp = oss.str() + " + " + oss1.str();
		}

		return temp;
	default:
		break;
	}
}

