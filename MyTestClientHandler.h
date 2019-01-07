//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_MYTESTCLIENTHANDLER_H
#define PROJECT2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

//template <class P,class S>
class MyTestClientHandler : public ClientHandler {
    //solver to solve this client
    Solver<class P,class S> solver; //todo - change to real solution and problem instead of int and string
    //cache manager that the client will use
    CacheManager<P,S> cacheManager;
public:
    void handleClient(istream &input, ostream &output);

};

#endif //PROJECT2_MYTESTCLIENTHANDLER_H
