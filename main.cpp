#include <iostream>
#include "game.hpp"
#include "socket_utils.hpp"
#include "start.hpp"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <server|client>" << std::endl;
        return 1;
    }
    std::string mode = argv[1];
    if (mode == "server")
    {
     void extern  startServer();
    }
    else if (mode == "client")
    {
       void extern startClient();
    }
    else
    {
        std::cerr << "Invalid mode: " << mode << std::endl;
        return 1;
    }
    return 0;
}