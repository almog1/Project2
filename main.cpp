#include <iostream>
#include <string>
#include "MySerialServer.h"
#include "State.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"

using namespace std;

int main() {
    //MySerialServer mySerialServer = new Server();
//    std::cout << "Hello, World!" << std::endl;
//    State<string> *st = new State<string>("almog");
//    State<string> *st2 = new State<string>("chagit");
//    State<string> *st3 = new State<string>("3");
//    st->setFrom(st2);
//    st2->setFrom(st3);
//    State<string> *fromState = st->getFrom();
//    State<string> *from2 = st->getFrom()->getFrom();
//
//    cout << st->getState() << endl;
//    cout << fromState->getState() << endl;
//    cout << from2->getState() << endl; //need to be 3

    MySerialServer* d = new MySerialServer();
    //Solver<ISearchable<Point>*,string>* solver = new SearcherSolver(new BestFirstSearch<Point>());
    CacheManager<string,string>* fileCacheManager;
    ClientHandler* ds = new MyTestClientHandler<string,string>(nullptr, fileCacheManager);
    d->open(5400,ds);

    while(true){}

    return 0;
}