#include <iostream>
#include <string>
#include "State.h"
#include "StringReverser.h"
#include "Solver.h"
#include "Point.h"
#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MyClientHandler.h"
#include "Matrix.h"
#include "SolverBestSearch.h"
#include "DFS.h"
#include "BFS.h"
#include "MyParallelServer.h"

//todo add a class of headers
using namespace std;

int main() {

    //Point* p = new Point(2,3);
    //std::cout<<*p<<std::endl;
    MyParallelServer *d = new MyParallelServer();
    ISearchable<Point> * mat = new Matrix();
 //   Solver<ISearchable<Point>*, string> *matrixR = new SolverBestSearch<Point>(new DFS<Point>());
    Solver<ISearchable<Point>*, string> *matrixR = new SolverBestSearch<Point>(new DFS<Point>());

    CacheManager<ISearchable<Point>*, string> *cacheManager = new FileCacheManager<ISearchable<Point>*, string>(
            "/home/chagit/CLionProjects/Project22/testFile", mat);
    ClientHandler *ds = new MyClientHandler<ISearchable<Point>*, string>(matrixR, cacheManager);
    d->open(5400, ds);

    while (true) {}
    return 0;
}