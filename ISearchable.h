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
    virtual State<T> *getInitializeState() = 0;

    //return the goal state - the detination state
    virtual State<T> *getGoalState() = 0;

    //return all the possible states - the structure in a vector
    virtual vector<State<T> *> getAllPossibleStates(State<T> *currentState) = 0;

    //return all the possible states in a vetcor
    virtual vector<State<T> *> getAllPossibleStates();

    //todo - check if need pointer to vector
};

#endif //PROJECT2_ISEARCHABLE_H
