//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_MYSERIALSERVER_H
#define PROJECT2_MYSERIALSERVER_H

#include "Server.h"

using namespace server_side;

class MySerialServer : public Server {
    void open(int port, ClientHandler clientHandler);

    void close();
};

#endif //PROJECT2_MYSERIALSERVER_H
