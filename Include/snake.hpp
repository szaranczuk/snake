#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED
#include "coordinates.hpp"
#include <queue>
class Snake
{
    public:
        Snake();
        Coordinates getHeadPos();
        Coordinates getPoppedElementPos();
        void snakeMove(unsigned _direction);
        char getBodyChar();
        char getHeadChar();
        std::deque<Coordinates> getBodyPosDeque();
        void setHeadPos(Coordinates _coord);
        void snakeGroove();
    private:
        void setPoppedElementPos(Coordinates coord);
        Coordinates head_pos;
        std::deque<Coordinates> deq_body_pos;
        void moveHeadPos(Coordinates _coord);
        const char BODY_CHAR;
        const char HEAD_CHAR;
        Coordinates popped_element_pos;
};


#endif // SNAKE_HPP_INCLUDED
