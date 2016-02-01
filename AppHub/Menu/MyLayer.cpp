#include "AppDelegate.h"

MyLayer::MyLayer()
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
	float reste = size.height - sprites[0]->getContentSize().height / 2 - 
		(size.height / sprites.size() * (sprites.size() - 1)) - 
		sprites[0]->getContentSize().height / 2;									// espace qui reste en bas apr�s avoir plac� tous les sprites
	float x = (size.width / 2);														// milieu sur l'axe x
	float y = size.height - sprites[0]->getContentSize().height / 2 - reste / 2;	// position en y du premier sprite

	// it�rateur qui permettra de faire changer y
	int i = 0;

	// boucle d'affichage des sprites
	for each (cocos2d::Sprite* elem in sprites)
	{
		elem->setPosition(x, y - (size.height / sprites.size() * i));
		addChild(elem, 0);
		i++;
	}

	// initialisation des m�thodes �v�nement dans le listener.
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(MyLayer::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(MyLayer::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(MyLayer::onTouchesEnded, this);
	listener->onTouchesCancelled = CC_CALLBACK_2(MyLayer::onTouchesEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

MyLayer::~MyLayer()
{
	// release our sprite and layer so that it gets dealloced
	int i = 0;

	while (this->sprites.empty())
	{
		CC_SAFE_RELEASE_NULL(this->sprites[i]);
		i++;
	}
}



void MyLayer::printModule(Module* module)
{
	cocos2d::Label* text = Label::create();
	cocos2d::Sprite* sprite = Sprite::create("bouton_module.jpg");

	// je d�finie le label
	text->setString(module->name);
	// pour r�cup�rer plus tard l'id du module
	text->setName(module->id);
	text->setTTFConfig("fonts/Marker Felt.ttf");
	text->setColor(Color3B::BLACK);
	text->setPosition(sprite->getContentSize().width / 2
		, sprite->getContentSize().height / 2);

	// j'ajotueles sprites au layer
	sprite->addChild(text, 0);

	// on ajoute le sprite dans la liste
	sprites.push_back(sprite);
}




Point MyLayer::touchToPoint(Touch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}

bool MyLayer::isTouchingSprite(Touch* touch)
{
	bool b = false;
	int i = 0;
	cocos2d::Rect rect;

	while (!b && i < sprites.size())
	{
		rect = sprites[i]->getBoundingBox();
		b = b || rect.containsPoint(touchToPoint(touch));
		i++;
	}

	return b;
}



cocos2d::Sprite* MyLayer::getTouchingSprite(Touch* touch)
{
	cocos2d::Rect rect;


	for each (auto elem in sprites)
	{
		rect = elem->getBoundingBox();

		if (rect.containsPoint(touchToPoint(touch)))
		{
			return elem;
		}
	}

	return nullptr;
}



void MyLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
	Sprite* sprite;

	for each (auto touch in touches)
	{
		// on v�rifie si la valeur retourn� par getTouchingSprite est diff�rente de null.
		if (sprite = getTouchingSprite(touch))
		{
			// on r�cup�re l'id du module correspondant au sprite
			auto children = sprite->getChildren();						// �tape qui m'�vite une grosse ligne gal�re pour r�cup�rer ma valeur
			cocos2d::Label* label = (cocos2d::Label*)children.at(0);	// �tape qui m'�vite une grosse ligne gal�re pour r�cup�rer ma valeur
			std::string id = label->getName();

			/*
			*	� compl�ter pour lancer le module s�lectionner
			*/
		}
	}
}

void MyLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{

}

void MyLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{

}