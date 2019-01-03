//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_SERVER_H
#define PROJECT2_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server {
        int sockfd;
        bool running;
    public:
        //todo - make sure not needded virtual

        //open the server in the port and wait for the customer - connection
        void open(int port, ClientHandler clientHandler);

        //close the server
        void close();
    };
}

#endif //PROJECT2_SERVER_H
