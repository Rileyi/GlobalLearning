#ifndef DIRECTION_H
#define DIRECTION_H

#pragma GCC diagnostic ignored "-Weffc++" // disable Weffc++ warnings for SFML
#include <SFML/System/Vector2.hpp>
#pragma GCC diagnostic pop // turn the warnings back on

#include <bitset>

/**
 * Enum�ration des directions possibles pour le d�placement
 */
enum class Direction
{
    North, South, East, West
};

/**
 * Structure repr�sentant les 4 directions, chacune pouvant valoir true or false
 * Initialisation possible � partir d'un std::bitset<4>
 */
struct Directions
{
    bool north, south, west, east;
    Directions() : north(false), south(false), west(false), east(false) {}
    Directions(const std::bitset<4>& bs) : north(bs[3] == 1), south(bs[2] == 1), west(bs[1] == 1), east(bs[0] == 1) {}
};

#endif // DIRECTION_H
