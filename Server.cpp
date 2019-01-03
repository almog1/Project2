//
// Created by almogg on 1/3/19.
//

#include <netinet/in.h>
#include <strings.h>
#include "Server.h"

#define ZERO 0
#define ONE 1
#define TIME 5

struct MyArgs{
    bool running = true;
};

int openSocket(int port);

void *listening(void *args);

void server_side::Server::open(int port, ClientHandler clientHandler) {

    struct MyArgs* params = new MyArgs();

    //open the socket
    this->sockfd = openSocket(port);
    //open thread for the listening to the client
    pthread_t id;
    pthread_create(&id, nullptr, listening, params);
}

void server_side::Server::close() {

}

int openSocket(int port) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, ZERO);

    //check if open socket succeeded
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

    //now bind the host address using bind call
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < ZERO) {
        perror("Error on binding");
        exit(ONE);
    }

    /**
     * now start listening to the client. here process will go in sleep mode and will wait
     * for the incoming connection
     */
    listen(sockfd, TIME);
    clilen = sizeof(cli_addr);

    //accept actual connection from the client
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
//    SymbolTable *symbolTable = SymbolTable::getInstance();
//    symbolTable->setServerId(newsockfd);
    //cout << "hii" << endl;

    if (newsockfd < ZERO) {
        perror("ERROR on accept");
        exit(ONE);
    }
    return sockfd;
}

void *listening(void *args) {
    char buffer[1024];
    struct MyArgs *params = (struct MyArgs *) args;
    bool isRun = params->running;
    //if connections is established then start communicating
    bzero(buffer, 1024);
    //SymbolTable *symbolTab = SymbolTable::getInstance();
    int n;

    string buff = "";
    string leftOvers = "";

    SymbolTable *table = SymbolTable::getInstance();
    vector <string> paths = table->getNames();
    //sleep fot this->hz
    while (running) {

        bzero(buffer, 256);
        n = read(table->getServerId(), buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            running = false;
            // exit(1);
        }

        vector <string> info;
        size_t pos = 0;
        string delimiter = ",";
        string delimiter2 = "\n";
        buff += buffer;
        pos = buff.find(delimiter2);
        leftOvers += buff.substr((0, pos));

        // to remove the \n from the beginning of the string
        leftOvers = leftOvers.substr(1);
        buff.erase(pos + delimiter2.length() - 1);
        pos = 0;
        while ((pos = buff.find(delimiter)) != string::npos) {
            info.push_back(buff.substr(0, pos));
            buff.erase(0, pos + delimiter.length());
        }
        info.push_back(buff.substr(0, pos));
        buff = "";

        for (int i = 0; i < paths.size(); ++i) {
            table->addValueByPathIndex(i, stod(info[i]));
        }
        // table->setValuesInSymbolTable();

        buff += leftOvers;
        leftOvers = "";

        sleep(10 / 1000);
    }
}