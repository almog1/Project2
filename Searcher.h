//
// Created by almogg on 1/9/19.
//

#ifndef PROJECT2_SEARCHER_H
#define PROJECT2_SEARCHER_H

#include "ISearcher.h"

//the Abstract class for Isearcher
template<class T>
class Searcher : public ISearcher<T> {
public:
    //todo - the 0 can be change - need to check - if need something else to be duplicate
    //method for the search function - search in the searchable
    //update the number of nodes and return string of the path
    virtual string search(ISearchable<T> *Isearchable) = 0;


    //return the ost of al the nodes - member
    virtual int getCostOfNodes() {
        return this->costOfAllNodes;
    }
};

#endif //PROJECT2_SEARCHER_H
