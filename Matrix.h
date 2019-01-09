//
// Created by almogg on 1/9/19.
//

#ifndef PROJECT2_MATRIX_H
#define PROJECT2_MATRIX_H

#include "Searchable.h"

template<class T>
class Matrix : public Searchable<T> {
public:
    State<T> *getInitializeState() override {
        return nullptr;
    }

    State<T> *getGoalState() override {
        return nullptr;
    }

    vector<State<T> *> getAllPossibleStates() override {
        return vector<State<T> *>();
    }
};

#endif //PROJECT2_MATRIX_H
