//
// Created by almogg on 1/7/19.
//

#ifndef PROJECT2_STRINGREVERSER_H
#define PROJECT2_STRINGREVERSER_H

#include "Solver.h"
#include <string>

using std::string;
template <class P,class S>
class StringReverser : public Solver<string, string> {
public:
    StringReverser(){

    };

//    string solve(string p){
//      //  need to revers the string
//        int i = 0;
//        string reverse = "";
//        //run on every char in the string and put from end to start
//        for (int i = p.length() - 1; i >= 0; i--) {
//            //take from here and put in the revrs string
//            reverse = reverse + p.at(i);
//        }
//        //return the new string
//        return reverse;
//    };

};

#endif //PROJECT2_STRINGREVERSER_H
