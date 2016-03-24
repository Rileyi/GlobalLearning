#ifndef NODE_H
#define NODE_H

#include "InGE.h"
#include "OutGE.h"
#include "Link.h"

class Node : public InGE, public OutGE
{
    public:
        Node(const Module*);
        Node(const Module*, GraphElement* previous, GraphElement* next);
        Node(const Node& other);
        ~Node();
        Node& operator=(const Node& other);

        void moveAfter(Link&);
        void moveBefore(Link&);

        using GraphElement::display;
        void display(GraphElement* callingGE, int l) override;

        const Module* getModule() const { return m_module; }
        void setModule(const Module* m) { m_module = m; }

        int bestFork(std::map<const Module*, int>** modules, Link* forkPlace) override;

        Side bestJunction(std::map<const Module*, int>** modules, Link* junctionPlace,
                Side* side, GraphElement* callingNode, int* distance) override;

        bool contains(std::map<const Module*, int>** modules) const override;

    protected:
    private:
        void moveAt(const Link&);
        const Module* m_module;
};

#endif // NOEUD_H
