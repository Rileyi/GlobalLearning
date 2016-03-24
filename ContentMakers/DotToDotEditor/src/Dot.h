#ifndef DOT_H
#define DOT_H

#pragma GCC diagnostic ignored "-Weffc++" // disable Weffc++ warnings for SFML
#include <SFML/Graphics.hpp>
#pragma GCC diagnostic pop // turn the warnings back on

#include <iostream>
#include <fstream>

class Dot
{
    public:
        Dot(unsigned int number);
        Dot(unsigned int number, const sf::Vector2f&);
        virtual ~Dot();

        friend std::ostream& operator<<(std::ostream& os, const Dot& dot);
        friend std::ofstream& operator<<(std::ofstream& stream, const Dot& dot);

        unsigned int get_number() const;
        sf::Vector2f get_pos() const;

    protected:
        unsigned int _number;
        sf::Vector2f _pos;

    private:
};

#endif // DOT_H
