#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "ModuleGE.h"

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

        const ModuleGE* getModuleGE() const override {return nullptr;}

    protected:
        GraphElement* m_left;
        GraphElement* m_right;
    private:
};

#endif // INTERSECTION_H
