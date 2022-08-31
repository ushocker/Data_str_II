//*******************************************************************************************************
//
// File: gcd.cpp
//
// Student: Urban Shocker
//
// Assignment: Program #02
//
// Course Name: Data Structures II
//
// Course Number: COSC 3100-01
//
// Due: 02/09/22
//
//
// This program Calculated the GCD of numbers provided via gcdFile.txt
//
// Other files required: 
// 1. gcdFile.txt
//
//*******************************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

//*******************************************************************************************************

int findGCD(int, int);
void display(int, int, int);

//*******************************************************************************************************

int main()
{

    int num1,
        num2;

    ifstream infile("gcdFile.txt");
    if (infile.fail())
    {

        cout << "failed to open file" << endl;

    }
    else
    {

        while (infile)
        {

            infile >> num1;
            infile.ignore();
            infile >> num2;
            infile.ignore();
            if (num1 >= num2 > 0)
            {

                display(num1, num2, findGCD(num1, num2));

            }

        }

    }
    infile.close();

}

//*******************************************************************************************************

int findGCD(int a, int b)
{

    int result;

    if (b != 0)
    {

        result = findGCD(b, (a % b));

    }
    else
    {
    
        result = a;

    }

    return result;

}

//*******************************************************************************************************

void display(int a , int b, int gcd)
{

    cout << "GCD of " << a << " and " << b << " is " << gcd << endl;

}

//*******************************************************************************************************

// output

/*
GCD of 210 and 45 is 15
GCD of 97 and 20 is 1
GCD of 164 and 123 is 41
GCD of 156 and 130 is 26
GCD of 176 and 132 is 44
GCD of 72 and 40 is 8
GCD of 117 and 78 is 39
GCD of 175 and 140 is 35
GCD of 147 and 98 is 49
GCD of 176 and 48 is 16
GCD of 182 and 156 is 26
GCD of 144 and 108 is 36
GCD of 141 and 94 is 47
GCD of 133 and 98 is 7
GCD of 196 and 140 is 28
GCD of 196 and 196 is 196 
*/