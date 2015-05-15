/* 
 * File:   Socket.cpp
 * Author: kleber
 * 
 * Created on 14 de Maio de 2015, 22:28
 */

#include "Socket.h"

namespace jk {

    Socket::Socket(string serverIP, int portnu) {
        assert(!serverIP.empty());
        assert(portnu);

        this->serverIP = serverIP;
        this->portnu = portnu;

        create();

        bindServer();
    }

    Socket::Socket(const Socket& orig) {
    }

    Socket::~Socket() {
        // has connection
        if (socketfd > 0)
            closeConnection(socketfd);
    }

    void Socket::create() {
        // create a socket
        socketfd = socket(AF_INET, SOCK_STREAM, 0);

        if (socketfd < 0)
            throw new SocketException("ERROR - create socket failed.");
    }

    void Socket::bindServer() {

        // clear data struct 
        bzero((char *) &server_addr, sizeof (server_addr));

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(serverIP.c_str());
        // convert between host and network byte order
        server_addr.sin_port = htons(portnu);

        if (bind(socketfd, (struct sockaddr *) &server_addr, sizeof (server_addr)) < 0)
            throw new SocketException("ERROR - bind failed.");

    }

    void Socket::closeConnection(int socketID) {
        close(socketID);
    }

    void Socket::run() {

        //  In kernels before 2.4.25 SOMAXCONN is 128
        listen(socketfd, SOMAXCONN);

        clientlen = sizeof (client_addr);

        // TODO - put a stop point
        while (true) {

            printf("wait connection...\n");

            // listen for connections
            socketcli = accept(socketfd, (struct sockaddr*) &client_addr, &clientlen);

            if (socketcli < 0)
                throw new SocketException("ERROR - acept connection failed.");

            int pid = fork();
            switch (pid) {
                case 0:
                    this->onRead();
                    closeConnection(socketcli);
                    break;
                case -1:
                    throw new SocketException("ERRO - fork for read socket failed.");
                default:
                    printf("got connection from IP %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            }

        }

        closeConnection(socketfd);
    }
}