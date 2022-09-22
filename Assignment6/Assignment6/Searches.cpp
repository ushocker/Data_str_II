//*****************************************************************************************************
//
//		File:					Searches.cpp
//
//		Student:				Urban Shocker
//
//		Assignment:				Program #06
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					22/09/22
//
//
//		This program benchmarks the effectivenss of diffrent search algorithms on inputed data
//	
//		Other files required: 
//			1.	Results.h
//			2.	ordered.txt
//          3.  unordered.txt
//          4.  searchNums.txt
//			
//*****************************************************************************************************


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Results.h"

//*****************************************************************************************************

void getdata(int arr [],const char*, int);
bool ordSearch(int list[], int size, int target, int& compares);
bool unOrdSearch(int list[], int size, int target, int& compares);
bool binSearch(int list[], int size, int target, int& compares);
void updateStats(Results&);
void displayResults(const Results&, const Results&, const Results&);
void process(int list[], int search[], int, Results& res
    , bool (*func)(int list[], int size, int target, int &compares));

//*****************************************************************************************************

int main()
{
    int ordered[1000];
    int unordered[1000];
    int searchNums[500];
    Results unord;
    Results ord;
    Results bin;

    getdata(ordered, "ordered.txt", 1000);
    getdata(unordered, "unordered.txt", 1000);
    getdata(searchNums, "searchNums.txt", 500);

    process(ordered, searchNums, 1000, ord, ordSearch);
    process(unordered, searchNums, 1000, unord, unOrdSearch);
    process(ordered, searchNums, 1000, bin, binSearch);

    updateStats(ord);
    updateStats(unord);
    updateStats(bin);

    displayResults(ord, unord, bin);


}

//*****************************************************************************************************

void getdata(int arr[],const char* fname, int arrsize)
{

    ifstream infile(fname);

    int num;
    int i = 0;
    while(i < arrsize && infile >> num)
    {
        arr[i++] = num;
    }

}

//*****************************************************************************************************

bool ordSearch(int list[], int size, int target, int& compares)
{
    bool found = false;
    int i = 0;
    while (i < size && ++compares && list[i] < target)
    {

        i++;
        
    }
    if (i < size && ++compares && list[i] == target)
    {
        found = true;

    }


    return found;
}

//*****************************************************************************************************

bool unOrdSearch(int list[], int size, int target, int& compares)
{
    bool found = false;
    int i = 0;
    while (i < size && ++compares && list[i] != target)
    {

        i++;
    }
    if (i < size && ++compares && list[i] == target)
    {

        found = true;
    }


    return found;
}

//*****************************************************************************************************

bool binSearch(int list[], int size, int target, int& compares)
{
    bool found = false;
    int low = 0;
    int high = size-1;
    int mid;

    while (!(found) && low <= high)
    {

        mid = (low + high) / 2;

        if (compares++, list[mid] == target)
        {

            found = true;
        }

        else if (compares++, list[mid] > target)
        {

            high = (mid - 1);

        }

        else
        {

            low = (mid + 1);

        }

    }


    return found;
}

//*****************************************************************************************************

void updateStats(Results& res)
{

    res.percSuccesses = ((res.numSuccesses / 500.0) * 100);
    res.avgNumCompares = res.totalCompares / 500.0;

}

//*****************************************************************************************************

void displayResults(const Results& resOrd, const Results& resUnOrd, const Results& resBin)
{

    cout << fixed << setw(40) << "Unordered" << setw(10) <<  "Ordered" << setw(10) << "Bin" << endl;
    cout << fixed << "Number of Successful Searches" << setw(11) << resUnOrd.numSuccesses << setw(10)
        << resOrd.numSuccesses << setw(10) << resBin.numSuccesses << endl << endl;
    cout << fixed << setprecision(2) << "Precent of Successful Searches" << setw(10)
        << resUnOrd.percSuccesses << "%" << setw(9) << resOrd.percSuccesses << "%" << setw(9)
        << resBin.percSuccesses << "%" << endl << endl;
    cout << fixed << setprecision(0) << "Average compares per search" << setw(13)
        << resUnOrd.avgNumCompares << setw(10) << resOrd.avgNumCompares << setw(10)
        << resBin.avgNumCompares << endl << endl;

}

//*****************************************************************************************************

void process(int list[], int search[],int size, Results& res
    , bool(*func)(int list[], int size, int target, int &compares))
{
    int numcomp;
    bool found;

    for (int i = 0; i < 500; i++)
    {
        numcomp = 0;
        found = func(list, size, search[i], numcomp);

        
        if (found)
        {
            
            res.numSuccesses++;
        }   

        res.totalCompares += numcomp;

    }

    

}
