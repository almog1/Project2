//
// Created by almogg on 1/9/19.
//

#ifndef PROJECT2_MATRIX_H
#define PROJECT2_MATRIX_H

#include "Searchable.h"
#include "Point.h"
#include <vector>
using std::vector;

class Matrix : public Searchable<Point> {
public:
    Matrix();

    //the constructor of the matrix
    Matrix(vector<State<Point>*> structure, State<Point>* initialState,State<Point>* goal){
        this->goalState=goal;
        this->initialState=initialState;
        this->structure=structure;
    }

    //get the possible moves in a current state of the matrix
    vector<State<Point> *> getAllPossibleStates(State<Point> *currentState) override;

    string getRoute() override;

    double getHuristic(State<Point> *start, State<Point> *goal) override;
};

#endif //PROJECT2_MATRIX_H