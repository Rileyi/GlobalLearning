#ifndef JUNCTION_H
#define JUNCTION_H

#include "Intersection.h"
#include "OutGE.h"
#include "Link.h"

#if defined _MSC_VER
    #pragma warning(disable:4250)
#endif

class Junction : public Intersection, public OutGE
{
    public:
        Junction();
        Junction(GraphElement* left, GraphElement* right, GraphElement* next);
        Junction(Link& l, const Side& s);
        ~Junction();
        Junction(const Junction& other);
        Junction& operator=(const Junction& other);


        using GraphElement::display;
        void display(GraphElement* callingGE, int l) override;

        void recursiveDelete() override;
        void changePrevious(GraphElement* oldGE, GraphElement* newGE) override;

        int bestFork(std::map<const Module*, int>** modules, Link* forkPlace) override;

        Side bestJunction(std::map<const Module*, int>** modules, Link* junctionPlace,
                Side* side, GraphElement* callingNode, int* distance) override;

        bool contains(std::map<const Module*, int>** modules) const override;

        void distanceAndValidity(std::map<const GraphElement*, twoInts*>* distancesMap,
                const GraphElement* callingGE, int distance, int w,
                std::string* errors) const override;

    protected:
    private:
};

#endif // JUNCTION_H
