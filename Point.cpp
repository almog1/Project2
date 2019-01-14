//
// Created by almogg on 1/9/19.
//

#include "Point.h"

//constructor of a new point
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
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

//return 'true' if both points equals,'false' otherwise
bool Point::equal(Point other) {
    if ((this->getX() == other.getX()) && (this->getY() == other.getY()))return true;
    return false;
}

//return 'true' if the other point is left neighbor
bool Point::isLeftNeighbor(Point other) {
    if (this->x == other.getX() && this->y == (other.getY() - 1)) return true;
    return false;
}

//return 'true' if the other point is right neighbor
bool Point::isRightNeighbor(Point other) {
    if (this->x == other.getX() && this->y == (other.getY() + 1)) return true;
    return false;
}

//return 'true' if the other point is up neighbor
bool Point::isUpNeighbor(Point other) {
    if (this->x == (other.getX() - 1) && this->y == other.getY())return true;
    return false;
}

//return 'true' if the other point is down neighbor
bool Point::isDownNeighbor(Point other) {
    if (this->x == (other.getX() + 1) && this->y == other.getY())return true;
    return false;
}

//return true if one point equals to another one
bool Point::operator==(Point other) {
    if (this->x == other.x && this->y == other.y)return true;
    return false;
}

//get the type step that we did
string Point::getMove(Point other) {
    if (this->x == other.getX() && this->y > other.getY()) {
        return "R";
    }
    if (this->x == other.getX() && this->y < other.getY()) {
        return "L";
    }
    if (this->x > other.getX() && this->y == other.getY()) {
        return "D";
    }
    if (this->x < other.getX() && this->y == other.getY()) {
        return "U";
    }
}


