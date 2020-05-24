#include "snake.hpp"
Snake::Snake() :  BODY_CHAR('%'),
HEAD_CHAR('@'){}
Coordinates Snake::getHeadPos() {return head_pos;}
Coordinates Snake::getPoppedElementPos() {return popped_element_pos;}
void Snake::setPoppedElementPos(Coordinates coord) {popped_element_pos = coord;}
void Snake::snakeMove(unsigned _direction)
{
    Coordinates head_pos = getHeadPos();
    deq_body_pos.push_front(head_pos);
    //if (deq_body_pos.back().x != NULLCOORD.x && deq_body_pos.back().y != NULLCOORD.y)
    setPoppedElementPos(deq_body_pos.back());

    deq_body_pos.pop_back();

    switch(_direction)
    {
        case 0: moveHeadPos(UP); break;
        case 1: moveHeadPos(RIGHT); break;
        case 2: moveHeadPos(DOWN); break;
        case 3: moveHeadPos(LEFT); break;
    }
}
void Snake::moveHeadPos(Coordinates _coord)
{
    Coordinates head_pos = getHeadPos();
    Coordinates newHeadPos = {head_pos.x + _coord.x, head_pos.y + _coord.y};
    setHeadPos(newHeadPos);
}
void Snake::setHeadPos(Coordinates _coord) {head_pos = _coord;}
void Snake::snakeGroove()
{
    deq_body_pos.push_back(NULLCOORD); //cause not pop in next move
}
char Snake::getBodyChar() {return BODY_CHAR;}
char Snake::getHeadChar() {return HEAD_CHAR;}
std::deque<Coordinates> Snake::getBodyPosDeque() {return deq_body_pos;}
