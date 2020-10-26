//
//  robot.cpp
//  look-for
//  Created by Ahmed Soliman
//

// definition of Robot class
#include "robot.h"

// set robot's moves to zero
int Robot::moves = 0;

// default constructor
Robot::Robot()
{
    robot_location.set(0, 0);
}

// destructor
Robot::~Robot()
{
}

// this function returns robot's location - Point object
Point Robot::getLocation()
{
    return robot_location;
} // end of getLocation()

// this function initializes robot’s current location to (0, 0)
// and its current orientation to the east
void Robot::init()
{
    robot_location.set(0, 0);
    orientation = East;
} // end of init()

// this function prints robot’s current location and orientation
void Robot::print() const
{
    cout << "\nI am at: ";
    robot_location.print();
    cout << " and facing ";
    if (orientation == North)
    {
        cout << "North.\n";
    }
    else if (orientation == South)
    {
        cout << "South.\n";
    }
    else if (orientation == East)
    {
        cout << "East.\n";
    }
    else if (orientation == West)
    {

        cout << "West.\n";
    }
    cout << "I have made " << moves << " moves." << endl;
} // end of print()

// this function sets the value of the robot’s orientation data member
void Robot::setOrientation(orientation_type orientation)
{
    this->orientation = orientation;
} // end of setOrientation()

// this function simulates the robot moving forward one step in the direction
// that it is facing. It checks to make sure that the robot is not at the edge
// of its world. It returns true if the robot moves forward successfully and
// false if the robot is at the edge of its world and cannot move forward
bool Robot::forward()
{
    if (orientation == North)
    {
        if (northEnd() == true)
        {
            cout << "\nOoops! I'm hitting north wall.";
            cout << "\nTry another direction.";
            return false;
        }
        else
        {
            robot_location.decY();
            moves++;
            return true;
        }
    }
    else if (orientation == South)
    {
        if (southEnd() == true)
        {
            cout << "\nOoops! I'm hitting south wall.";
            cout << "\nTry another direction.";
            return false;
        }
        else
        {
            robot_location.incY();
            moves++;
            return true;
        }
    }
    else if (orientation == East)
    {
        if (eastEnd() == true)
        {
            cout << "\nI've reached the Eastern wall, turning right...";
            zag();
            return false;
        }
        else
        {
            robot_location.incX();
            moves++;
            return true;
        }
    }
    else if (orientation == West)
    {
        if (westEnd() == true)
        {
            cout << "\nI've reached the Western wall, turning left...";
            zig();
            return false;
        }
        else
        {
            robot_location.decX();
            moves++;
            return true;
        }
    }
    return false;
} // end of forward()

// this function changes robot’s orientation,
// simulating a turn in the clockwise direction
void Robot::turnCW()
{
    if (orientation == North)
    {
        orientation = East;
    }
    else if (orientation == East)
    {
        orientation = South;
    }
    else if (orientation == South)
    {
        orientation = West;
    }
    else if (orientation == West)
    {
        orientation = North;
    }
} // end of turnCW()

// this function changes robot’s orientation,
// simulating a turn in the anti-clockwise direction
void Robot::turnAntiCW()
{
    if (orientation == North)
    {
        orientation = West;
    }
    else if (orientation == East)
    {
        orientation = North;
    }
    else if (orientation == South)
    {
        orientation = East;
    }
    else if (orientation == West)
    {
        orientation = South;
    }
} // end of turnAntiCW()

// this function returns true if robot has reached the east edge of its world
bool Robot::eastEnd()
{
    if (robot_location.getX() == 9)
        return true;
    else
        return false;
} // end of eastEnd()

// this function returns true if robot has reached the west edge of its world
bool Robot::westEnd()
{
    if (robot_location.getX() == 0)
        return true;
    else
        return false;
} // end of westEnd()

// this function returns true if robot has reached the north edge of its world
bool Robot::northEnd()
{
    if (robot_location.getY() == 0)
        return true;
    else
        return false;
} // end of northEnd()

// this function returns true if robot has reached the south edge of its world
bool Robot::southEnd()
{
    if (robot_location.getY() == 9)
        return true;
    else
        return false;
} // end of southEnd()

// this function is called when the robot has been moving east and has reached
// the east edge of its world, in which case it should turn clockwise,
// go forward one step south and turn clockwise again
// (where it will be heading west for its next move)
bool Robot::zag()
{
    if (eastEnd() == true)
    {
        turnCW();
        forward();
        turnCW();
        return true;
    }
    else
    {
        return false;
    }
} // end of zag()

// this function is called when the robot has been moving west and has reached
// the west edge of its world, in which case it should turn anti-clockwise,
// go forward one step south and turn anti-clockwise again
// (where it will be heading east for its next move)
bool Robot::zig()
{
    if (westEnd() == true)
    {
        turnAntiCW();
        forward();
        turnAntiCW();
        return true;
    }
    else
    {
        return false;
    }
} // end of zig()

// this function send the robot to a random location until it finds hidden coins
void Robot::gorandom()
{
    cout << "Robot is moving to a random location...\n";
    int a = (rand() % 9);
    int b = (rand() % 9);
    robot_location.set(a, b);
    moves++;
} // end of gorandom

// this function send the robot Home at any point, bring back orientation to east and count moves
void Robot::goHome()
{
    cout << "Robot is going home to recharge...\n";
    robot_location.set(0, 0);
    orientation = East;
    moves++;
} // end of goHome

// this function reports the number of moves made by the robot
// in order to find all the coins
void Robot::result()
{
    cout << "\nI found all 3 coins in " << moves << " moves." << endl;
} // end of result()
