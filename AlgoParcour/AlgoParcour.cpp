#include "stdafx.h"
#include "AlgoParcour.h"

using namespace std;

int main()
{
    cout << "Algorithm de creation des parcours journaliers de modules.\n";


    int N,L;
    cout << "Longueur (nombre de modules par set): ";
    cin >> N;
    cout << "Largeur: ";
    cin >> L;
    int readingAim, writingAim, mathsAim, funAim;
    cout << "Quantite ecriture/lecture/mathematiques/eveil: ";
    cin >> readingAim >> writingAim >> mathsAim >> funAim;

    generateGraph(N, L, readingAim, writingAim, mathsAim, funAim);

    return 0;
}

UsableGraph* generateGraph(int length, int width, int readingAim, int writingAim, int mathsAim, int funAim)
{
    //Initialisation de l'aleatoire
    srand(static_cast<int>(time(nullptr)));

    //Etape I:
    //Lire la BDD de modules pour en extraire les module correspondant au niveau et
    //capacites de l'enfant.
    //Ici cette etape est remplacee par la lecture d'un simple fichier csv suppose contenir
    //la liste de ces modules.
    map<const Module* const, int> modules = readCSV("modules.csv");
    //La map modules contient les pointeur vers les modules, chacun associe un entier
    //correspondant au nombre d'apparition du module dans le graphe

    PreGraph* preGraph = nullptr;

    int success=0;
    int fails=0;
    do
    {
        //Etape II:
        //Generation de sets de N modules correspondant au ratio
        //ecriture/lecture/mathematiques/eveil.

        //Generation de la base, liste de modules +/-random ituant un point de depart
        //que l'on va adapter pour devenir un set correspondant au besoins de notre graphe
        //(ratio ecriture/lecture/mathematiques/eveil).
        map<const Module*, int>* base = new map<const Module*, int>(generateBase(modules, length));

        //On va desormais ameillorer cette base par echange successif de modules
        do {}
        while (exchange(*base, modules, readingAim, writingAim, mathsAim, funAim));

        cout << "\nSet :\n";
        for (map<const Module*, int>::const_iterator it = base->begin();
                it != base->end(); ++it)
        {
            cout << it->second << "*[" << (*it->first) << "] : " << it->first->toString() << '\n';
            modules[it->first] += it->second;
        }

        //Etape III:
        //Generation du graphe a partir des sets de modules
        //La structure produite est assez complexe mais peut tout a fait se transformer en une
        //representation plus classique de graphe (matrice d'adjacence par exemple)

        //On innitialise le graphe en creant le premier chemin
        if (success==0)
        {
            preGraph = new PreGraph(*base);
            ++success;
        }
        else
        {
            //Puis on ajoute un par un les autres sets
            //L'algo derriere la methode ajouter permet de reperer le redondances
            //et donc de generer le squelette du graphe final
            ++ (preGraph->add(base) ? success : fails);
        }

        preGraph->getContenu()->display();
        cout <<'\n';

        delete base;

    } while (success < width  &&  fails < width);

    UsableGraph* graph =
        new UsableGraph(preGraph, length+2, width, readingAim, writingAim, mathsAim, funAim);
    delete preGraph;

    if (graph->isValid())
    {
        cout << "\nGraph of dimensions (" << graph->getLength() << "," << graph->getWidth() << "):\n";
        graph->display();
    }

    return graph;
}

std::map<const Module* const, int> & readCSV(const string& filename)
{
    cout << "Lecture du fihier contenant la liste de modules:\n";
    map<const Module* const, int>* modules = new map<const Module* const, int>();
    ifstream file(filename);
    if (file.is_open())
    {
        cout << filename << "Fichier correctement ouvert.\n";
        string moduleName;
        int reading, writting, maths, fun;
        getline(file, moduleName);
        for (int i = 0; file.good(); ++i)
        {
            file >> moduleName >> reading >> writting >> maths >> fun;
            (*modules)[new Module(moduleName, reading, writting, maths, fun)] = 0;
        }
        cout << "Verrification du contenu:\n";
        for (map<const Module* const, int>::const_iterator it = (*modules).begin();
                it != (*modules).end(); ++it)
        {
            cout << it->first->toString() << '\n';
        }
    }
    else
    {
        cout << "Impossible d'ouvrir " << filename << ".\n";
    }
    return *modules;
}

//Genere une base (ou preset) de N modules randomises en privilegiant les modules absents
//des precedents sets.
std::map<const Module*, int>& generateBase(
    std::map<const Module* const, int> & modules, int N)
{
    map<const Module*, int>* const base = new map<const Module*, int>();

    //System de malus pour les modules deja present dans le set
    int malus = 2;

    //choix des modules pour la base
    //On choisit en priorite les modules les moins frequent des les set deja crees
    int n = 0; //n: nombre de modules ajoutes a notre base
    int k; //k: nombre de modules avec occ occurences
    //occ: nombre d'occurence
    for (int occ = 0; n < N; occ++)
    {
        k = 0;
        for (map<const Module* const, int>::iterator it = modules.begin();
                it != modules.end(); ++it)
        {

            //Si un module corespond au nombre d'occurence
            if (it->second == occ)
            {

                //On l'ajoute à la base (ou on augmente sa frequence si il y est deja)
                if ((*base).find(it->first) == (*base).end())
                {
                    (*base)[it->first] = 1;
                }
                else
                {
                    ++((*base)[it->first]);
                }

                //System de malus pour les modules deja present:
                //il reapparaitrons aux niveaux de plusieurs occurences de plus
                //Cela permet aussi de completer l'algo meme lorsque le nombre total de
                //modules est <N
                //Et on oublie pas le '+1' pour le fait que on a quand meme rajoute un module
                it->second += malus + 1;

                ++k;
            }
        }
        n += k;
    }

    //On a desormais n>=N modules dans notre base
    //On en enleve aleatoirement n-N
    for (map<const Module* const, int>::iterator it; n > N; --n)
    {
        it = (*base).begin();

        //On defini et on va chercher quel module retirer
        for (int r = rand() % (*base).size(); r > 0; ++it, --r);

        //Diminution de la frequence d'utilisation dans la frequence des modules sans
        //oublier le malus
        modules[it->first] -= malus + 1;

        //On le retire (ou on diminu sa frequence si il y en a plusieurs exemplaires)
        if (it->second == 1)
        {
            (*base).erase(it);
        }
        else
        {
            --(it->second);
        }
    }

    //Suppression des malus ayant ete introduits lors de cette etape
    for (map<const Module* const, int>::const_iterator it = (*base).begin(); it != (*base).end();
            ++it)
    {
        modules[it->first] -= malus*(it->second);
    }

    return *base;
}


//Cherche un module a echanger pour ameillorer la base et effectue cet echange
bool exchange(std::map<const Module*, int> & base,
              std::map<const Module* const, int> const& candidats,
              int readingAim, int writingAim, int mathsAim, int funAim)
{
    //On commence par calculer le total ecriture/lecture/mathematiques/eveil
    int writingTotal = 0, readingTotal = 0, mathsTotal = 0, funTotal = 0;
    for (map<const Module* const, int>::const_iterator it = base.begin();
            it != base.end(); ++it)
    {
        writingTotal += (it->first->getWriting()) * (it->second);
        readingTotal += (it->first->getReading()) * (it->second);
        mathsTotal   += (it->first->getMaths()  ) * (it->second);
        funTotal     += (it->first->getFun()    ) * (it->second);
    }

    //On en deduit l'ecart entre ce que l'on a et ce que l'on veux
    int writingDiff = writingTotal - writingAim;
    int readingDiff = readingTotal - readingAim;
    int mathsDiff = mathsTotal - mathsAim;
    int funDiff = funTotal - funAim;

    //Puis on note et on ordone chaque module de la base selon son apport,
    //sa frequence, et sa redondance par rapport aux autres modules dans le set.
    set< ModuleScoreStruct*, ModuleScoreStruct> scoreBase;
    for (map<const Module* const, int>::const_iterator it = base.begin();
                                           it != base.end(); ++it)
    {
        scoreBase.insert(new  ModuleScoreStruct(it->first,
                                                max(it->first->getWriting() - max(writingDiff, 0), 0) //apport
                                                + max(it->first->getReading() - max(readingDiff, 0), 0) //
                                                + max(it->first->getMaths()   - max(mathsDiff  , 0), 0) //
                                                + max(it->first->getFun()     - max(funDiff    , 0), 0) //
                                                - min(it->first->getWriting(), max(writingDiff, 0))     //redondance
                                                - min(it->first->getReading(), max(readingDiff, 0))     //
                                                - min(it->first->getMaths()  , max(mathsDiff  , 0))     //
                                                - min(it->first->getFun()    , max(funDiff    , 0))     //
                                                - (it->second - 1) * 10));                              //frequence
    }


    //Idem pour les modules candidats
    //On enleve juste la redondance qui ne donnerais que des scores negatifs
    /*set<const ModuleScoreStruct*, ModuleScoreStruct> scoreCandidats;
    for (map<const Module* const, int>::const_iterator it = candidats.begin();
                                           it != candidats.end(); ++it)
    {
        scoreCandidats.insert(new  ModuleScoreStruct(it->first,
                              min(it->first->getWriting(), max(-writingDiff, 0))   //apport
                              + min(it->first->getReading(), max(-readingDiff, 0))   //
                              + min(it->first->getMaths()  , max(-mathsDiff  , 0))   //
                              + min(it->first->getFun()    , max(-funDiff    , 0))   //
                              - (base.find(it->first) != base.end()  ?  base[it->first] * 10  :  0)));//frequence
    }*/ //peu performant pour effectuer des bon choix, n'allege presque jamais la complexite


    for (const ModuleScoreStruct* moduleBase : scoreBase)
    {
        int meilleurScore = 0;
        const Module* meilleurCandidat = nullptr;
        for (map<const Module* const, int>::const_reverse_iterator
             rit = candidats.rbegin(); rit != candidats.rend(); ++rit)
        {

            //sinon on calcul l'apport reel optenu en cas d'echange
            int ra = rit->first->getReading() - moduleBase->module->getReading();
            ra = (readingDiff>0
                  ? (ra >= 0 ||  readingDiff >= -ra  ?  -ra  :   ra+2*readingDiff)
                  : (ra <= 0 || -readingDiff >=  ra  ?   ra  :  -ra-2*readingDiff));
            int wa = rit->first->getWriting() - moduleBase->module->getWriting();
            wa = (writingDiff>0
                  ? (wa >= 0 ||  writingDiff >= -wa  ?  -wa  :   wa+2*writingDiff)
                  : (wa <= 0 || -writingDiff >=  wa  ?   wa  :  -wa-2*writingDiff));
            int ma = rit->first->getMaths() - moduleBase->module->getMaths();
            ma = (mathsDiff>0
                  ? (ma >= 0 ||  mathsDiff >= -ma  ?  -ma  :   ma+2*mathsDiff)
                  : (ma <= 0 || -mathsDiff >=  ma  ?   ma  :  -ma-2*mathsDiff));
            int fa = rit->first->getFun() - moduleBase->module->getFun();
            fa = (funDiff>0
                  ? (fa >= 0 ||  funDiff >= -fa ? -fa :  fa+2*funDiff)
                  : (fa <= 0 || -funDiff >=  fa ?  fa : -fa-2*funDiff));
            int r = (base[moduleBase->module]-1) *10;
            r -= (base.find(rit->first) == base.end()  ?  0  :  base[rit->first] * 10);

            //On choisi le meilleur candidat (celui avec le meilleur score) au fil des iteration
            int score = wa + ra + ma + fa + r;
            if (score > meilleurScore)
            {
                meilleurCandidat = rit->first;
                meilleurScore = score;
            }
        }

        if (meilleurScore >0)
        {
            //Si le meilleur candidat donne un apport positif, on effectue l'echange :
            //On ajoute le nouveau module a la base (ou augmente sa frequence si il y est deja)
            if (base.find(meilleurCandidat) == base.end())
            {
                base[meilleurCandidat] = 1;
            }
            else
            {
                ++(base[meilleurCandidat]);
            }

            //Et on retire le precedent module (ou diminue sa frequence le cas echeant)
            if (--base[moduleBase->module] == 0)
            {
                base.erase(moduleBase->module);
            }

            //travail termine
            for (const ModuleScoreStruct* moduleScore : scoreBase)
            {
                delete moduleScore;
            }
            return true;
        }
        //Sinon, on essaye d'echanger un autre module
    }

    for (const ModuleScoreStruct* moduleScore : scoreBase)
    {
        delete moduleScore;
    }

    return false;
}
