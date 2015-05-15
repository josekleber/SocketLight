/* 
 * File:   SocketTest.cpp
 * Author: kleber
 *
 * Created on 15/05/2015, 02:05:51
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include "Socket.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;

void testSocket() {
    string serverIP = "127.0.0.1";
    int portnu = 3000;
    try {
        jk::Socket socket(serverIP, portnu);
    } catch (jk::SocketException &e) {
        std::cout << "%TEST_FAILED% time=0 testname=testSocket (SocketTest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% SocketTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testSocket (SocketTest)" << std::endl;
    testSocket();
    std::cout << "%TEST_FINISHED% time=0 testSocket (SocketTest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

