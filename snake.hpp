#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED
#include "coordinates.hpp"
#include <queue>
class Snake
{
    public:
        Snake(Coordinates _start_pos);
        Coordinates getHeadPos();
        void snakeMove(unsigned _direction);
    private:
        Coordinates head_pos;
        std::deque<Coordinates> deq_body_pos;
        void moveHeadPos(Coordinates _coord);
        void setHeadPos(Coordinates _coord);
        void snakeGroove();
};


#endif // SNAKE_HPP_INCLUDED
