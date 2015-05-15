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
#include <cassert>
#include <exception>

namespace jk {

    using namespace std;

    /**
     * The first version this class accepty only IPV4 and TCP connections.
     */
    class Socket {
    public:
        Socket(string serverIP, int portnu);
        Socket(const Socket& orig);
        virtual ~Socket();

        /** listen for connect  */
        void run();
        
    private:
        /** socket id */
        int socketfd, socketcli;
        /** port number */
        int portnu;
        /** server IPV4 */
        string serverIP;
        /** server address information */
        struct sockaddr_in server_addr;
        /** remote address information */
        struct sockaddr_in client_addr;
        /** socket client len*/
        socklen_t clientlen;
        
        /** create a new socket */
        void create();
        /** bind to socket server */
        void bindServer();
        /** close connection */
        void closeConnection(int socketID);
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