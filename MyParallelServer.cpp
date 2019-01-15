//
// Created by chagit on 1/15/19.
//

#include "MyParallelServer.h"
#define ZERO 0
#define ONE 1
#define TIME 5
//todo change the number
#define TV_SEC 100000
#define TV_USEC 0

void MyParallelServer::open(int port, ClientHandler *clientHandler) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    //call to socket() function
    sockfd = socket(AF_INET, SOCK_STREAM, ZERO);

    if (sockfd < ZERO) {
        perror("ERROR opening socket");
        exit(ONE);
    }

    //initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    //now bind the host address using bind() call
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < ZERO) {
        perror("ERROR on binding");
        exit(1);
    }

    int newsockfd, clilen;
    struct sockaddr_in cli_addr;

    struct params* info = new params;
    listen(sockfd, SOMAXCONN);
    clilen = sizeof(cli_addr);

    //using the timeout
    timeval timeout;
    timeout.tv_sec = TV_SEC;
    timeout.tv_usec = TV_USEC;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));


    while (true) {
        //accept actual connection from the client
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

        if (newsockfd < 0)	{
            if (errno == EWOULDBLOCK) {
                //time out!
                stop();
                break;
            }	else	{
                perror("other error");
                exit(3);
            }
        }

        //setting params
        info->sockfd = newsockfd;
        info->clientHandler = clientHandler;
        pthread_t thread;
        //creating thread and sending to handle client
        if (pthread_create(&thread, nullptr, MyParallelServer::parallelService,info) != 0){
            perror("thread failed");
        }
        //add the current thread to our vector
        closeServer.push_back(pair<pthread_t,int>(thread,newsockfd));
        threads.push_back(thread);
    }
}

void MyParallelServer::stop() {
    for (auto thread: this->threads) {
        pthread_join(thread, nullptr);
    }
    for(auto pair: this->closeServer){
        close(pair.first);
        //todo check how to close a tread
    }
}

//initialize the params of the server
void* MyParallelServer::parallelService(void* newParams) {
    struct params *info = (struct params*)newParams;
    int sockfd = info->sockfd;
    info->clientHandler->handleClient(sockfd);
}
