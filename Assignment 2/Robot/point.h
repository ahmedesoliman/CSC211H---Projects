//
//  point.h
//  look-for
//  Created by Ahmed Soliman
//

#ifndef point_hpp
#define point_hpp

#include <iostream>
using namespace std;

class Point
{

private:
    // x and y coordinates of the Point object
    int x, y;

public:
    // default constructor
    Point();

    // constructor with arguments
    Point(int x, int y);

    // destructor
    ~Point();

    // this function prints out the values of the data members x and y
    void print() const;

    // this function sets the values of the data members x and y
    void set(int x, int y);

    // this function returns the value of the x data member
    int getX();

    // this function returns the value of the y data member
    int getY();

    // this function increments X value by one
    void incX();

    // this function decrements X value by one
    void decX();

    // this function increments Y value by one
    void incY();

    // this function decrements Y value by one
    void decY();

}; // end of Point class

#endif /* point.h */
