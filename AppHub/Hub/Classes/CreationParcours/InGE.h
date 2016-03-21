#ifndef INGE_H
#define INGE_H

#include "GraphElement.h"


class InGE : public virtual GraphElement
{
    public:
        InGE(GraphElement* previous);
        virtual ~InGE() {}
        InGE(const InGE& other);
        InGE& operator=(const InGE& other);

        void changePrevious(GraphElement* oldGE, GraphElement* newGE) override;

        GraphElement* getPrevious() { return m_previous; }
        void setPrevious(GraphElement* val) { m_previous = val; }

    protected:
        GraphElement* m_previous;

    private:
};

#endif // INGE_H
