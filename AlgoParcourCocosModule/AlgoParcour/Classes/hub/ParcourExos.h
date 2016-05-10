#ifndef __PARCOUR_EXOS_H__
#define __PARCOUR_EXOS_H__

#include "cocos2d.h"
#include "../algoParcours/AlgoParcour.h"
#include "tinyxml2.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <cmath>

class ParcourExos : public cocos2d::Node
{
public:
	// seul et unique method � lancer pour cr�er un graph
	static ParcourExos* createParcourExos(int longueur, int largeur, int reading, int writing, int math, int fun);


private:
	void initPrintGraph(std::vector<std::list<ModuleNode*>>*);
	void linkGraph(std::vector<std::list<ModuleNode*>>*);
	void linkModule(Node* module1, Node* module2);

	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void addSpriteToModule(ModuleNode* node);

	// implement the "static create()" method manually
	CREATE_FUNC(ParcourExos);

	cocos2d::Vec2 pos_click;

	UsableGraph* list;
};

#endif // __HELLOWORLD_SCENE_H__
