#include "game.hpp"
#include <iostream>
Game::Game()
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            board[i][j] = ' ';
        }
    }
}
void Game::displayBoard()
{
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            std::cout << "|" << board[i][j];
        }
        std::cout << "|" << std::endl;
    }
    std::cout << " 1 2 3 4 5 6 7" << std::endl;
}
bool Game::makeMove(int player, int column)
{
    if (column < 0 || column >= 7)
        return false;
    char mark = player == 1 ? 'S' : 'C';
    for (int i = 5; i >= 0; --i)
    {
        if (board[i][column] == ' ')
        {
            board[i][column] = mark;
            return true;
        }
    }
    return false;
}
int Game::checkWin()
{
    // Check horizontal
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3])
            {
                return board[i][j] == 'S' ? 1 : 2;
            }
        }
    }
    // Check vertical
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j])
            {
                return board[i][j] == 'S' ? 1 : 2;
            }
        }
    }
    // Check diagonal /
    for (int i = 3; i < 6; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j] != ' ' && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] &&
                board[i][j] == board[i - 3][j + 3])
            {
                return board[i][j] == 'S' ? 1 : 2;
            }
        }
    }
    // Check diagonal
    for (int i = 3; i < 6; ++i)
    {
        for (int j = 3; j < 7; ++j)
        {
            if (board[i][j] != ' ' && board[i][j] == board[i - 1][j - 1] && board[i][j] == board[i - 2][j - 2] &&
                board[i][j] == board[i - 3][j - 3])
            {
                return board[i][j] == 'S' ? 1 : 2;
            }
        }
    }
    return 0;
}