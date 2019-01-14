//
// Created by almogg on 1/9/19.
//

#include "Matrix.h"

//constructor
//Matrix::Matrix(vector<State<Point> *> structure, State<Point> *initialState, State<Point> *goal) {
//    this->goalState=goal;
//    this->initialState=initialState;
//    this->structure=structure;
//    this->setGoalState(goal);
//    this->setInitialState(initialState);
//    this->setStructure(structure);
//}

//return a list of all the neighbors possible in the next step
vector<State<Point> *> Matrix::getAllPossibleStates(State<Point> *currentState) {
    vector<State<Point> *> possible;
    for (State<Point> *futureState : structure) {
        //state is the point we check according to him on our current state point
        if (futureState->getState().isLeftNeighbor(currentState->getState()) ||
            futureState->getState().isRightNeighbor(currentState->getState()) ||
            futureState->getState().isUpNeighbor(currentState->getState()) ||
            futureState->getState().isDownNeighbor(currentState->getState())) {
            if (futureState->getCost() != -1) {
                possible.push_back(futureState);
            }
        }
    }
    return possible;
}

Matrix::Matrix() {}

string Matrix::getRoute() {
    State<Point> *current = getGoalState();
    string path = "}";
    //end when getting to the start
    while (current->getFrom() != nullptr) {
        //go on the state of your structure
        for (State<Point> *state:structure) {
            if (state->getFrom() != nullptr) {
                //find father node of current
                if (current->getFrom()->equals(state)) {
                    path = "," + current->getState().getMove(state->getState()) + path;
                    break;
                }
            }
        }
        current = current->getFrom();
        //when the current is the initial state
        if (current->getFrom()->equals(getInitializeState())) {
            break;
        }
    }
    //find the last move to the initial state
    path = "{" + current->getState().getMove(getInitializeState()->getState()) + path;
    return path;
}
