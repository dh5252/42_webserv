#include "kqueue.hpp"

Kqueue::Kqueue(){}
Kqueue::~Kqueue(){}

void Kqueue::initServer(const Config& config)
{
    /* init server socket and listen */
    int server_socket;
    struct sockaddr_in server_addr;

    if ((server_socket = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        throw "socket() Error\n";

    /*중복 처리?*/

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    // server_addr.sin_port = htons((*it)->getPort());

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        throw "bind() Error\n";
    if (listen(server_socket, 3) == -1)
        throw "listen() Error\n";
    fcntl(server_socket, F_SETFL, O_NONBLOCK);
    
    /* init kqueue */
    if ((kqueue_fd = kqueue()) == -1)
        throw "kqueue() Error\n";
}