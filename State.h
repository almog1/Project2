//
// Created by almogg on 1/8/19.
//

#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

template<class T>
class State {
private:
    T myState;
    double cost; //how much cost to reach this state
    State<T> *from;//the state we came from to this state
public:
    //constructor
    State(T state) {
        this->myState = state;
    };

    //return the state T
    T getState() {
        return this->myState;
    };

    //change the from state
    void setFrom(State<T> *fromSt) {
        this->from = fromSt;
    };

    //return the from state of this state
    State<T> *getFrom() {
        return this->from;
    };

    //check if the states are equal
    bool equals(State<T> *state) {

    };

    ~State() {

    };
//get the state from this state
//   void setFromState(State<T> other); //set the from state - from where we got to this state
};

#endif //PROJECT2_STATE_H
