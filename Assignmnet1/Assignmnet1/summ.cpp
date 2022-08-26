//*******************************************************************************************************
//
// File: summ.cpp
//
// Student: Urban Shocker
//
// Assignment: Program #01
//
// Course Name: Data Structures II
//
// Course Number: COSC 3100-01
//
// Due: 29/08/22
//
//
// This program preforms summation on user provided value
//
// Other files required: 
// 1. None
//
//*******************************************************************************************************

#include <iostream>
using namespace std;

int userInput();
int calcSummation(int);
void displayResult(int, int);


//*******************************************************************************************************

int main()
{
    int input;
    int result;

    input = userInput();
    result = calcSummation(input);
    displayResult(input, result);
    

    return 0;
}

//*******************************************************************************************************

int userInput()
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

int calcSummation(int n)
{
    int result;

    if (n > 0)
    {
        result = calcSummation(n-1) + n;
    }
    else
    {
        result = 0;
    }

    return result;
}

//*******************************************************************************************************

void displayResult(int n , int r)
{
    cout << "Summation " << n << " = " << r;
}

//*******************************************************************************************************

// Sample output
/*

Please enter a positive number : 5
Summation 5 = 15

Please enter a positive number: 10
Summation 10 = 55

*/
