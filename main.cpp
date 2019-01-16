#include <iostream>
#include <string>
#include "Headers.h"

//todo add a class of headers
using namespace std;

int main() {

    MySerialServer *d = new MySerialServer();
    ISearchable<Point> * mat = new Matrix();
    //Solver<ISearchable<Point>*, string> *matrixR = new SolverBestSearch<Point>(new DFS<Point>());
    Solver<ISearchable<Point>*, string> *matrixR = new SolverBestSearch<Point>(new AStarSearch<Point>());
    //CacheManager<ISearchable<Point>*, string> *cacheManager
     FileCacheManager *cacheManager= new FileCacheManager(
            "/home/chagit/CLionProjects/Project22/testFile");
    ClientHandler *ds = new MyClientHandler<ISearchable<Point>*, string>(matrixR, cacheManager);
    d->open(5400, ds);

    while (true) {}
    return 0;
}