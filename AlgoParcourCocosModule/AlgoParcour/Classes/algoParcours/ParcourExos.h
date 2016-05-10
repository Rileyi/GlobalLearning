#ifndef __PARCOUR_EXOS_H__
#define __PARCOUR_EXOS_H__

#include "cocos2d.h"
#include "../algoParcours/AlgoParcour.h"
#include "tinyxml2.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <cmath>


/*****************************************************************************************************
** Pour créer graphiquement un parcours, il faut utiliser la méthode ParcourExos::createParcourExos.**
**																									**
** Cette méthode a pour paramètre :																	**
**	-int longueur	:	nombre d'exercice entre le début et la fin du parcours (le premier et le	**
** dernier noeud étant des noeuds sans exercice, ils ne comptent pas)								**
**	-int largeur	:	le nombre de chemin différent maximum (on aura au plus <largeur> chemin		**
** possible, mais il peut y en avoir moins)															**
**	-int reading	:	la quantité de point en reading												**
**	-int writing	:	la quantité de point en writing												**
**	-int math		:	la quantité de point en math												**
**	-int fun		:	la quantité de point en fun													**
**																									**
** par exemple :																					**
**																									**
** ParcourExos::createParcourExos(10, 5, 550, 550, 550, 550);										**
**																									**
** On crée un parcours de 10 exercice, avec au plus 5 chemins et 550 points dans chaque catégorie.	**
**																									**
** La method retourne une valeur de type ParcourExos* qui dérive du type Node.						**
** Vous avez donc juste à ajouter cet objet comme un Node à votre layer et le tour est joué !		**
*****************************************************************************************************/

class ParcourExos : public cocos2d::Node
{
public:
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
