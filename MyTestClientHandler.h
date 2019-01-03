//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_MYTESTCLIENTHANDLER_H
#define PROJECT2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
    //solver to solve this client
    Solver<int, string> solver; //todo - change to real solution and problem instead of int and string

    //cache manager that the client will use
    CacheManager *cacheManager;
};

#endif //PROJECT2_MYTESTCLIENTHANDLER_H
