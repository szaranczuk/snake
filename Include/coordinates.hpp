#ifndef COORDINATES_HPP_INCLUDED
#define COORDINATES_HPP_INCLUDED
struct Coordinates
{
    int x;
    int y;
};
const Coordinates UP = {0, -1};
const Coordinates RIGHT = {1, 0};
const Coordinates DOWN = {0, 1};
const Coordinates LEFT = {-1, 0};
const Coordinates NULLCOORD = {-21, -37};


#endif // COORDINATES_HPP_INCLUDED
