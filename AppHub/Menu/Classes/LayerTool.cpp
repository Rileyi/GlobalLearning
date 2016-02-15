#include "LayerTool.h"



LayerTool::LayerTool()
{
	size = Director::getInstance()->getWinSize();

	// création du bouton pour revenir au menu principal
	MySprite* menu = MySprite::create("menu.png", Rect(0, 0, 175, 47), TYPE::MENU);
	menu->setPosition(Vec2(0, size.height));
	menu->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	addChild(menu, 0);
	nodes.push_back(menu);


	// initialisation des méthodes évènement dans le listener.
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(LayerTool::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(LayerTool::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(LayerTool::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(LayerTool::onTouchesEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}


LayerTool::~LayerTool()
{
	// release our sprite and layer so that it gets dealloced
	int i = 0;

	while (this->nodes.empty())
	{
		CC_SAFE_RELEASE_NULL(this->nodes[i]);
		i++;
	}
}



Point LayerTool::touchToPoint(Touch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}


bool LayerTool::isTouchingSprite(Touch* touch)
{
	bool b = false;
	unsigned int i = 0;
	Rect rect;

	while (!b && i < nodes.size())
	{
		rect = nodes[i]->getBoundingBox();
		b = rect.containsPoint(touchToPoint(touch));
		i++;
	}

	return b;
}



Node* LayerTool::getTouchingSprite(Touch* touch)
{
	Rect rect;


	for each (auto elem in nodes)
	{
		rect = elem->getBoundingBox();

		if (rect.containsPoint(touchToPoint(touch)))
		{
			return (MySprite*)elem;
		}
	}

	return nullptr;
}



void LayerTool::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
	Node* node;

	for each (auto touch in touches)
	{
		// on vérifie si la valeur retourné par getTouchingSprite est différente de null.
		if (node = getTouchingSprite(touch))
		{
			// à vérifier à la code review !!!!!!
			if ((MySprite*)node)
			{
				MySprite*  sprite = (MySprite*)node;
				if (sprite->type == TYPE::MENU)
				{
					// create a generic scene
					auto scene = Scene::create();

					// add the layer
					auto layer = new LayerMenu();
					scene->addChild(layer, 1);
					layer->release(); // addChild() retained so we release

					// run the first scene
					Director::getInstance()->pushScene(scene);
				}
				else if (sprite->type == TYPE::ANIMATION)
				{
					// création + lancement de l'animation
				}
			}
		}
	}
}



void LayerTool::playAnimation(MySprite* sprite, const std::string FILE_NAME, const float IMG_SIZE_X, const float IMG_SIZE_Y, const int NB_FRAME_X, const int NB_FRAME_Y)
{
	const float FRAME_SIZE_X = IMG_SIZE_X / NB_FRAME_X;
	const float FRAME_SIZE_Y = IMG_SIZE_Y / NB_FRAME_Y;

	// le rectangle qu'on sélectionne dans notre image
	Rect frame_zone;
	// la liste de nos frames
	Vector<SpriteFrame*> animFrames;

	// boucle qui parcours notre image pour la découper en frame
	for (int i = 0; i < NB_FRAME_Y; i++)
	{
		for (int j = 0; j < NB_FRAME_X; j++)
		{
			frame_zone = Rect(FRAME_SIZE_X * j, FRAME_SIZE_Y * i,
				FRAME_SIZE_X, FRAME_SIZE_Y);

			auto frame = SpriteFrame::create(FILE_NAME, frame_zone);
			animFrames.pushBack(frame);
		}
	}
	// on fini de créer l'animation
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	sprite->runAction(animate);
}



void LayerTool::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{

}

void LayerTool::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{

}