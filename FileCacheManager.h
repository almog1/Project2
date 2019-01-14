//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "OtherFunctions.h"
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

template<class P, class S>
//cache manager of files
class FileCacheManager : public CacheManager<P, S> {
    //map between problem and solution
    map<P, S> cache;
    string path;
    int oldSize;
public:
    //constructor of a new file cache manager
    //get a path of the file
    //put in the map all the cache from the file
    FileCacheManager(string path, P prob) {
        this->path = path;
//
//        //read from file
//        P problem;
//        S solution;
//        this->oldSize = 0;
//
//        //check if the file exist
//        ifstream ifs(this->path);
//        if (ifs.is_open()) {
//            //while file isn't over
//            while (!ifs.eof()) {
//                //problem and solution seperate by '$'
//                //take the problem
//                ifs >> problem;
//                ifs >> solution;
//
//                cache.insert(pair<P,S>(problem,solution));
//            }
//
//            this->oldSize = cache.size(); //save the old size
//
//            //close the file
//            ifs.close();
//        }
    };

    bool isSolutionExist(P prob) override {
        //check the map
        typename ::map<P,S>::iterator it = this->cache.find(prob);

        //if its not the end - have the solution
        if(it!=this->cache.end()){
            return true; //the solution exist
        }else{
            return false; // solution not exist
        }

    };

    S getSolution(P prob) override {
        typename ::map<P,S>::iterator it = this->cache.find(prob);

        //if its not the end - have the solution
        if(it!=this->cache.end()){
            return (*it).second; // the solution from the table
        }
    };

    //save all the problems with solution that wasnt in the file
    bool saveSolution(P prob, S sol) override {
        //put it in the map
        //todo - maybe don't need it becaue use juse once
//        this->cache.insert(pair<P,S>(prob,sol));
//
//        ofstream ofs;
//
//        //open the file for writing without delete the old
//        ofs.open(path, ofstream::out | ofstream::app);
//
//        //put the prob and solution in the file
//        //to be working - have to make sure every prob and sol have << operator
//        ofs << prob << " " << sol << "\n";
//
//        //close the file
//        ofs.close();
    };
};

#endif //PROJECT2_FILECACHEMANAGER_H
