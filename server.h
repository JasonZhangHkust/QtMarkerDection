#ifndef SERVER_H
#define SERVER_H
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <string>
#include <iostream>
#include <vector>
#include <string>


class Server {
public:
    Server(int PORT, bool BroadcastPublically = false);
    bool ListenForNewConnection();
    void update(std::string s, int ID);
    std::vector<std::string> orderNew;
    std::vector<std::string> order;
    HANDLE h;
private:
    static void ClientHandlerThread(int ID);
    void string2char2(std::string order);
private:
    SOCKET Connections[5];
    int TotalConnections = 0;
    SOCKADDR_IN addr; //Address that we will bind our listening socket to
    int addrlen = sizeof(addr);
    SOCKET sListen;
    bool flag[5];
    BYTE y[8];
};
static Server * serverptr;

#endif // SERVER_H
