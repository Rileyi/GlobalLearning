#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "GraphElement.h"
#include "ModuleGE.h"
#include "Link.h"


class Intersection : public virtual GraphElement
{
    public:
        Intersection();
        Intersection(GraphElement* left, GraphElement* right);
        Intersection(Link&);
        virtual ~Intersection() {}
        Intersection(const Intersection& other);
        Intersection& operator=(const Intersection& rhs);

        GraphElement* getLeft() const { return m_left; }
        void setLeft(GraphElement* val) { m_left = val; }
        GraphElement* getRight() const { return m_right; }
        void setRight(GraphElement* val) { m_right = val; }

    protected:
        GraphElement* m_left;
        GraphElement* m_right;
    private:
};

#endif // INTERSECTION_H
