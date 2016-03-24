#ifndef OUTGE_H
#define OUTGE_H

#include "GraphElement.h"


class OutGE : public virtual GraphElement
{
    public:
        OutGE(GraphElement* next);
        virtual ~OutGE() {}
        OutGE(const OutGE& other);
        OutGE& operator=(const OutGE& other);

        void changeNext(GraphElement* oldGE, GraphElement* newGE) override;

        std::vector<const ModuleGE*>* getNextModuleGEs() const override;

        void recursiveDelete() override;

        GraphElement* getNext() { return m_next; }
        void setNext(GraphElement* val) { m_next = val; }

    protected:
        GraphElement* m_next;

    private:
};

#endif // OUTGE_H
