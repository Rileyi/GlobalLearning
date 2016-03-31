#ifndef ALGOPARCOUR_H
#define ALGOPARCOUR_H

#include "UsableGraph.h"

UsableGraph* generateGraph(int length, int width, int reading, int writing, int maths, int fun);

std::map<const Module* const, int> & readCSV(const std::string& filename);

//Genere une base (ou preset) de N modules randomises en privilegiant les modules absents
//des precedents sets.
std::map<const Module*, int>& generateBase(std::map<const Module* const, int> & modules,
        int N);

//Cherche un module a echanger pour ameillorer le set et effectue cet echange
bool exchange(std::map<const Module*, int> & base,
              std::map<const Module* const, int> const& candidats,
              int reading, int writing, int maths, int fun);


struct ModuleScoreStruct
{
    const Module* module;
    int score;
    ModuleScoreStruct() : module(nullptr), score(0) {};
    ModuleScoreStruct(const Module* const m, int s) : module(m), score(s) {};
    bool operator()
    (const ModuleScoreStruct*  left, const ModuleScoreStruct* right)
    {
        if (left->score != right->score) return left->score < right->score;
        return left->module < right->module;
    };
};

#endif
