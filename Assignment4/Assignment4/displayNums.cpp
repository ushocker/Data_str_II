//*******************************************************************************************************
//
// File: displayNums.cpp
//
// Student: Urban Shocker
//
// Assignment: Program #04
//
// Course Name: Data Structures II
//
// Course Number: COSC 3100-01
//
// Due: 09/09/22
//
//
// This program Splits numbers based on content of text file
//
// Other files required: 
// 1. bignums.txt
//
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//*******************************************************************************************************

void displayNum(long long int, int);

//*******************************************************************************************************

int main()
{

    long long int input;
    int num;
    ifstream infile("bignums.txt");

    if (infile.fail())
    {

        cout << "failed to open file" << endl;

    }
    else
    {

        while (infile >> input >> num)
        {

            displayNum(input, (int)pow(10, num));

        }

    }

    infile.close();

}

//*******************************************************************************************************

void displayNum(long long int bignum, int num)
{

    if ((bignum / num) != 0)
    {

        displayNum(bignum / num, num);
        cout << setw(5) << right << bignum % num << endl;

    }
    else
    {

        cout << endl << endl << setw(5) << right << bignum % num << endl;

    }
}

//*******************************************************************************************************

//output
/*
    

    1
    2
    3
    4


  123
 4567
 8912
 3456
 7891


 1234
56789
12345
67891


    1
23456
78912


   12
  345
  678


    1
   23
   45
   67

*/
