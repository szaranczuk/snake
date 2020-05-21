#include "board.hpp"

Board::Board(unsigned _height, unsigned _width) : U_HEIGHT(_height), U_WIDTH(_width), U_BOARD_SIZE(_height * _width)
{
    initializeBoard();
    makeBorders();
}
unsigned Board::getHeight() {return U_HEIGHT;}
unsigned Board::getWidth() {return U_WIDTH;}
unsigned Board::getBoardSize() {return U_BOARD_SIZE;}
unsigned Board::getIndex(Coordinates coord) {return coord.x + coord.y * getWidth();}
std::vector<char>& Board::getBoardReference() {return v_board;}

void Board::initializeBoard()
{
    for (int i = 0; i < getBoardSize(); i++)
    {
        v_board.push_back(' ');
    }
}
void Board::makeBorders()
{
    unsigned width = getWidth();
    unsigned height = getHeight();
    for (unsigned i = 0; i < width; i++) //first row
        v_board[getIndex({i, 0})] = '*';
    for (unsigned i = 0; i < height; i++) //first and last column
    {
        v_board[getIndex({0, i})] = '*';
        v_board[getIndex({width - 1, i})] = '*';
    }
    for (unsigned i = 0; i < width; i++) //last row
        v_board[getIndex({i, height - 1})] = '*';
}
std::string Board::parseBoardToString()
{
    std::unique_ptr<BoardToString> p_boardToString(new BoardToString(getWidth()));
    BoardToString boardToString = *p_boardToString;
    std::for_each(v_board.begin(), v_board.end(), std::ref(boardToString));
    return boardToString.getStringBoard();
}


BoardToString::BoardToString(unsigned _width) : U_WIDTH(_width) {resetCharsToNewLine();}
std::string BoardToString::getStringBoard() {return stringBoard;}
void BoardToString::operator()(char _cell)
{
    stringBoard.push_back(_cell);
    if (isItLastLine())
    {
        stringBoard.push_back('\n');
        resetCharsToNewLine();
    }
}
void BoardToString::resetCharsToNewLine() {u_charsToNewLine = U_WIDTH;}
bool BoardToString::isItLastLine()
{
    u_charsToNewLine--;
    return u_charsToNewLine == 0;
}
