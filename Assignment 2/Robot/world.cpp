//
//  world.cpp
//  look-for
//  Created by Ahmed Soliman
//

// definition of World class
#include "world.h"


// set founded coins to zero
int World::coinsFound = 0;

// default constructor
World::World()
{
}

// destructor
World::~World()
{
}

// this function prints out the locations of three coins
void World::print() const
{
    cout << "\nRobot will be looking for coin No#1 - Position: ";
    coins[0].print();
    cout << "\nRobot will be looking for coin No#2 - Position: ";
    coins[1].print();
    cout << "\nRobot will be looking for coin No#3 - Position: ";
    coins[2].print();
    cout << endl;
} //end of print()

// this function sets the location of the i-th coin in the data member array to (x, y)
void World::setCoin(int i, int x, int y)
{
    coins[i].set(x, y);
} // end of setCoin()

// this function generates random locations of the coins
void World::randomlySetCoins()
{
    for (int i = 0; i < 3; i++)
    {
        int x = rand() % n;
        int y = rand() % m;
        setCoin(i, x, y);
    }
} // end of randomlySetCoins()

// this functions sets the coins location using validated user input
void World::userSetCoins()
{
    for (int i = 0; i < 3; i++)
    {
        int x, y;
        cout << "Please set X coordinate for coin No#" << i + 1 << " (0 TO 9): ";
        cin >> x;
        while (cin.fail() || x < 0 || x > 9)
        {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Invalid input. Please re-enter (0 TO 9): ";
            cin >> x;
        }
        cout << "Please set Y coordinate for coin No#" << i + 1 << " (0 TO 9): ";
        cin >> y;
        while (cin.fail() || y < 0 || y > 9)
        {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Invalid input! Please re-enter: (0 To 9): ";
            cin >> y;
        }
        setCoin(i, x, y);
    }
} // end of userSetCoin()

// this function returns the number of coins found
int World::getCoinsFound()
{
    return coinsFound;
} // end of getCoinsFound()

// this function initializes the world
void World::initWorld()
{
    for (int b = 0; b < m; b++)
    {
        for (int a = 0; a < n; a++)
        {
            world[b][a] = '*';
        }
    }
    for (int i = 0; i < 3; i++)
        world[coins[i].getY()][coins[i].getX()] = 'C';
} // end of initWorld()

// this function displays the world as a multiD Array
void World::displayWorld()
{
    cout << endl;
    for (int b = 0; b < m; b++)
    {
        for (int a = 0; a < n; a++)
        {
            cout << "  ";
            cout << world[b][a];
        }
        cout << endl;
    }
} // end of displayWorld()

// this function resets robot's previous location in the world
void World::resetWorld(Robot R)
{
    world[R.getLocation().getY()][R.getLocation().getX()] = '*';
} // end of resetWorld()

// this function updates robot's new location in the world,
// checks and see if the three coins are in the same location
// determines and inform the user if coins are found
// and keeps track of how many coins have been found
void World::updateWorld(Robot R)
{
    for (int i = 0; i < 3; i++)
    {
        if (coinsFound < 3 && R.getLocation().getY() == coins[i].getY() && R.getLocation().getX() == coins[i].getX())
        {
            coinsFound++;
            cout << "I found coin No# " << coinsFound << " I'm gonna be rich! Yippee!" << endl;
        }
    }
    world[R.getLocation().getY()][R.getLocation().getX()] = 'R';
} // end of updateWorld()

// this function reads and validates user commands to move the robot in the world
void World::controller(Robot R)
{

    while (coinsFound < 3)
    {
        // comment this to use user input
        resetWorld(R);
        R.forward();
        R.print();
        updateWorld(R);
        displayWorld();
    }

    // uncomment to to use user input
    // char input;

    // // prompt menu for user to execute the command
    // cout << "\nReading the next robot's move from user: \n";
    // cout << "--------------------------------------------------\n";
    // cout << "(t) OR (T) - To visit every unit until all coins are found\n";
    // cout << "(f) OR (F) - To move robot forward one step\n";
    // cout << "(c) OR (C) - To rotate robot clockwise\n";
    // cout << "(a) OR (A) - To rotate robot anti-clockwise\n";
    // cout << "(r) OR (R) - To send robot to a random location.\n";
    // cout << "(h) OR (H) - To send robot home to recharge.\n";
    // cout << "(q) OR (Q) - To quit the program\n";
    // cout << "--------------------------------------------------\n";
    // int i = 0;
    // cout << "Enter command Here: ";
    // cin >> input;
    //     while (input != 'q' || input != 'Q'){

    //         if (input == 't' || input == 'T'){
    //             // let the robot visit every cell until all the coins are found
    //             while (getCoinsFound() < 3){
    //                 resetWorld(R);
    //                 R.forward();
    //                 R.print();
    //                 updateWorld(R);
    //                 displayWorld();
    //             }
    //             R.result();
    //             break;

    //         } else if (input == 'f' || input == 'F'){
    //             // move the robot forward one step
    //             resetWorld(R);
    //             R.forward();
    //             R.print();
    //             updateWorld(R);
    //             displayWorld();

    //         } else if (input == 'c' || input == 'C'){
    //             // rotate the robot clockwise
    //             resetWorld(R);
    //             R.turnCW();
    //             R.print();
    //             updateWorld(R);
    //             displayWorld();

    //         } else if (input == 'a'|| input == 'A'){
    //             // rotate the robot anti-clockwise
    //             resetWorld(R);
    //             R.turnAntiCW();
    //             R.print();
    //             updateWorld(R);
    //             displayWorld();

    //         } else if (input == 'r' || input == 'R'){
    //           resetWorld(R);
    //           R.gorandom();
    //           R.print();
    //           updateWorld(R);
    //           displayWorld();

    //         } else if (input == 'h' || input == 'H'){
    //           resetWorld(R);
    //           R.goHome();
    //           R.print();
    //           updateWorld(R);
    //           displayWorld();

    //         } else if (input == 'q' || input == 'Q'){
    //             // quit the program if user enter q
    //             break;

    //         } else {
    //             // user input validation
    //             cout << "\nInvalid option. Please select from the menu.\n";
    //         }

    //         if (getCoinsFound() == 3){
    //             // print the results and quit the program if all the coins are found
    //             R.result();
    //             break;
    //         }
    //         cout << "\nReading the next robot move...\nEntre command here: ";
    //         cin >> input;
    //     }
    // i++;
} // end of controller()
