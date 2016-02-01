#ifndef REQUIREMENT_H
#define REQUIREMENT_H

class Requirement
{
    public:
        Requirement(unsigned int level = 0);
        virtual ~Requirement();
        Requirement(const Requirement& other);
        Requirement& operator=(const Requirement& other);

    // Attributes
    protected:
        unsigned int _level;
};

#endif // REQUIREMENT_H
