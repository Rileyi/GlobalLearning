#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ToolBarReader.h"
#include "ToolBar.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	// récupérer la taille de l'écran
	size = Director::getInstance()->getWinSize();
	size.height -= 86;

	// Register the readers for our custom classes
	CSLoader* instance = CSLoader::getInstance();
	instance->registReaderObject("ToolBarReader", (ObjectFactory::Instance) ToolBarReader::getInstance);


    rootNode = CSLoader::createNode("MainScene.csb");

	// créer les boutons
	cocos2d::ui::Button* playButton = rootNode->getChildByName<cocos2d::ui::Button*>("Play_button");
	cocos2d::ui::Button* quitButton = rootNode->getChildByName<cocos2d::ui::Button*>("Exit_button");
	cocos2d::ui::Button* shahootsButton = rootNode->getChildByName<cocos2d::ui::Button*>("Shahoots_button");

	// on ajoute les methods à exécuter en cas de clique sur un bouton
	playButton->addTouchEventListener(CC_CALLBACK_2(MainScene::play, this));
	quitButton->addTouchEventListener(CC_CALLBACK_2(MainScene::quit, this));
	shahootsButton->addTouchEventListener(CC_CALLBACK_2(MainScene::shahootsPop, this));

	// on met l'event sur shahoots
	cocos2d::ui::Button* mascotte_button = (cocos2d::ui::Button*)rootNode->getChildByName("Mascotte")->getChildByName("Button");
	mascotte_button->addTouchEventListener(CC_CALLBACK_2(MainScene::shahootsAie, this));

	// on ajoute les évènements au layer
	tool_bar = (ToolBar*)rootNode->getChildByName("Tool_bar");
	tool_bar->setLocalZOrder(2);
	cocos2d::ui::Button* vision_graph = tool_bar->getChildByName<cocos2d::ui::Button*>("Vision_graph");
	cocos2d::ui::Button* menu = tool_bar->getChildByName<cocos2d::ui::Button*>("Menu_button");
	cocos2d::ui::Button* valid = tool_bar->getChildByName<cocos2d::ui::Button*>("Valid_button");
	cocos2d::ui::Button* shahoots = tool_bar->getChildByName<cocos2d::ui::Button*>("Shahoots_button");


	// on crée le parcour l'exercice.
	graph = ParcourExos::createParcourExos(10, 5, 550, 550, 550, 550);
	graph->setVisible(false);

	// on ajoute les évènements aux boutons de la tool_bar
	shahoots->addTouchEventListener(CC_CALLBACK_2(MainScene::shahootsPop, this));
	menu->addTouchEventListener(CC_CALLBACK_2(MainScene::goToMenu, this));
	vision_graph->addTouchEventListener(CC_CALLBACK_2(MainScene::changeDisplayModule, this));

	rootNode->addChild(graph, 1);
    addChild(rootNode);

    return true;
}


void MainScene::buttonAppeared()
{
	cocostudio::timeline::ActionTimeline* buttonTimeline = CSLoader::createTimeline("MainScene.csb");
	stopAllActions();
	runAction(buttonTimeline);
	buttonTimeline->play("button_appeared", false);
}


void MainScene::runToolBar(bool b)
{
	cocostudio::timeline::ActionTimeline* buttonTimeline = CSLoader::createTimeline("ToolBar.csb");
	//stopAllActions();
	runAction(buttonTimeline);

	if (b)
	{
		buttonTimeline->play("other_to_menu", false);
		tool_bar->getChildByName<cocos2d::ui::Button*>("Menu_button")->setEnabled(!b);
	}
	else
	{
		buttonTimeline->play("menu_to_other", false);
		tool_bar->getChildByName<cocos2d::ui::Button*>("Menu_button")->setEnabled(!b);
	}
}


void MainScene::onEnter()
{
	Layer::onEnter();

	// on gère la musique
	//CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("music_background.wav", true);
	// set the 'background music' volume level (from 0 to 1)
	//CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.1);

	buttonAppeared();
	runToolBar(true);
	scheduleUpdate();
}



void MainScene::changeDisplayModule(Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		if (graph->isVisible())
		{
			graph->setVisible(false);
			for (auto elem : list)
			{
				elem->setVisible(true);
			}
		}
		else
		{
			graph->setVisible(true);
			for (auto elem : list)
			{
				elem->setVisible(false);
			}
		}
	}
}



void MainScene::goToMenu(Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		// create a scene. it's an autorelease object
		auto scene = MainScene::createScene();

		// run
		Director::getInstance()->pushScene(scene);
	}
}

void MainScene::shahootsAie(Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		count_shahoots++;

		if (count_shahoots != 5)
		{
			return;
		}

		cocostudio::timeline::ActionTimeline* buttonTimeline = CSLoader::createTimeline("Mascotte.csb");
		stopAllActions();
		runAction(buttonTimeline);
		buttonTimeline->play("Aie", false);
	}
}

void MainScene::shahootsPop(Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		Node* shahoots = rootNode->getChildByName("Mascotte");

		shahoots->setVisible(!(shahoots->isVisible()));
		shahoots->getChildByName("Text")->setVisible(true);
		shahoots->getChildByName("Text_aie")->setVisible(false);
		count_shahoots = 0;
	}
}

void MainScene::play(Ref* pSender, ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		cocostudio::timeline::ActionTimeline* buttonTimeline = CSLoader::createTimeline("MainScene.csb");
		// on attend la fin de l'animation avant de lancer la création du screen select
		buttonTimeline->setLastFrameCallFunc([this]()
		{
			this->createSelectScreen();
			rootNode->getChildByName("Tool_bar")->setVisible(true);
			runToolBar(false);
		});

		stopAllActions();
		runAction(buttonTimeline);
		buttonTimeline->play("button_left", false);

		//createSelectScreen();
	}
}

void MainScene::quit(Ref* pSender, ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		CCDirector::getInstance()->end();
		exit(0);
	}
}



void MainScene::createSelectScreen()
{
	tinyxml2::XMLDocument document;
	const std::string MODULE = "res/Modules.xml";
	const std::string EXT = ".png";
	const std::string BIS = " ON";
	const std::string PATH = "res/boutons/";

	// ouvrir le document xml
	if (document.LoadFile(MODULE.c_str()) == tinyxml2::XML_NO_ERROR)
	{
		// on récupère la racine
		tinyxml2::XMLHandle root(&document);
		// on récupère son premier fils. Le handle sécurise la possibilité d'un résultat null.
		tinyxml2::XMLElement* elem = root.FirstChildElement().FirstChildElement().ToElement();

		if (elem)
		{
			while (elem)
			{
				ButtonModule* module = (ButtonModule*)(CSLoader::createNode("ButtonModule.csb"));

				//module->getButton()->setTitleText(elem->Attribute("name"));
				//module->setId = elem->Attribute("id");

				// on défini les différentes images de notre bouton
				module->getButton()->loadTextureNormal(PATH + elem->Attribute("img") + EXT);
				module->getButton()->loadTexturePressed(PATH + elem->Attribute("img") + BIS + EXT);
				module->getButton()->loadTextureDisabled(PATH + elem->Attribute("img") + BIS + EXT);

				// on les ajoute à une liste
				list.push_back(module);

				// iteration
				elem = elem->NextSiblingElement();
			}
		}
	}

	// calcul des coordonnées du premier sprite
	float reste = size.height - list[0]->getContentSize().height / 2 -
		(size.height / list.size() * (list.size() - 1)) -
		list[0]->getContentSize().height / 2;									// espace qui reste en bas après avoir placé tous les sprites
	float x = (size.width / 2);													// milieu sur l'axe x
	float y = size.height - list[0]->getContentSize().height / 2 - reste / 2;	// position en y du premier sprite

	// boucle d'affichage des sprites boutons
	/*for each (auto elem in list)
	{
		elem->setPosition(x, y - (size.height / list.size() * i));
		addChild(elem, 0);
		i++;
	}*/
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->setPosition(x, y - (size.height / list.size() * i));
		addChild(list[i], 0);
	}
}