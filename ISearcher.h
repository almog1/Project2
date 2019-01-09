//
// Created by almogg on 1/9/19.
//

#ifndef PROJECT2_ISEARCHER_H
#define PROJECT2_ISEARCHER_H

#include "ISearchable.h"
#include <string>

using std::string;

//interface for all the methods of searcher
template<class T>
class ISearcher {
protected:
    int costOfAllNodes = 0;
public:
    //method for the search function - search in the searchable
    //update the number of nodes and return string of the path
    virtual string search(ISearchable<T> *Isearchable);

    //return the total cost of all the nodes in the path -
    // all the nodes evaluated
    virtual int getCostOfNodes();
};

#endif //PROJECT2_ISEARCHER_H
