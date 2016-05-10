#ifndef __PARCOUR_EXOS_H__
#define __PARCOUR_EXOS_H__

#include "cocos2d.h"
#include "../algoParcours/AlgoParcour.h"
#include "tinyxml2.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include <cmath>


/*****************************************************************************************************
** Pour cr�er graphiquement un parcours, il faut utiliser la m�thode ParcourExos::createParcourExos.**
**																									**
** Cette m�thode a pour param�tre :																	**
**	-int longueur	:	nombre d'exercice entre le d�but et la fin du parcours (le premier et le	**
** dernier noeud �tant des noeuds sans exercice, ils ne comptent pas)								**
**	-int largeur	:	le nombre de chemin diff�rent maximum (on aura au plus <largeur> chemin		**
** possible, mais il peut y en avoir moins)															**
**	-int reading	:	la quantit� de point en reading												**
**	-int writing	:	la quantit� de point en writing												**
**	-int math		:	la quantit� de point en math												**
**	-int fun		:	la quantit� de point en fun													**
**																									**
** par exemple :																					**
**																									**
** ParcourExos::createParcourExos(10, 5, 550, 550, 550, 550);										**
**																									**
** On cr�e un parcours de 10 exercice, avec au plus 5 chemins et 550 points dans chaque cat�gorie.	**
**																									**
** La method retourne une valeur de type ParcourExos* qui d�rive du type Node.						**
** Vous avez donc juste � ajouter cet objet comme un Node � votre layer et le tour est jou� !		**
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
