//
// Created by almogg on 1/10/19.
//

#ifndef PROJECT2_DFS_H
#define PROJECT2_DFS_H

#include "Searcher.h"
#include <stack>
#include<iostream>
#include<list>

using std::stack;
using std::list;


template<class T>
class DFS : public Searcher<T> {
    stack<State<T>> currentNodes;
    string path;
    vector<State<T> *> openVector;
    vector<State<T> *> closedVector;
    bool found;
public:
    string dfsSeacrhRecurs(ISearchable<State<T>> *Isearchable) {
        //as long the open vector have items
        while (this->openVector.empty() == false) {
            State<T> *state = this->openVector.pop_back(); //take from the open
            this->closedVector.push_back(state); //add it to the closed list
            this->costOfAllNodes += state->valueOfState(); //add the value of this state to the values

            //todo - if the value is needed - int value - maybe need state val
            //    this->costOfAllNodes += state->getState(); //add its cost

            //check if it is the goal state
            if (state->equals(Isearchable->getGoalState())) {
                //return the path
                this->found = true;
                return "path";
                //maybe the path is the closed list
                //todo path return need to check where function for it
            } else {
                //take all the possible states he can go to
                vector<State<T> *> statesToOpen = Isearchable->getAllPossibleStates(state);

                typename vector<State<T> *>::iterator it;
                for (it = statesToOpen.begin(); it != statesToOpen.end(); it++) {
                    //check its not in the colsed list - alredy been there
                    if (find(this->closedVector.begin(), this->closedVector.end(), (*it)) == this->closedVector.end()) {
                        //its not in the closed list
                        //take the state and do it in this state
                        return dfsSeacrhRecurs(Isearchable);
                    }
                }
            }
        }
        //if not found path to there
        if (this->found == false) {
            return "-1";
        }
    }

    //search in the searchable
    string search(ISearchable<T> *Isearchable) override {
        //take the init state from the searchable
        //vector<State<T> *> openList;
        this->openVector.push_back(Isearchable->getInitializeState());
        this->found = false;
        string solPath = dfsSeacrhRecurs(Isearchable);

    }
};

#endif //PROJECT2_DFS_H
