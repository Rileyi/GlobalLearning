#include "AppDelegate.h"

MyLayer::MyLayer()
{
	Size iSize = Director::getInstance()->getWinSize();

	// crée le sprite de démonstration
	// ces lignes sont à supprimer si vous voulez faire votre propre layer.
	this->sprite = new Sprite;
	this->sprite->initWithFile("Sprite.png");
	this->sprite->setPosition(Point(iSize.width / 2.0f, iSize.height / 2.0f));
	this->sprite->setAnchorPoint(Point(0.5f, 0.55f)); // nudge the anchor point upward because of the shadow
	this->addChild(this->sprite, 2);

	// initialisation des méthodes évènement dans le listener.
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
	CC_SAFE_RELEASE_NULL(this->sprite);
}

Point MyLayer::touchToPoint(Touch* touch)
{
	// convert the touch object to a position in our cocos2d space
	return CCDirector::getInstance()->convertToGL(touch->getLocationInView());
}

bool MyLayer::isTouchingSprite(Touch* touch)
{
	// on compare la distance entre l'endroit où l'utilisateur a cliqué et la position
	// du sprite avec un cercle de rayon 100 histoire d'être "à peu près" dans le sprite.
	return (this->sprite->getPosition().getDistance(this->touchToPoint(touch)) < 100.0f);
}

void MyLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
	// on réinitialise le touch_offset
	this->touch_offset = Point::ZERO;

	for (auto touch : touches)
	{
		// on appelle la method qui vérifie si on est bien dans notre sprite
		if (touch && this->isTouchingSprite(touch))
		{
			// on enregistre la distance entre la position du sprite et le clique du user
			this->touch_offset = this->sprite->getPosition() - this->touchToPoint(touch);
		}
	}
}

void MyLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{
	for (auto touch : touches)
	{
		// on change de position notre sprite en fonction du mouvement de la souris sans oublier le offset.
		if (touch && touch_offset.x && touch_offset.y)
			this->sprite->setPosition(this->touchToPoint(touch) + this->touch_offset);
	}
}

void MyLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{
	for (auto touch : touches)
	{
		if (touch && touch_offset.x && touch_offset.y)
		{
			// on défini la dernière position du sprite. Toujours avec l'offset
			this->sprite->setPosition(this->touchToPoint(touch) + this->touch_offset);

			// on arrête toutes les actions sur le sprite.
			this->sprite->stopAllActions();
			this->sprite->setScale(1.0f);
		}
	}
}
