//
// Created by almogg on 1/11/19.
//

#ifndef PROJECT2_BFS_H
#define PROJECT2_BFS_H

#include "Searcher.h"
#include <list>
#include <queue>
#include <iostream>

using std::list;
using std::queue;

template<class T>
class BFS : public Searcher<T> {

public:
    BFS() {
        Searcher<T>::nodesNumer = 0;
    }

    //search in the Isearchable
    string search(ISearchable<T> *Isearchable) override {

        State<T> *state = Isearchable->getInitializeState(); //take the first - the init state
        typename vector<State<T> *>::iterator it;
        bool isFound = false;

        queue<State<T> *> openQueue; //queue for the open
        openQueue.push(state);
        vector<State<T> *> closeV;

        //as long as the queue not empty and didnt found the goal state
        while ((openQueue.empty() == false) && (isFound == false)) {

            //take the first - the one in the front
            state = openQueue.front(); //look at the next in the queue
            openQueue.pop();//take it out

            std::cout<<state->getState()<<std::endl;

            //check if it is the goal state
            if (state == Isearchable->getGoalState()) {
                //change the boolian of the found
                isFound = true;
            }

            //check if not in the close vector
            if (find(closeV.begin(), closeV.end(), state) == closeV.end()) {
                Searcher<T>::nodesNumer++;
                //run on all the negibors and add them
                vector<State<T> *> statesToOpen = Isearchable->getAllPossibleStates(state);

                typename vector<State<T> *>::iterator it;
                //run on all the negibhors
                for (it = statesToOpen.begin(); it != statesToOpen.end(); it++) {
                    //just if not in close list
                    if (find(closeV.begin(), closeV.end(), *it) == closeV.end()) {
                        //changed the from
                        (*it)->setFrom(state);
                        //take the state and do it in this state
                        openQueue.push(*it);//push the neigbhor to the queue
                    }
                }
               //put the state in the closed vector - the visited
               closeV.push_back(state);
            }
        }
        return Isearchable->getRoute();
    }
};

#endif //PROJECT2_BFS_H
