#ifndef FORK_H
#define FORK_H

#include "Intersection.h"
#include "InGE.h"
#include "Link.h"


class Fork : public Intersection, public InGE
{
    public:
        Fork();
        Fork(GraphElement* left, GraphElement* right, GraphElement* previous);
        Fork(Link& link, const Side& side);
        ~Fork() {};
        Fork(const Fork& other);
        Fork& operator=(const Fork& rhs);

        using GraphElement::display;
        void display(GraphElement* callingGE, int l) override;

        void recursiveDelete() override;
        void changeNext(GraphElement* oldGE, GraphElement* newGE) override;

        int bestFork(std::map<const Module*, int>** modules, Link* forkPlace) override;

        Side bestJunction(std::map<const Module*, int>** modules, Link* junctionPlace,
                Side* side, GraphElement* callingNode, int* distance) override;

        bool contains(std::map<const Module*, int>** modules) const override;

    protected:
    private:
};

#endif // FORK_H
