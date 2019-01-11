//
// Created by almogg on 1/9/19.
//

#ifndef PROJECT2_SEARCHABLE_H
#define PROJECT2_SEARCHABLE_H

#include "ISearchable.h"

template<class T>
class Searchable : public ISearchable<T> {
public:
    virtual State<T> *getInitializeState() = 0;

    virtual State<T> *getGoalState() = 0;

    virtual vector<State<T> *> getAllPossibleStates(State<T>* state) = 0;
};

#endif //PROJECT2_SEARCHABLE_H
