#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "board.hpp"
#include "snake.hpp"
#include "coordinates.hpp"
#include "randomunsignednumbergenerator.hpp"

class Game
{
    public:
        Game(unsigned _boardHeight, unsigned _boardWidth);
        bool isSnakeOnLoosingCell();
        void takePlayerTurn(int _direction);
        char getAppleChar();
        std::string getBoardToPrint();
    private:
        Board game_board;
        Snake player_snake;
        RandomUnsignedNumberGenerator random_pos_generator;
        bool isSnakeOnApple();
        void putApple();
        void updateGameBoard();
        const char APPLE_CHAR;
};


#endif // GAME_H_INCLUDED
