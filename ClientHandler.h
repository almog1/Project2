//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_CLIENTHANDLER_H
#define PROJECT2_CLIENTHANDLER_H

#include <iostream>

using namespace std;

class ClientHandler {
public:
    //get istream - to read the meassage from it
    //get ostream to write the mesaage to it
    virtual void handleClient(istream &input, ostream &output);
};

#endif //PROJECT2_CLIENTHANDLER_H
