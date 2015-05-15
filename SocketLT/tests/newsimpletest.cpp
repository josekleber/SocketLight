/* 
 * File:   newsimpletest.cpp
 * Author: kleber
 *
 * Created on 15/05/2015, 00:11:30
 */

#include <stdlib.h>
#include <iostream>
#include "Socket.h"

/*
 * Simple C++ Test Suite
 */

void testCreate() {
    jk::Socket socket;
    socket.create();
    if (false /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCreate (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testCreate (newsimpletest)" << std::endl;
    testCreate();
    std::cout << "%TEST_FINISHED% time=0 testCreate (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

