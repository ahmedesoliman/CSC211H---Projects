/*
   roomba.cpp
   Name: Ahmed Soliman
   ID#: 24033795
   Class: Fall 2020, CSC 211H 0500[64041] (Borough of Manhattan CC)
   Date: 09/10/2020
   Time: 05:30PM
   Instructor Name: Dr. Azhar 

   31-jan-2019/dr. azhar
   based on 
   work Dr. sklar

   this program demonstrates a simple robot (called "roomba")
   wandering around in a simulated room. the robot can move in any of
   four directions (forward, backward, left or right) within a "grid"
   so that any move changes the robot's location by one grid square.
   for example, if the robot starts at location (0,0) and moves forward,
   it will end up at location (0,1).
*/

#include <iostream>
#include "Roomba.h"

using namespace std;

int main()
{
    Roomba R = Roomba();
    R.welcome();
    char input = ' ';
    while (input != 'Q' || 'q')
    {
        cout << "Enter Command Here: ";
        cin >> input;
        R.movement(input);
        if (input == 'Q' || input == 'q')
        {
            cout << "You have exited ROOMBA!!!\nGoogbye!";
            exit(0);
        }
    }
}