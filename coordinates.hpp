#ifndef COORDINATES_HPP_INCLUDED
#define COORDINATES_HPP_INCLUDED
struct Coordinates
{
    int x;
    int y;
};
const Coordinates UP = {1, 0};
const Coordinates RIGHT = {0, 1};
const Coordinates DOWN = {-1, 0};
const Coordinates LEFT = {0, -1};
const Coordinates NULLCOORD = {-21, -37};


#endif // COORDINATES_HPP_INCLUDED
