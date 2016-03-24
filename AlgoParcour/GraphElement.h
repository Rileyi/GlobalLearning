#ifndef GRAPHELEMENT_H
#define GRAPHELEMENT_H

#include <vector>

#include "Module.h"
#include "Side.h"
#include "Link.h"

class ModuleGE;
class Junction;
class Fork;

struct twoInts
{
    int fst, snd;
    twoInts(int a, int b) : fst(a), snd(b) {};
};

typedef class GraphElement
{
    public:
        virtual ~GraphElement() {}

        //suppression recursive des elements du graphe
        virtual void recursiveDelete() =0;

        //Change un predecesseur ou successeur de l'element courrant connaissant l'adresse de ce
        //predecesseur/successeur et sa nouvelle valeur.
        //Ne fait rien si l'adresse donnee n'est pas connue de l'element courrant
        virtual void changePrevious(GraphElement* oldGE, GraphElement* newGE) =0;
        virtual void changeNext(GraphElement* oldGE, GraphElement* newGE) =0;

        virtual void display(GraphElement* callingGE, int l) =0;
        void display() {display(nullptr,0);}

        virtual const ModuleGE* getModuleGE() const =0;
        virtual std::vector<const ModuleGE*>* getNextModuleGEs() const =0;

        //Recherche une fourche (ne la cree pas) de facon recursive dans le graphe
        //
        //Cette fonction adapte le graphe de maniere a ameillorer la qualite du point de fourche
        //
        //La map de module passee en parametres est modifiee au cours de la recursion, d'ou le
        //pointeur, (faire une copie preventive) et, a la fin, il n'y reste que les modules qui
        //pourront parraitre apres le point de fourche
        //
        //forkPlace doit etre vide au premier appel (fp = new Link()).
        //A la fin du parcours forkPlace est positione entre le dernier element devant se touver
        //avant la fourche et le premier element devant se trouver apres la fourche
        //Si a la fin du parcour, aucun point de fourche correct n'a ete trouve, ce qui implique que
        //la liste de module donnee est deja decrite par un chemin du graphe alors il sera toulours
        //vide (ie getAfter() = getBefore() = nullptr)
        //
        //L'entier retourne indique le nombre de noeuds (ie de modules) precedents la fourche et que
        //partagerons l'ancien chemin et le nouveau chemin
        virtual int bestFork(std::map<const Module*, int>** modules, Link* forkPlace) =0;

        virtual Side bestJunction(std::map<const Module*, int>** modules, Link* junctionPlace,
                Side* side, GraphElement* callingNode, int* distance) =0;

        virtual bool contains(std::map<const Module*, int>** modules) const =0;

        virtual void distanceAndValidity(std::map<const GraphElement*, twoInts*>* distancesMap,
                const GraphElement* callingGE, int distance, int w,
                std::string* errors) const =0;


    protected:
    private:
} GE;

#endif // GRAPHELEMENT_H
