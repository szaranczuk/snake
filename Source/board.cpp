#include "board.hpp"

Board::Board(unsigned _height, unsigned _width) : U_HEIGHT(_height), U_WIDTH(_width), U_BOARD_SIZE(_height * _width), BORDER_WALLS_CHAR('|'), BORDER_ROOF_CHAR('_'), BORDER_FLOOR_CHAR('#')
{
    initializeBoard();
    makeBorders();
}
unsigned Board::getHeight() {return U_HEIGHT;}
unsigned Board::getWidth() {return U_WIDTH;}
unsigned Board::getBoardSize() {return U_BOARD_SIZE;}
unsigned Board::getIndex(Coordinates coord) {return coord.x + coord.y * getWidth();}
char Board::getCellValue(Coordinates coord) {return v_board[getIndex(coord)];}
char Board::getBorderWallsChar() {return BORDER_WALLS_CHAR;}
char Board::getBorderRoofChar() {return BORDER_ROOF_CHAR;}
char Board::getBorderFloorChar() {return BORDER_FLOOR_CHAR;}
std::vector<char>& Board::getBoardReference() {return v_board;}

void Board::initializeBoard()
{
    for (int i = 0; i < getBoardSize(); i++)
    {
        v_board.push_back(' ');
    }
}
bool Board::isCellEmpty(Coordinates coord) {return getCellValue(coord) == ' ';}
void Board::setCellValue(Coordinates coord, char value) {v_board[getIndex(coord)] = value;}
void Board::makeBorders()
{
    unsigned width = getWidth();
    unsigned height = getHeight();
    for (unsigned i = 0; i < width; i++) //border roof
        v_board[getIndex({i, 0})] = BORDER_ROOF_CHAR;
    for (unsigned i = 1; i < height - 1; i++) //border walls
    {
        v_board[getIndex({0, i})] = BORDER_WALLS_CHAR;
        v_board[getIndex({width - 1, i})] = BORDER_WALLS_CHAR;
    }
    for (unsigned i = 0; i < width; i++) //border floor
        v_board[getIndex({i, height - 1})] = BORDER_FLOOR_CHAR;
}
std::string Board::parseBoardToString()
{
    std::unique_ptr<BoardToString> p_boardToStringConventer(new BoardToString(getWidth()));
    BoardToString boardToStringConventer = *p_boardToStringConventer;
    std::for_each(v_board.begin(), v_board.end(), std::ref(boardToStringConventer));
    return boardToStringConventer.getStringBoard();
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
