========================================================================
    APPLICATION CONSOLE : Vue d'ensemble du projet AlgoParcour
========================================================================

UsableGraph* generateGraph(int length, int width, int reading, int writing, int maths, int fun) genere le graphe.

La classe UsableGraph contient (entre autres) les methodes suivantes :

- bool isValid() const
	Revoie true si le graphe est correctement forme.
	Appelez cette methode apres la generation du graphe et avant de tenter de l'utiliser, comme ceci par exemple :
	
	UsableGraph* graph generateGraph(8 , 4, 200, 200, 200, 200);
	if (graph != nullptr  &&  graph->isValid())
	{
		//Utilisation du graph
	}
	
	Vous pouvez aussi utiliser "std::string getErrors() const" qui renvoie un catalogue de toutes les erreur detectees si vous voulez faire du cas par cas
	
- int getLength() const
- unsigned int getWidth() const

- diverse fonction pour utiliser un noeud courant:
	const ModuleNode* getCurrentNode() const {return m_currentNode;}
    void setCurrentNode(ModuleNode* moduleNode) {m_currentNode = moduleNode;}
	bool moveForward(unsigned int k);
	bool moveForwardTo(ModuleNode* mn);
	bool moveBackward(unsigned int k);
	bool moveBackwardTo(ModuleNode* mn);

- std::vector<std::list<ModuleNode*>>* getNodes() const; 
	Retourne le contenu du graphe
	Chaque colonne i du vecteur retourne contient la liste des noeud situes a la distance i du debut du graphe
	La premiere et la derniere colonne contiennent chacune juste un noeud vide representant respectivement le debut et la fin du graphe.
	
	


La classe moduleNode contient (entre autres) les methodes suivantes :

- std::vector<ModuleNode*>* getPrevious() const { return m_previous; }
- std::vector<ModuleNode*>* getNext() const { return m_next; }
- const Module* getModule() const {return m_module;}


J'ai essayer sans succes de faire heriter cette classe de cocos2d::Node, mais je galere a inclure et compiler cocos2d.
Cependant decommenter le "//: public cocos2d::Node" dans la classe moduleNode,
ainsi que le paragraphe d'include de cocos2d dans stdafx.h pourai fonctioner si cocos marche bien chez vous.



En cas d'erreur ou de crash, vous pouvez m'envoyer: 
-une copie de coutLog.txt
-capture d'ecran du message d'erreur et/ou du graphe affiche si existant
