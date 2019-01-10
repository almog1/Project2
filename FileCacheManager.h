//
// Created by almogg on 1/3/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "OtherFunctions.h"
#include <string>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

template<class P, class S>
//cache manager of files
class FileCacheManager : public CacheManager<P, S> {
    //map between problem and solution
    // map<P, S> cache;
public:
    //constructor of a new file cache manager
    //get a path of the file
    FileCacheManager(string path, P prob) {
        //need to take all the solution from the file
        //prob.to_string();
        //prob.to_string();
        int num = 5;
        //std::string st = to_string(prob);

        string str = tempToString(prob);

        cout << str << endl;

    };

    bool isSolutionExist(P prob) override {


    };

    S getSolution(P prob) override {

    };

    bool saveSolution(P prob, S sol) override {

    };
    //write to file
//    ofstream ofs;
//    ofs.open(EMLOYEE_DATE, ofstream::out | ofstream::app);
//
//    ofs << this->emloyeeId << "," << (*this->date).getDate() << "\n";
//
//    ofs.close();


//READ
/*
 * MyReservation::MyReservation(string line) {
    stringstream temp(line);
    //create from the line
    string segment;
    std::vector<std::string> seglist;
    //split by ","
    while (getline(temp, segment, ',')) {
        seglist.push_back(segment);
    }
    this->myId = seglist.at(0);
    this->customerId = seglist.at(1);
    this->flightId = seglist.at(2);
    this->classes = checkClass(seglist.at(3));

    //take out the \n
    stringstream test(seglist.at(4));
    getline(test, segment, '\n');
    this->maxBaggage = stoi(segment);

}

void MyReservation::writeToFile() {
    ofstream ofs;
    ofs.open(RESERVATION_FILE, ofstream::out | ofstream::app);

    ofs << this->getID() << "," << this->customer->getID() << "," << this->flight->getID() << ","
        << this->getClass() << ","
        << this->getMaxBaggage() << "\n";

    ofs.close();

}
 *
 * */



/***READ
 *  string line;
    //check if the file exist
    ifstream ifs(RESERVATION_FILE);
    if (ifs.is_open()) {
        //take a string of line
        while (getline(ifs, line)) {
            //add to the list all the planes
            this->reservations.push_back(new MyReservation(line));
        }
        //take the last one id
        this->reservations.back()->setResId(this->reservations.back()->getID());

        //keep the old size of the list
        oldSize[RESERVATION_FLAG] = this->reservations.size();
        ifs.close();
    }
    //run on all the reservations and put id
    list<MyReservation *>::iterator it;

    //check not empty
    if (this->reservations.empty() == false) {
        //need to run on the reservations and change the customer and flight
        for (it = this->reservations.begin(); it != this->reservations.end(); it++) {
            //get the customer and flight by the ids
            (*it)->setCustomer(this->getCustomer((*it)->getCustomerId()));
            (*it)->setFlight(this->getFlight((*it)->getFlightId()));
        }
    }
    //flag of reading from employees
    isLoad[RESERVATION_FLAG] = true;
 * */
};

#endif //PROJECT2_FILECACHEMANAGER_H
