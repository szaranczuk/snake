#include "game.hpp"

Game::Game(unsigned _boardHeight, unsigned _boardWidth) : game_board(_boardHeight, _boardWidth), random_pos_generator(), player_snake(), APPLE_CHAR('o')
{
    unsigned u_snake_start_x_pos = random_pos_generator.rollRandomUnsignedNumber(1, _boardWidth - 1);
    unsigned u_snake_start_y_pos = random_pos_generator.rollRandomUnsignedNumber(1, _boardHeight - 1);
    player_snake.setHeadPos({u_snake_start_x_pos, u_snake_start_y_pos});
    putApple();
    game_board.setCellValue(player_snake.getHeadPos(), player_snake.getHeadChar());

}
bool Game::isSnakeOnLoosingCell()
{
    char headPosCellValue = game_board.getCellValue(player_snake.getHeadPos());
    return headPosCellValue == game_board.getBorderWallsChar() || headPosCellValue == game_board.getBorderRoofChar() || headPosCellValue == game_board.getBorderFloorChar() || headPosCellValue == player_snake.getBodyChar();
}
void Game::takePlayerTurn(int _direction)
{
    player_snake.snakeMove(_direction);
    if (isSnakeOnApple())
    {
        player_snake.snakeGroove();
        putApple();
    }
    if (!isSnakeOnLoosingCell())
        updateGameBoard();
}
bool Game::isSnakeOnApple()
{
    Coordinates snake_head_pos = player_snake.getHeadPos();
    return game_board.getCellValue(snake_head_pos) == getAppleChar();
}
char Game::getAppleChar() {return APPLE_CHAR;}
void Game::putApple()
{
    unsigned game_board_width = game_board.getWidth();
    unsigned game_board_height = game_board.getHeight();
    unsigned apple_x_pos = random_pos_generator.rollRandomUnsignedNumber(1, game_board_width - 1);
    unsigned apple_y_pos = random_pos_generator.rollRandomUnsignedNumber(1, game_board_height - 1);
    while(!game_board.isCellEmpty({apple_x_pos, apple_y_pos}))
        {
            apple_x_pos = random_pos_generator.rollRandomUnsignedNumber(1, game_board_width - 1);
            apple_y_pos = random_pos_generator.rollRandomUnsignedNumber(1, game_board_height - 1);
        }
    game_board.setCellValue({apple_x_pos, apple_y_pos}, getAppleChar());
}
void Game::updateGameBoard()
{
    game_board.setCellValue(player_snake.getHeadPos(), player_snake.getHeadChar());
    for (Coordinates snake_body_element_coord : player_snake.getBodyPosDeque())
    {
        game_board.setCellValue(snake_body_element_coord, player_snake.getBodyChar());
    }
    game_board.setCellValue(player_snake.getPoppedElementPos(), ' ');
}
std::string Game::getBoardToPrint() {return game_board.parseBoardToString();}
