#ifndef ROOMBA_H
#define ROOMBA_H

#include <iostream>
using namespace std;

class Roomba
{

private:
    int x;
    int y;

public:
    Roomba();
    void welcome();
    int moveNorth();
    int moveSouth();
    int moveRight();
    int moveLeft();
    // int hittingWall(char);
    void movement(char);
    void gorandom();
    void goHome();
    void display();
    void hitNorth();
    void hitSouth();
    void hitEast();
    void hitWest();
};

#endif