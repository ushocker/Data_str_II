#include <iostream>
#include <fstream>

using namespace std;

#include "Results.h"

void getdata(int arr [],const char*, int);
bool ordSearch(int list[], int size, int target, int& compares);
bool unOrdSearch(int list[], int size, int target, int& compares);
bool binSearch(int list[], int size, int target, int& compares);
void updateStats(Results&);
void displayResults(const Results&, const Results&, const Results&);
void process(int list[], int search[], int, Results& res, bool (*func)(int list[], int size, int target, int &compares));

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
    //process(ordered, searchNums, 1000, bin, binSearch);

    updateStats(ord);
    updateStats(unord);
    //updateStats(bin);

    displayResults(ord, unord, bin);


}


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

bool ordSearch(int list[], int size, int target, int& compares)
{
    bool found = false;
    int i = 0;
    while (i < size && list[i] < target)
    {
        i++;
        compares++;
    }
    if (i < size && list[i] == target)
    {
        found = true;
        compares++;
    }

    return found;
}

bool unOrdSearch(int list[], int size, int target, int& compares)
{
    bool found = false;
    int i = 0;
    while (i < size && list[i] != target)
    {
        i++;
        compares++;
    }
    if (i < size && list[i] == target)
    {
        found = true;
        compares++;
    }

    return found;
}

bool binSearch(int list[], int size, int target, int& compares)
{
    

    return false;
}

void updateStats(Results& res)
{

    res.percSuccesses = ((res.numSuccesses / 500.0) * 100);
    res.avgNumCompares = res.totalCompares / 500.0;

}

void displayResults(const Results& resOrd, const Results& resUnOrd, const Results& resBin)
{

    printf("%40s%10s%10s\n", "Unordered", "Ordered", "Bin");
    printf("Number of Successful Searches %10i%10i%10i\n\n", resUnOrd.numSuccesses, resOrd.numSuccesses, resBin.numSuccesses);
    printf("Precent of Successful Searches %9.2f%%%9.2f%%%9.2f%%\n\n", resUnOrd.percSuccesses, resOrd.percSuccesses, resBin.percSuccesses);
    printf("Average compares per search %12.0f%10.0f%10.0f\n\n", resUnOrd.avgNumCompares, resOrd.avgNumCompares, resBin.avgNumCompares);

}

void process(int list[], int search[],int size, Results& res, bool(*func)(int list[], int size, int target, int &compares))
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
