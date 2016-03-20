#ifndef PREGRAPH_H
#define PREGRAPH_H

#include <map>

#include "Node.h"
#include "Fork.h"
#include "Junction.h"

class PreGraph
{
    public:
        PreGraph(std::map<const Module*, int>& modules);
        void add(std::map<const Module*, int>*& modules);
        Node* getContenu(){return m_contenu;};
        PreGraph(const PreGraph& other);
        ~PreGraph();
        PreGraph& operator=(const PreGraph& other);
    protected:
    private:
        Node* m_contenu;
};

#endif // PREGRAPH_H
