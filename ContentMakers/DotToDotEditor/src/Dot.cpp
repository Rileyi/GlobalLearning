#include "Dot.h"

Dot::Dot(unsigned int number) : _number(number), _pos()
{
}

Dot::Dot(unsigned int number, const sf::Vector2f &position) : _number(number), _pos(position)
{
}

Dot::~Dot()
{
}

std::ostream& operator<<(std::ostream& os, const Dot& dot)
{
    os << dot._number << " (" << dot._pos.x << ";" << dot._pos.y << ")";
    return os;
}

std::ofstream& operator<<(std::ofstream& stream, const Dot& dot)
{
    stream << "<dot>" << std::endl;
    stream << "\t<number>" << dot._number << "</number>" << std::endl;
    stream << "\t<x>" << dot._pos.x << "</x>" << std::endl;
    stream << "\t<y>" << dot._pos.y << "</y>" << std::endl;
    stream << "</dot>" << std::endl;
    return stream;
}

unsigned int Dot::get_number() const
{
    return _number;
}

sf::Vector2f Dot::get_pos() const
{
    return _pos;
}
