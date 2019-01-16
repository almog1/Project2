#include <iostream>
#include <string>
#include "Headers.h"

//todo add a class of headers
using namespace std;

int main(int argc, char *argv[]) {
    int port;
    if (argc >= 1) {
        port = stoi(argv[1]);

        MySerialServer *d = new MySerialServer();
        ISearchable<Point> *mat = new Matrix();
        //Solver<ISearchable<Point>*, string> *matrixR = new SolverBestSearch<Point>(new DFS<Point>());
        Solver<ISearchable<Point> *, string> *matrixR = new SolverBestSearch<Point>(new AStarSearch<Point>());
        //CacheManager<ISearchable<Point>*, string> *cacheManager
        FileCacheManager *cacheManager = new FileCacheManager(
                "/home/almogg/CLionProjects/Project2/testFile");
        ClientHandler *ds = new MyClientHandler<ISearchable<Point> *, string>(matrixR, cacheManager);
        d->open(port, ds);

        while (true) {}
    }
    return 0;
}