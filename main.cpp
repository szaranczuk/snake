#include <iostream>
#include "board.hpp"
int main()
{
    Board board(10, 10);
    std::cout << board.parseBoardToString();
    return 0;
}
