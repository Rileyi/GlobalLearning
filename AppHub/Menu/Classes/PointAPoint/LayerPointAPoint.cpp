#include "LayerPointAPoint.h"




LayerPointAPoint::LayerPointAPoint()
{
	auto dirs = Director::getInstance();
	Size visibleSize = dirs->getVisibleSize();
	//Ajout des éléments graphiques
	auto bg = cocos2d::LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(bg);
	auto label1 = Label::create("Relier les points", "Helvetica", 36);
	label1->setColor(Color3B(0, 0, 0));
	label1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 20));
	this->addChild(label1);
	start_button = new Sprite();
	start_button->initWithFile("Start_button.png");
	start_button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height/2));
	this->addChild(start_button);
	//Ajout évènements
	// initialisation des méthodes évènement dans le listener.
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(LayerPointAPoint::onTouchesBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}



LayerPointAPoint::~LayerPointAPoint()
{
}



void LayerPointAPoint::AffichePoints()
{
	for (int i = 0; i < liste_Points.size(); i++)
	{
		liste_Sprites.push_back(Sprite::create("point.png"));
		liste_Sprites[i]->setPosition(liste_Points[i]->getX(), liste_Points[i]->getY());
		liste_Sprites[i]->setTag(i);
		liste_Labels.push_back(Label::create(etiquette(1, i), "Helvetica", 10));
		liste_Labels[i]->setColor(Color3B(0, 0, 0));
		liste_Labels[i]->setPosition(liste_Points[i]->getX(), liste_Points[i]->getY()-10);
		this->addChild(liste_Labels[i]);
		this->addChild(liste_Sprites[i]);
	}
}

void LayerPointAPoint::LoadPoints()
{
	liste_Points.push_back(new PointGame(100, 100, 1));
	liste_Points.push_back(new PointGame(275, 234, 2));
	liste_Points.push_back(new PointGame(450, 790, 3));
}

void LayerPointAPoint::RelierPoints(int p1, int p2)
{
	Vec2 coo1 =  Vec2(liste_Points[p1]->getX(), liste_Points[p1]->getY());
	Vec2 coo2 = Vec2(liste_Points[p2]->getX(), liste_Points[p2]->getY());

	CCDrawNode* node = CCDrawNode::create();
	addChild(node, 10);//Make sure your z-order is large enough
	node->drawSegment(coo1, coo2, 5.0, ccc4f(180, 180, 180, 100));
}


Point LayerPointAPoint::touchToPoint(Touch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}

bool LayerPointAPoint::isTouchingSprite(Touch* touch, Sprite* Sprite_test)
{
	// on compare la distance entre l'endroit où l'utilisateur a cliqué et la position
	// du sprite avec un cercle de rayon 100 histoire d'être "à peu près" dans le sprite.
	return (Sprite_test->getPosition().getDistance(this->touchToPoint(touch)) < 100.0f);
}
void LayerPointAPoint::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
	// on réinitialise le touch_offset
	this->touch_offset = Point::ZERO;

	for (auto touch : touches)
	{
		// on appelle la method qui vérifie si on est bien dans notre sprite
		if (touch && this->isTouchingSprite(touch, start_button))
		{
			start_button->removeFromParent();
			this->LoadPoints();
			this->AffichePoints();
		}
		else
		{
			for (int i = 0; i < liste_Sprites.size(); i++)
			{
				if ((touch && this->isTouchingSprite(touch, liste_Sprites[i])))
				{
					if (liste_Sprites[i]->getTag() - 1 == save_last_sprite_tag)
					{
						this->RelierPoints(liste_Sprites[i]->getTag(), save_last_sprite_tag);
					}
					save_last_sprite_tag = liste_Sprites[i]->getTag();
				}
			}
		}
	}
}

std::string LayerPointAPoint::etiquette(int type, int id) //type 0 : Entier, type 1 : Alphabet, type 2 : Arithmètique 
{
	std::ostringstream oss, oss1;
	std::string  alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string temp= "";
	srand(time(NULL)); // initialisation de rand
	char c= 'A';

	int a, b, signe;
	switch (type)
	{
	case  0:

		oss << id;
		return oss.str();
		break;
	case 1:
		temp = c+id;
		return temp;
	case 2:
		if (id == 0)
		{
			oss << id;
			return oss.str();
		}
		a = rand() % 100;
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
