//
// Created by almogg on 1/11/19.
//

#ifndef PROJECT2_BFS_H
#define PROJECT2_BFS_H

#include "Searcher.h"
#include <list>
#include <queue>

using std::list;

template<class T>
class BFS : public Searcher<T> {

public:
    string search(ISearchable<T> *Isearchable) override {
        list<State<T> *> open;
        list<State<T> *> close;
        State<T> *state;

        string path;

        open.push_back(Isearchable->getInitializeState());

        typename list<State<T> *>::iterator it;

        //while the queue isn't empty
        while (!open.empty()) {
            state = open.front(); //take the first one
            close.push_back(state); //to add to path been
            open.pop_front();

            //check if its the goal
            if (state->equals(Isearchable->getGoalState())) {
                return "path";
            }
            vector<State<T> *> next;
            next = Isearchable->getAllPossibleStates(state);
            for (it = next.begin(); it != next.end(); it++) {
                //if not in closed list
                if (find(close.begin(), close.end(), (*it)) == close.end()) {
                    //set the from
                    (*it)->setFrom(state); // state wiil be the "from" of this state

                    //its not in the closed list
                    //   close.push_back(*it);
                    open.push_back(*it);
                }
            }
        }
    }
};

#endif //PROJECT2_BFS_H
