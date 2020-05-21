#include <iostream>
#include <map>
#include <exception>
#include "game.hpp"
#ifdef _WIN32
#define clean "cls"
#else
#define clean "clean"
#endif

std::map<char, unsigned> CONTROLS = {{'w', 0}, {'d', 1}, {'s', 2}, {'a', 3}};

const unsigned getDirectionFromUser()
{
    while (true)
    {
        char key;
        std::cin >> key;
        try
        {
            return CONTROLS.at(key);
        }
        catch (std::out_of_range)
        {
            std::cout << "Wrong key!"
                      << "\n";
        }
    }
}

int main()
{
    Game game(10, 10);
    std::cout << game.getBoardToPrint();
    while(!game.isSnakeOnLoosingCell())
    {
        game.takePlayerTurn(getDirectionFromUser());
        system(clean);
        std::cout << game.getBoardToPrint();
    }
    return 0;
}
