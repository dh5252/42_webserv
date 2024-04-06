#ifndef KQUEUE_HPP
# define KQUEUE_HPP

#include <iostream>
#include <fcntl.h>
/* events */
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <sys/socket.h>

/* network */
#include <arpa/inet.h>
#include <map>
#include <vector>
#include <string>

class Config;
class Client;
class Server;

class Kqueue {
private:
    int kqueue_fd;
    std::vector<Server*> servers;

public:
    Kqueue();
    ~Kqueue();

    void initServer(const Config& config);
    void runServer();
    void connectClient(int server_fd);
    void disconnectClient(const Client& client);
};

#endif