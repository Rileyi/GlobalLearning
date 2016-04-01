#ifndef LINK_H
#define LINK_H

class GraphElement;

class Link
{
    public:
        Link();
        Link(GraphElement* before, GraphElement* after);
        ~Link();
        Link(const Link& other);
        Link& operator=(const Link& other);

        GraphElement* getBefore() const { return m_before; }
        GraphElement* getAfter() const { return m_after; }
        void setBefore(GraphElement* before) { m_before = before; }
        void setAfter(GraphElement* after) { m_after = after; }
        bool isEmpty();
        void makeEmpty();

    protected:

    private:
        GraphElement* m_before;
        GraphElement* m_after;
};

bool operator==(const Link& l, const Link& r);


#endif // LINK_H
