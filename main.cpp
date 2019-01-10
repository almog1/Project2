#include <iostream>
//#include <string>
//#include "MySerialServer.h"
#include "State.h"
#include "StringReverser.h"
//#include "Solver.h"
#include "Point.h"
#include "FileCacheManager.h"

using namespace std;

int main() {
    //MySerialServer mySerialServer = new Server();
    std::cout << "Hello, World!" << std::endl;
    Point *point = new Point(4, 3, 15);
    cout << point->getX() << endl;

    State<string> *st = new State<string>("almog");
    State<string> *st2 = new State<string>("chagit");
    State<string> *st3 = new State<string>("3");
    State<string> *st4 = new State<string>("3");
    st->setFrom(st2);
    st2->setFrom(st3);
    State<string> *fromState = st->getFrom();
    State<string> *from2 = st->getFrom()->getFrom();

    if (st4->equals(st3) == true) {
        cout << "equal" << endl;
    }
    cout << st->getState() << endl;
    cout << fromState->getState() << endl;
    cout << from2->getState() << endl; //need to be 3

    Solver<string, string> *stringRe = new StringReverser();
    string stBe = "hello";
    cout << "before " << stBe << endl;
    string stN = stringRe->solve(stBe);
    cout << "after " << stN << endl;


    //CacheManager<string, int> *ch = new FileCacheManager<string, int>("test.txt", 2);
    CacheManager<string, string> *cacheManager = new FileCacheManager<string,string>("/home/almogg/CLionProjects/Project2/testFile","check");
    cacheManager->saveSolution("problem1","solution1");
    cacheManager->saveSolution("problem2","solution2");
   if( cacheManager->isSolutionExist("problem1") == true){
       cout<<"solution from cache is "<<cacheManager->getSolution("problem1")<<endl;
   }
    if( cacheManager->isSolutionExist("problem2") == true){
        cout<<"solution from cache is "<<cacheManager->getSolution("problem2")<<endl;
    }


    return 0;
}