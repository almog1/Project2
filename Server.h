//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_SERVER_H
#define PROJECT2_SERVER_H

#include "ClientHandler.h"

namespace server_side{
    class Server{
    public:
        //open the server in the port and wait for the customer - connection
        virtual void open(int port,ClientHandler clientHandler);
        //close the server
        virtual void close();
    };
}

#endif //PROJECT2_SERVER_H
