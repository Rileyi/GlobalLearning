========================================================================
    APPLICATION CONSOLE : Vue d'ensemble du projet AlgoParcour
========================================================================

PreGraph* generateGraph(int length, int width, int reading, int writing, int maths, int fun) genere le graphe.

Le pregraph contient (pour l'instant) juste un pointer sur le premier noeud.

Chaque element du graphe est un GraphElement (ou GE) (classe virtuelle).
Cette classe se decline en:
-Node (element qui contienne un "module", ainsi qu'un GE suivant et un GE precedent),
-Fork (contient un GE precedant, un GE suivant droit, et un GE suivant gauche),
-Junction (contient un GE suivant, un GE precedant droit, et un GE precedant gauche)

