#include "game.hpp"
#include "socket_utils.hpp"
#include <iostream>
#include <unistd.h>
#include "start.hpp"

void startClient()
{
    int clientSocket = createClientSocket("192.168.1.100", 7777);
    Game game;
    int currentPlayer = 2;
    while (true)
    {
        game.displayBoard();
        if (currentPlayer == 2)
        {
            std::cout << "Your move (1-7): ";
            int column;
            std::cin >> column;
            char buffer[256];
            buffer[0] = column + '0';
            write(clientSocket, buffer, sizeof(buffer));
            game.makeMove(currentPlayer, column - 1);
            currentPlayer = 1;
        }
        else
        {
            char buffer[256];
            read(clientSocket, buffer, sizeof(buffer));
            int column = buffer[0] - '0';
            game.makeMove(currentPlayer, column - 1);
            currentPlayer = 2;
        }
        int winner = game.checkWin();
        if (winner != 0)
        {
            game.displayBoard();
            std::cout << "Player " << winner << " wins!" << std::endl;
            break;
        }
    }
    close(clientSocket);
}