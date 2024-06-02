#include "game.hpp"
#include "socket_utils.hpp"
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <unistd.h>
#include "start.hpp"

std::mutex coutMutex;
void handleClient(int clientSocket)
{
    Game game;
    int currentPlayer = 1;
    while (true)
    {
        game.displayBoard();
        if (currentPlayer == 1)
        {
            std::cout << "Your move (1-7): ";
            int column;
            std::cin >> column;
            if (!game.makeMove(currentPlayer, column - 1))
            {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }
            currentPlayer = 2;
        }
        else
        {
            char buffer[256];
            read(clientSocket, buffer, sizeof(buffer));
            int column = buffer[0] - '0';
            game.makeMove(currentPlayer, column - 1);
            currentPlayer = 1;
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
void startServer()
{
    int serverSocket = createServerSocket(7777);
    std::vector<std::thread> threads;
    while (true)
    {
        int clientSocket = acceptClientConnection(serverSocket);
        threads.emplace_back(handleClient, clientSocket);
    }
    for (auto &th : threads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}