#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H
#include <string>
int createServerSocket(int port);
int acceptClientConnection(int serverSocket);
int createClientSocket(const std::string &ipAddress, int port);
#endif // SOCKET_UTILS_H