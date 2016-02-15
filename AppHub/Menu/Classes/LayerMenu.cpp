#include "LayerMenu.h"

LayerMenu::LayerMenu()
{
	size = Director::getInstance()->getWinSize();
	tinyxml2::XMLDocument document;
	const std::string path = "Modules.xml";

	// ouvrir le document xml
	if (document.LoadFile(path.c_str()) == tinyxml2::XML_NO_ERROR)
	{
		// on r�cup�re la racine
		tinyxml2::XMLHandle root(&document);
		// on r�cup�re son premier fils. Le handle s�curise la possibilit� d'un r�sultat null.
		tinyxml2::XMLElement* elem = root.FirstChildElement().FirstChildElement().ToElement();

		if (elem)
		{
			Module* module = new Module();

			while (elem)
			{
				// on r�cup�re les infos sur le module
				module->name = elem->Attribute("name");
				module->id = elem->Attribute("id");

				// on les affiche sur notre menu
				printModule(module);

				// iteration
				elem = elem->NextSiblingElement();
			}
		}
	}

	// calcul des coordonn�es du premier sprite
	float reste = size.height - nodes[0]->getContentSize().height / 2 - 
		(size.height / nodes.size() * (nodes.size() - 1)) -
		nodes[0]->getContentSize().height / 2;									// espace qui reste en bas apr�s avoir plac� tous les sprites
	float x = (size.width / 2);														// milieu sur l'axe x
	float y = size.height - nodes[0]->getContentSize().height / 2 - reste / 2;	// position en y du premier sprite

	// it�rateur qui permettra de faire changer y
	int i = 0;

	// boucle d'affichage des sprites boutons
	for each (MySprite* elem in nodes)
	{
		elem->setPosition(x, y - (size.height / nodes.size() * i));
		elem->type = TYPE::BOUTON;
		addChild(elem, 0);
		i++;
	}


	// initialisation des m�thodes �v�nement dans le listener.
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(LayerMenu::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(LayerMenu::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(LayerMenu::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(LayerMenu::onTouchesEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

LayerMenu::~LayerMenu()
{
	// release our sprite and layer so that it gets dealloced
	int i = 0;

	while (this->nodes.empty())
	{
		CC_SAFE_RELEASE_NULL(this->nodes[i]);
		i++;
	}
}



void LayerMenu::printModule(Module* module)
{
	Label* text = Label::createWithTTF(module->name, "fonts/Marker Felt.ttf", 30);
	//auto pinfo = AutoPolygon::generatePolygon("bouton_module.jpg");
	MySprite* sprite = MySprite::create("bouton_module.jpg", TYPE::BOUTON);

	// je d�finie le label
	text->setString(module->name);
	// pour r�cup�rer plus tard l'id du module
	text->setName(module->id);
	text->setColor(Color3B::BLACK);
	text->setPosition(sprite->getContentSize().width / 2
		, sprite->getContentSize().height / 2);

	// j'ajoute les sprites au layer
	sprite->addChild(text, 0);

	// on ajoute le sprite dans la liste
	nodes.push_back(sprite);
}




Point LayerMenu::touchToPoint(Touch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}

bool LayerMenu::isTouchingSprite(Touch* touch)
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



Node* LayerMenu::getTouchingSprite(Touch* touch)
{
	Rect rect;


	for each (auto elem in nodes)
	{
		rect = elem->getBoundingBox();

		if (rect.containsPoint(touchToPoint(touch)))
		{
			return elem;
		}
	}

	return nullptr;
}



void LayerMenu::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
	Node* node;

	for each (auto touch in touches)
	{
		// on v�rifie si la valeur retourn� par getTouchingSprite est diff�rente de null.
		if (node = getTouchingSprite(touch))
		{
			// � v�rifier � la code review !!!!!!
			if ((MySprite*)node)
			{
				MySprite*  sprite = (MySprite*)node;
				if (sprite->type == TYPE::BOUTON)
				{
					// on r�cup�re l'id du module correspondant au sprite
					auto children = sprite->getChildren();						// �tape qui m'�vite une grosse ligne gal�re pour r�cup�rer ma valeur
					Label* label = (Label*)children.at(0);	// �tape qui m'�vite une grosse ligne gal�re pour r�cup�rer ma valeur
					std::string id = label->getName();

					if (id.compare(DOT_LINK) == 0)
					{
						// create a scene. it's an autorelease object
						auto scene = Scene::create();
						// on cr�e le layer du module
						auto layer = new LayerPointAPoint();
						// on cr�e le layer de la toolbar � ajouter poru revenir au menu
						auto menu = new LayerTool();
						// on ajoute les layers � la scene
						scene->addChild(layer, 1);
						scene->addChild(menu, 2);

						// on release nos layers
						layer->release();
						menu->release();

						Director::getInstance()->pushScene(scene);
					}
				}
				else if (sprite->type == TYPE::ANIMATION)
				{
					// cr�ation + lancement de l'animation
				}
			}
		}
	}
}



void LayerMenu::playAnimation(MySprite* sprite, const std::string FILE_NAME, const float IMG_SIZE_X, const float IMG_SIZE_Y, const int NB_FRAME_X, const int NB_FRAME_Y)
{
	const float FRAME_SIZE_X = IMG_SIZE_X / NB_FRAME_X;
	const float FRAME_SIZE_Y = IMG_SIZE_Y / NB_FRAME_Y;

	// le rectangle qu'on s�lectionne dans notre image
	Rect frame_zone;
	// la liste de nos frames
	Vector<SpriteFrame*> animFrames;

	// boucle qui parcours notre image pour la d�couper en frame
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
	// on fini de cr�er l'animation
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	sprite->runAction(animate);
}



void LayerMenu::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{

}

void LayerMenu::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{

}