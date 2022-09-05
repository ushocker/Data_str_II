//*******************************************************************************************************
//
// File: stars.cpp
//
// Student: Urban Shocker
//
// Assignment: Program #03
//
// Course Name: Data Structures II
//
// Course Number: COSC 3100-01
//
// Due: 05/09/22
//
//
// This program displays stars based recursively based on user input
//
// Other files required: 
// 1. None
//
//*******************************************************************************************************

#include <iostream>

using namespace std;

//*******************************************************************************************************

int getInput();
void makeRows(int);
void display(int);

//*******************************************************************************************************

int main()
{

    int input;

    input = getInput();

    makeRows(input);

    return 0;
}

//*******************************************************************************************************

int getInput()
{
    int n = -1;

    while (n < 0)
    {

        cout << "Please enter a positive number: ";
        cin >> n;

    }

    return n;
}

//*******************************************************************************************************

void makeRows(int n)
{

    if (n > 0)
    {

        display(n);
        makeRows(n - 1);
        display(n);

    }

}

//*******************************************************************************************************

void display(int n)
{

    if (n > 0)
    {

        cout << '*';
        display(n - 1);

    }
    else
    {

        cout << endl;

    }
    
}

//*******************************************************************************************************
//output

/*

Please enter a positive number: 4
****
***
**
*
*
**
***
****

Please enter a positive number: 3
***
**
*
*
**
***

*/