//*****************************************************************************************************
//
//		File:					pals.cpp
//
//		Student:				Urban Shocker
//
//		Assignment:				Program #05
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					13/09/22
//
//
//		This program reads strings from provided file and determines if they are palindromes.
//	
//		Other files required: 
//			1.	pals.txt
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//*****************************************************************************************************

void dispRev(char input[]);
bool isPal(char input [], int length);
void display(bool, int);

//*****************************************************************************************************

int main()
{

    bool result;
    char input[60];
    int length;

    ifstream infile("pals.txt");

    if (infile.fail())
    {

        cout << "failed to open file" << endl;

    }
    else
    {

        while (infile.getline(input, 60, '\n'))
        {
                    
            length = (int) strlen(input);
            dispRev(input);
            result = isPal(input, length - 1);
            display(result, length);
            
        }

    }
    infile.close();

    return 0;
}

//*****************************************************************************************************

void dispRev(char input[])
{

    if (input[0] != '\0')
    {

        dispRev(input + 1);
        cout << input[0] ;

    }

}

//*****************************************************************************************************

bool isPal(char input[], int length)
{

    bool result;

    if (length > 0 && input[0] == input[length])
    {
        
        result = isPal(input+1, length - 2);
        
    }
    else if (length > 0 && input[0] != input[length])
    {

        result = false;

    }
    else
    {

        result = true;

    }

    return result;
}

//*****************************************************************************************************

void display(bool result, int length)
{
    if (result)
    {

        printf("%*s \n", 30 - length , "Valid");

    }
    else
    {

        printf("%*s \n", 38 - length, "Invalid");

    }

}

//*****************************************************************************************************

//output

/*

aha                      Valid
isitiitisi               Valid
deed                     Valid
srotor                         Invalid
neveroddoreven           Valid
nolemonsnomelon          Valid
racecar                  Valid
cimoc                          Invalid
wasitacaroracatisaw      Valid
10101                    Valid
yddad                          Invalid

*/

