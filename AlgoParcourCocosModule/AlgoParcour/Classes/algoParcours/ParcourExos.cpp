#include "ParcourExos.h"
#define COCOS2D_DEBUG 1

USING_NS_CC;



ParcourExos* ParcourExos::createParcourExos(int longueur, int largeur, int reading, int writing, int math, int fun)
{
	ParcourExos* graph = ParcourExos::create();

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchMoved = CC_CALLBACK_2(ParcourExos::onTouchMoved, graph);
	listener->onTouchBegan = CC_CALLBACK_2(ParcourExos::onTouchBegan, graph);

	dispatcher->addEventListenerWithSceneGraphPriority(listener, graph);

	graph->list = generateGraph(longueur, largeur, reading, writing, math, fun);
	do {
		graph->initPrintGraph(graph->list->getNodes());
	} while (!graph->list->isValid());

	graph->linkGraph(graph->list->getNodes());

	return graph;
}



bool ParcourExos::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	pos_click = touch->getLocation();

	return true;
}


void ParcourExos::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	Vec2 new_pos = Vec2(getPosition().x + touch->getLocation().x - pos_click.x, getPosition().y + touch->getLocation().y - pos_click.y);

	if ((getPosition().x >= -1920/2 && getPosition().x <= 0) || (new_pos.x >= -1920/2 && new_pos.x <= 0))
	{
		setPositionX(getPosition().x + touch->getLocation().x - pos_click.x);
		pos_click.x = touch->getLocation().x;
	}
	if ((getPosition().y >= -1240/2 && getPosition().y <= 0) || (new_pos.y >= -1240/2 && new_pos.y <= 0))
	{
		setPositionY(getPosition().y + touch->getLocation().y - pos_click.y);
		pos_click.y = touch->getLocation().y;
	}
}




void ParcourExos::initPrintGraph(std::vector<std::list<ModuleNode*>>* graph)
{
	Rect area = Rect::Rect(0, 0, 1920, 1280);
	auto list = *graph;
	const float ECART_X = (area.getMaxX() - area.getMinX()) / (list.size() + 1);
	int i = 1;

	for (auto column : list)
	{
		const float ECART_Y = (area.getMaxY() - area.getMinY()) / (column.size() + 1);
		int j = 1;

		for (auto elem : column)
		{
			elem->setPosition(Vec2(ECART_X * i + area.getMinX(), ECART_Y * j + area.getMinY()));
			//if ((i != 1 || j != 1) && (i != list.size() || j != column.size()))
			addSpriteToModule(elem);
			//else
			//	elem->addChild(Sprite::create("res/boutons/Button Icon rocket.png"));
			addChild(elem, 1);
			j++;
		}
		i++;
	}
}


void ParcourExos::addSpriteToModule(ModuleNode* module)
{
	tinyxml2::XMLDocument document;
	const std::string XML_DOC = "res/algoParcours/list_exercises.xml";
	const std::string EXT = ".png";
	const std::string BIS = " ON";
	const std::string SOCLE = "res/algoParcours/Icon background.png";
	const std::string NAME = module->getModuleName();
	
	// ouvrir le document xml
	if (document.LoadFile(XML_DOC.c_str()) == tinyxml2::XML_NO_ERROR)
	{
		// on récupère la racine
		tinyxml2::XMLHandle root(&document);
		// on récupère son premier fils. Le handle sécurise la possibilité d'un résultat null.
		tinyxml2::XMLElement* elem = root.FirstChildElement().FirstChildElement().ToElement();

		if (elem)
		{
			while (elem && (NAME.compare(elem->Attribute("name")) != 0))
			{
				// iteration
				elem = elem->NextSiblingElement();
			}
			if (elem)
			{
				// on ajoute les images à notre bouton
				if (NAME.compare("depart") != 0 && NAME.compare("arrivee") != 0)
				{
					Sprite* sprite = Sprite::create(SOCLE);
					module->addChild(sprite, 0);
					cocos2d::ui::Button* button = cocos2d::ui::Button::create();
					button->loadTextureNormal(elem->Attribute("img") + EXT);
					button->loadTexturePressed(elem->Attribute("img") + BIS + EXT);
					button->loadTextureDisabled(elem->Attribute("img") + BIS + EXT);
					module->addChild(button, 1);
				}
				else
				{
					cocos2d::ui::Button* button = cocos2d::ui::Button::create();
					button->loadTextureNormal(elem->Attribute("img") + EXT);
					button->loadTextureDisabled(elem->Attribute("img") + EXT);
					button->setEnabled(false);
					module->addChild(button, 1);
				}
			}
		}
	}
}


void ParcourExos::linkGraph(std::vector<std::list<ModuleNode*>>* graph)
{
	Rect area = Rect::Rect(0, 0, 960, 640);
	auto list = *graph;
	const float ECART_X = (area.getMaxX() - area.getMinX()) / (list.size() + 1);
	int i = 1;

	for (auto column : list)
	{
		const float ECART_Y = (area.getMaxY() - area.getMinY()) / (column.size() + 1);
		int j = 1;

		for (auto elem : column)
		{
			auto childs = *(elem->getNext());

			for (auto child : childs)
			{
				linkModule(elem, child);
			}
		}
		i++;
	}
}


void ParcourExos::linkModule(Node* module1, Node* module2)
{
	Vec2 loc1 = module1->getPosition();
	Vec2 loc2 = module2->getPosition();

	const std::string RESSOURCE = "res/algoParcours/dot.png";
	const int NB_POINTS = 10000;
	float a = (loc1.y - loc2.y) / 2;
	float y = loc2.x - loc1.x;
	float iterator = y / (float)NB_POINTS;
	DrawNode* dot = DrawNode::create();
	int i = 0;

	for (float x = -5; x < (5 - iterator); x += iterator)
	{
		/*dot->drawSegment(Vec2((loc1.x - loc2.x) / 2 + loc2.x + (x * y / 10), (loc1.y - loc2.y) / 2 + loc2.y - a * tanh(x)),
			Vec2((loc1.x - loc2.x) / 2 + loc2.x + ((x + iterator) * y / 10), (loc1.y - loc2.y) / 2 + loc2.y - a * tanh((x + iterator))), 3, Color4F::YELLOW);*/
		Sprite* rect = Sprite::create(RESSOURCE);
		rect->setPosition(Vec2((loc1.x - loc2.x) / 2 + loc2.x + (x * y / 10), (loc1.y - loc2.y) / 2 + loc2.y - a * tanh(x)));
		//rect->setRotation3D(Vec3(0, 0, (360 / (2 * M_PI)) * atan(1 - tanh(x))));
		rect->setRotation((360 / (2 * M_PI)) * atan(a - a * tanh(x)));
		dot->addChild(rect, 0);
		i++;
	}
	addChild(dot, 0);
}