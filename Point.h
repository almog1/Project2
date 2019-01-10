//
// Created by almogg on 1/9/19.
//

#ifndef PROJECT2_POINT_H
#define PROJECT2_POINT_H

class Point {
private:
    int x;
    int y;
    double val;
public:
    Point(int x,int y, double val);
    ~Point();

    double getVal() const;

    void setVal(double val);

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);
};

#endif //PROJECT2_POINT_H
