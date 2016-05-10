#ifndef MODULEGE_H
#define MODULEGE_H

#include "InGE.h"
#include "OutGE.h"

#if defined _MSC_VER
    #pragma warning(disable:4250)
#endif

class ModuleGE : public InGE, public OutGE
{
    public:
        ModuleGE(const Module*);
        ModuleGE(const Module*, GraphElement* previous, GraphElement* next);
        ModuleGE(const ModuleGE& other);
        ~ModuleGE();
        ModuleGE& operator=(const ModuleGE& other);

        void recursiveDelete() override;

        void moveAfter(Link&);
        void moveBefore(Link&);

        using GraphElement::display;
        void display(GraphElement* callingGE, int l) override;

        const ModuleGE* getModuleGE() const override {return this;}

        const Module* getModule() const { return m_module; }
        void setModule(const Module* m) { m_module = m; }

        int bestFork(std::map<const Module*, int>** modules, Link* forkPlace) override;

        Side bestJunction(std::map<const Module*, int>** modules, Link* junctionPlace,
                Side* side, GraphElement* callingNode, int* distance) override;

        bool contains(std::map<const Module*, int>** modules) const override;

        void distanceAndValidity(std::map<const GraphElement*, twoInts*>* distancesMap,
                const GraphElement* callingGE, int distance, int* w,
                std::string* errors) const override;

        std::string toString() const;

    protected:
    private:
        void moveAt(const Link&);
        const Module* m_module;
};

#endif // NOEUD_H
