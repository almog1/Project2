//
// Created by almogg on 1/9/19.
//

#include "Point.h"

//constructor of a new point
Point::Point(int x, int y, double val) {
    this->x = x;
    this->y = y;
    this->val = val;
}

Point::~Point() {

}

int Point::getX() const {
    return x;
}

void Point::setX(int x) {
    Point::x = x;
}

int Point::getY() const {
    return y;
}

void Point::setY(int y) {
    Point::y = y;
}

double Point::getVal() const {
    return val;
}

void Point::setVal(double val) {
    Point::val = val;
}
