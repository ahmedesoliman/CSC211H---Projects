#include <iostream>
#include "Roomba.h"

using namespace std;

Roomba::Roomba()
{
    x = 0;
    y = 0;
}

void Roomba::welcome()
{
    cout << "---Welcome to ROOMBA---\nROOMBA IS AT TOP LEFT CORNER OF THE ROOM\n";
    cout << "ROOMBA HOME STARTS AT (0,0) OF THE ROOM SIZE 10X10\n";
    cout << "PLEASE ENTRE A COMMAND TO MOVE ROOMBA OR (Q) TO EXIT:\n";
    cout << "---------------------------------------------------------" << endl
         << "|| n or (N) - Move Roomba 1 Unit North (to North Wall) ||" << endl
         << "|| s or (S) - Move Roomba 1 Unit South (to South Wall) ||" << endl
         << "|| w or (W) - Move Roomba 1 Unit West (to West Wall)   ||" << endl
         << "|| e or (E) - Move Roomba 1 Unit East (to East Wall)   ||" << endl
         << "||   R      - MOVE ROOMBA TO A RANDOM LOCATION         ||" << endl
         << "||   H      - SEND ROOMBA HOME TO ORIGIN (0,0)         ||" << endl
         << "---------------------------------------------------------" << endl;
}

int Roomba::moveNorth()
{
    cout << "Moving Forward...\n";
    if (y <= 0)
    {
        cout << "CAUTION: ROOMBA is Hitting North Wall. Cannot Move!.\nPlease Reenter a Diretion\n"
             << endl;
        return 0;
    }
    y--;
    return 0;
} // end of moveNorth()

int Roomba::moveSouth()
{
    cout << "Moving South...\n";
    if (y >= 9)
    {
        cout << "CAUTION: ROOMBA is Hitting South Wall. Cannot Move!.\nPlease Reenter a Diretion" << endl;
        return 0;
    }
    y++;
    return 0;
} // end of moveSouth()

int Roomba::moveLeft()
{
    cout << "Moving Left...\n";
    if (x <= 0)
    {
        cout << "CAUTION: ROOMBA is Hitting East Wall. Cannot Move!.\nPlease Reenter a Diretion" << endl;
        return 0;
    }
    x--;
    return 0;
} // end of moveLeft()

int Roomba::moveRight()
{
    cout << "Moving Right...\n";
    if (x >= 9)
    {
        cout << "CAUTION: ROOMBA is Hitting West Wall. Cannot Move!.\nPlease Reenter a Diretion" << endl;
        return 0;
    }
    x++;
    return 0;
} // end of moveRight()

// int Roomba::hittingWall(char direction) // hitting the walls function one for each direction
// {
//     if (direction == 'N')
//     {
//         for (int i = y; i >= 0; i--)
//         {
//             moveNorth();
//             display();
//         }
//     }
//     else if (direction == 'S')
//     {
//         for (int i = y; i <= 9; i++)
//         {
//             moveSouth();
//             display();
//         }
//     }
//     else if (direction == 'E')
//     {
//         for (int i = x; i <= 9; i++)
//         {
//             moveRight();
//             display();
//         }
//     }
//     else if (direction == 'W')
//     {
//         for (int i = x; i >= 0; i--)
//         {
//             moveLeft();
//             display();
//         }
//     }
//     return 0;
// } // end of hittingWall()

void Roomba::hitNorth()
{
    y = 0;
    display();
}
void Roomba::hitSouth()
{
    y = 9;
    display();
}
void Roomba::hitEast()
{
    x = 9;
    display();
}
void Roomba::hitWest()
{
    x = 0;
    display();
}
void Roomba::movement(char direction) //takes user input to determine direction
{
    if (direction == 'n')
    {
        moveNorth();
        display();
    }
    else if (direction == 'w')
    {
        moveLeft();
        display();
    }
    else if (direction == 'e')
    {
        moveRight();
        display();
    }
    else if (direction == 's')
    {
        moveSouth();
        display();
    }
    else if (direction == 'N') //wallNorth
    {
        hitNorth();
    }
    else if (direction == 'S') //wallSouth
    {
        hitSouth();
    }
    else if (direction == 'E') //wallRight
    {
        hitEast();
    }
    else if (direction == 'W') //wallLeft
    {
        hitWest();
    }
    else if (direction == 'R' || direction == 'r') // set a random location
    {
        gorandom();
    }
    // else if (direction == 'A' || direction == 'a') // Go on an eefienct route
    // {
    //     autoRoute();
    // }
    else if (direction == 'H' || direction == 'h') //sendHome
    {
        goHome();
    }
    else if (direction != 'q' || direction != 'q')
    {
        cout << "Incorrect input, please try again \n";
    }
} // end of movement()

void Roomba::gorandom()
{
    cout << "ROOMBA is Moving to Random Location...\n";
    x = (rand() % 9);
    y = (rand() % 9);
    display();
} // end of gotandom()

void Roomba::goHome()
{
    cout << "ROOMBA is going Home to recharge...\n";
    x = 0;
    y = 0;
    display();
} // end of goHome()

void Roomba::display() //displays Roomba location and builds display
{
    cout << "The ROOMBA is at location (" << x << "," << y << ")\n";
    for (int i = 0; i <= 10; ++i)
    {
        cout << (i - 1);
        if (i < 10 && i >= 0)
            cout << " ";
        if (i == 10)
            cout << " ";

        for (int j = 0; j <= 9; j++)
        {
            if (i == 0)
            {
                if (j >= 0)
                {
                    cout << "" << j << "  ";
                }
            }
            else if (j == x && i - 1 == y)
            {
                cout << "(X)";
            }
            else
                cout << "( )";
            if (j == 9)
                cout << endl;
        }
    }
} // end of display()