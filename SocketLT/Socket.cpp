/* 
 * File:   Socket.cpp
 * Author: kleber
 * 
 * Created on 14 de Maio de 2015, 22:28
 */

#include "Socket.h"

namespace jk {

    Socket::Socket() {
    }

    Socket::Socket(const Socket& orig) {
    }

    Socket::~Socket() {
    }

    void Socket::create() {
        // create a socket
        socketfd = socket(AF_INET, SOCK_STREAM, 0);

        if (socketfd < 0)
            throw new SocketException("ERRO - create socket.");
    }
}