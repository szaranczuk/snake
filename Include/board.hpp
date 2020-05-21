#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "coordinates.hpp"

class Board
{
    public:
        Board(unsigned _height, unsigned _width);
        unsigned getWidth();
        unsigned getHeight();
        unsigned getBoardSize();
        char getCellValue(Coordinates coord);
        bool isCellEmpty(Coordinates coord);
        void setCellValue(Coordinates coord, char value);
        char getBorderChar();
        std::vector<char>& getBoardReference();
        std::string parseBoardToString();
    private:
        unsigned getIndex(Coordinates coord);
        const unsigned U_HEIGHT;
        const unsigned U_WIDTH;
        const unsigned U_BOARD_SIZE;
        std::vector<char> v_board; //1D represantation of 2D array
        void initializeBoard();
        void makeBorders();
        const char BORDER_CHAR;
};

class BoardToString //conversion functor
{
    public:
        BoardToString(unsigned _width);
        std::string getStringBoard();
        void operator()(char _cell);
    private:
        bool isItLastLine();
        void resetCharsToNewLine();
        std::string stringBoard;
        const unsigned U_WIDTH;
        unsigned u_charsToNewLine;
};

#endif // BOARD_HPP_INCLUDED
