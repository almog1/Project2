//
// Created by almogg on 1/9/19.
//

#ifndef PROJECT2_ISEARCHABLE_H
#define PROJECT2_ISEARCHABLE_H

#include "State.h"
#include <vector>

using std::vector;

//interface for a thing to search in it
//the functional of the search problem
template<class T>
class ISearchable {
public:
    //get the initialize state - the source
    virtual State<T> *getInitializeState();

    //return the goal state - the detination state
    virtual State<T> *getGoalState();

    //return all the possible states in a vetcor
    virtual vector<State<T> *> getAllPossibleStates();

    //todo - check if need pointer to vector
};

#endif //PROJECT2_ISEARCHABLE_H
