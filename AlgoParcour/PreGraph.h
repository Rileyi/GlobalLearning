#ifndef PREGRAPH_H
#define PREGRAPH_H

#include <map>

#include "ModuleGE.h"
#include "Fork.h"
#include "Junction.h"

class PreGraph
{
    public:
        PreGraph(std::map<const Module*, int>& modules);
        bool add(std::map<const Module*, int>*& modules);
        ModuleGE* getContenu(){return m_contenu;};
        PreGraph(const PreGraph& other);
        ~PreGraph();
        PreGraph& operator=(const PreGraph& other);
    protected:
    private:
        ModuleGE* m_contenu;
};

#endif // PREGRAPH_H
