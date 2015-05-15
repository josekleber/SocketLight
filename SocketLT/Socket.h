/* 
 * File:   Socket.h
 * Author: kleber
 *
 * Created on 14 de Maio de 2015, 22:28
 */

#ifndef SOCKET_H
#define	SOCKET_H

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <exception>

namespace jk {

    using namespace std;

    /**
     * The first version this class accepty only IPV4 and TCP connections.
     */
    class Socket {
    public:
        Socket();
        Socket(const Socket& orig);
        virtual ~Socket();

        /** create a new socket */
        void create();
        /** bind to socket */
        void bind();
        /** listen for connect */
        void listen();
    private:
        /** socket id */
        int socketfd;
        /** port number */
        int portnu;
        /** server address information */
        struct sockaddr_in server_addr;
        /** remote address information */
        struct sockaddr_in client_addr;
    };

    /**
     * Exception from a socket class
     */
    class SocketException : public exception {
    public:

        SocketException(const char* errMessage) : errMessage_(errMessage) {
        }
        // overriden what() method from exception class
        const char* what() const throw () {
            return errMessage_;
        }

    private:
        const char* errMessage_;
    };
}

#endif	/* SOCKET_H */