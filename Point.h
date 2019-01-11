//
// Created by almogg on 1/9/19.
//

#ifndef PROJECT2_POINT_H
#define PROJECT2_POINT_H

#include <string>
using std::string;

class Point {
private:
    int x;
    int y;
    double val;
public:
    Point(int x, int y);

    ~Point();

    //get x value
    int getX() const;

    //set x value
    void setX(int x);

    //get y value
    int getY() const;

    //set y value
    void setY(int y);

    //return true if both points equals-else otherwise
    bool equal(Point other);

    //return 'true' if the other point is left neighbor
    bool isLeftNeighbor(Point other);

    //return 'true' if the other point is right neighbor
    bool isRightNeighbor(Point other);

    //return 'true' if the other point is up neighbor
    bool isUpNeighbor(Point other);

    //return 'true' if the other point is down neighbor
    bool isDownNeighbor(Point other);

    //get the type step that we did
    string getMove(Point other);


};

#endif //PROJECT2_POINT_H
