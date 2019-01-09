//
// Created by almogg on 1/9/19.
//

#ifndef PROJECT2_BESTFIRSTSEARCH_H
#define PROJECT2_BESTFIRSTSEARCH_H

#include "Searcher.h"

//algoritm of searcher
template<class T>
class BestFirstSearch : public Searcher<T> {
public:
    //we want to search by this searcher  in the searchable
    string search(ISearchable<T> *Isearchable)  {

    }
};

#endif //PROJECT2_BESTFIRSTSEARCH_H
