#include <iostream>
#include <string>
//#include "MySerialServer.h"
#include "State.h"
#include "StringReverser.h"
//#include "Solver.h"
#include "Point.h"

using namespace std;

int main() {
    //MySerialServer mySerialServer = new Server();
    std::cout << "Hello, World!" << std::endl;
    Point * point = new Point(4,3,15);
    cout<<point->getX()<<endl;

    State<string> *st = new State<string>("almog");
    State<string> *st2 = new State<string>("chagit");
    State<string> *st3 = new State<string>("3");
    st->setFrom(st2);
    st2->setFrom(st3);
    State<string> *fromState = st->getFrom();
    State<string> *from2 = st->getFrom()->getFrom();

    cout << st->getState() << endl;
    cout << fromState->getState() << endl;
    cout << from2->getState() << endl; //need to be 3

    Solver<string, string>* stringRe;

//    string stN = stringRe->solve("almog");
//    cout<<stN<<endl;
    //= new StringReverser<string,string>();
    //= new StringReverser();
    //string str = "almog";
//    string * str;
//    *str = "almog";
//    string *newSt = stringRe->solve(str);
    return 0;
}