//*****************************************************************************************************
//
//		File:					sortComp.cpp
//
//		Customer:				Urban Shocker
//
//		Assignment:				Program #11
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					08/12/22
//
//
//		This program is the driver program for Heap
//	
//		Other files required: 
//			1.	Results.h
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <utility>
#include <iomanip>
#include <string>

using namespace std;

#include "Results.h"

//*****************************************************************************************************

void getData(int list[], int size, const char* fname);
void insertSort(int list[], int size, int& comp, int& cpy);
void selSort(int list[], int size, int& comp, int& cpy);
void bubbleSort(int list[], int size, int& comp, int& cpy);
void shellSort(int list[], int size, int& comp, int& cpy);
void heapSort(int list[], int size, int& comp, int& copy);
void _siftUp(int list[], int child, int& comp, int& cpy);
void _siftDown(int list[], int parent, int size, int& comp, int& cpy);
void quickSort(int list[], int size, int& comp, int& cpy);
void _quickSort(int list[], int left, int right, int& comp, int& cpy);
void putMedianLeft(int list[],int left,int right,int& comp,int& cpy);
int partition(int list[], int left, int right, int& comp, int& cpy);
void calcResults(Results& result);
void displayResults(Results iResults, Results sResults, Results bResults, Results shResults, Results hResults, Results qResults);
void displayReuslt(Results result, const char* sort);

//*****************************************************************************************************

int main()
{
    const int ARR_SIZE = 1000;

    int ordered[ARR_SIZE],
     unordered[ARR_SIZE],
     reversed[ARR_SIZE];

    Results iResults, 
        sResults, 
        bResults, 
        shResults, 
        hResults, 
        qResults;


    getData(ordered, ARR_SIZE, "ordered.txt");
    getData(unordered, ARR_SIZE, "unordered.txt");
    getData(reversed, ARR_SIZE, "reversed.txt");
    insertSort(ordered, ARR_SIZE, iResults.ordCompares, iResults.ordCpy);
    insertSort(unordered, ARR_SIZE, iResults.unOrdCompares, iResults.unOrdCpy);
    insertSort(reversed, ARR_SIZE, iResults.revOrdCompares, iResults.revOrdCpy);
    calcResults(iResults);


    getData(ordered, ARR_SIZE, "ordered.txt");
    getData(unordered, ARR_SIZE, "unordered.txt");
    getData(reversed, ARR_SIZE, "reversed.txt");
    selSort(ordered, ARR_SIZE, sResults.ordCompares, sResults.ordCpy);
    selSort(unordered, ARR_SIZE, sResults.unOrdCompares, sResults.unOrdCpy);
    selSort(reversed, ARR_SIZE, sResults.revOrdCompares, sResults.revOrdCpy);
    calcResults(sResults);


    getData(ordered, ARR_SIZE, "ordered.txt");
    getData(unordered, ARR_SIZE, "unordered.txt");
    getData(reversed, ARR_SIZE, "reversed.txt");
    bubbleSort(ordered, ARR_SIZE, bResults.ordCompares, bResults.ordCpy);
    bubbleSort(unordered, ARR_SIZE, bResults.unOrdCompares, bResults.unOrdCpy);
    bubbleSort(reversed, ARR_SIZE, bResults.revOrdCompares, bResults.revOrdCpy);
    calcResults(bResults);


    getData(ordered, ARR_SIZE, "ordered.txt");
    getData(unordered, ARR_SIZE, "unordered.txt");
    getData(reversed, ARR_SIZE, "reversed.txt");
    shellSort(ordered, ARR_SIZE, shResults.ordCompares, shResults.ordCpy);
    shellSort(unordered, ARR_SIZE, shResults.unOrdCompares, shResults.unOrdCpy);
    shellSort(reversed, ARR_SIZE, shResults.revOrdCompares, shResults.revOrdCpy);
    calcResults(shResults);


    getData(ordered, ARR_SIZE, "ordered.txt");
    getData(unordered, ARR_SIZE, "unordered.txt");
    getData(reversed, ARR_SIZE, "reversed.txt");
    heapSort(ordered, ARR_SIZE, hResults.ordCompares, hResults.ordCpy);
    heapSort(unordered, ARR_SIZE, hResults.unOrdCompares, hResults.unOrdCpy);
    heapSort(reversed, ARR_SIZE, hResults.revOrdCompares, hResults.revOrdCpy);
    calcResults(hResults);


    getData(ordered, ARR_SIZE, "ordered.txt");
    getData(unordered, ARR_SIZE, "unordered.txt");
    getData(reversed, ARR_SIZE, "reversed.txt");
    quickSort(ordered, ARR_SIZE, qResults.ordCompares, qResults.ordCpy);
    quickSort(unordered, ARR_SIZE, qResults.unOrdCompares, qResults.unOrdCpy);
    quickSort(reversed, ARR_SIZE, qResults.revOrdCompares, qResults.revOrdCpy);
    calcResults(qResults);


    displayResults(iResults,sResults,bResults, shResults, hResults, qResults);


    return 0;
}

//*****************************************************************************************************

void getData(int list[], int size, const char* fname)
{
    ifstream infile(fname);

    int num;
    int i = 0;
    while (i < size && infile >> num)
    {
        list[i++] = num;
    }
}

//*****************************************************************************************************

void insertSort(int list[], int size, int& comp, int& cpy)
{
    int temp;
    int j;

    for (int i = 1; i < size; i++)
    {
        temp = list[i];
        cpy++;

        for (j = i - 1; j >= 0 && ++comp && list[j] > temp; j--)
        {
            list[j + 1] = list[j];
            cpy++;
        }
        list[j + 1] = temp;
        cpy++;
    }

}

//*****************************************************************************************************

void selSort(int list[], int size, int& comp, int& cpy)
{
    int min;

    for (int i = 0; i < (size - 1); i++)
    {
        min = i;

        for (int j = (i + 1); j < size; j++)
        {

            if ((++comp) && (list[j] < list[min]))
            {
                min = j;
            }
        }
        swap(list[min], list[i]);
        cpy += 3;
    }
}

//*****************************************************************************************************

void bubbleSort(int list[], int size, int& comp, int& cpy)
{
    bool s = true;

    for (int i = 0; i < (size - 1) && (s); i++)
    {
        s = false;

        for (int j = (size - 1); j > i; j--)
        {
            if ((++comp) && (list[j] < list[j - 1]))
            {
                swap(list[j], list[j - 1]);
                cpy += 3;
                s = true;
            }
        }
    }
}

//*****************************************************************************************************

void shellSort(int list[], int size, int& comp, int& cpy)
{
    int hold, y;

    for (int gap = (size / 2); gap >= 10; gap = gap / 2)
    {
        if (gap % 2 == 0)
        {
            gap++;
        }

        for (int i = gap; i < size; i++)
        {
            hold = list[i];
            cpy++;

            for (y = (i - gap); (y >= 0) && (++comp) && (list[y] > hold); y -= gap)
            {
                list[y + gap] = list[y];
                cpy++;
            }
            list[y + gap] = hold;
            cpy++;
        }
    }
    insertSort(list, size, comp, cpy);
}

//*****************************************************************************************************

void heapSort(int list[], int size, int& comp, int& cpy)
{
    for (int i = 1; i < size; i++)
    {
        _siftUp(list, i, comp, cpy);
    }

    for (int x = (size - 1); x > 0; x--)
    {
        swap(list[x] ,list[0]);
        cpy += 3;
        _siftDown(list, 0, x, comp, cpy);
    }

}

//*****************************************************************************************************

void _siftUp(int list[], int child, int& comp, int& cpy)
{
    int parent;

    if (child > 0)
    {
        parent = (child - 1) / 2;

        if ((++comp) && (list[child] > list[parent]))
        {
            swap(list[child], list[parent]);
            cpy += 3;
            _siftUp(list, parent, comp, cpy);
        }
    }
}

//*****************************************************************************************************

void _siftDown(int list[], int parent, int size, int& comp, int& cpy)
{
    int child;
    child = (parent * 2) + 1;

        if (child < size)
        {
            if ((child + 1 < size) && (++comp) && (list[child + 1] > list[child]))
            {
                child++;
            }

            if ((++comp) && (list[parent] < list[child]))
            {
                swap(list[parent], list[child]);
                cpy += 3;
                _siftDown(list, child, size, comp, cpy);
            }
        }
}

//*****************************************************************************************************

void quickSort(int list[], int size, int& comp, int& cpy)
{
    _quickSort(list, 0, (size - 1), comp, cpy);
    insertSort(list, size, comp, cpy);
}

//*****************************************************************************************************

void _quickSort(int list[], int left, int right, int& comp, int& cpy)
{
    int piviot;

    if (((right - left) + 1) > 11)
    {
        putMedianLeft(list, left, right, comp, cpy);
        piviot = partition(list, left, right, comp, cpy);
        _quickSort(list, left, (piviot - 1), comp, cpy);
        _quickSort(list, (piviot + 1), right, comp, cpy);
    }
}

//*****************************************************************************************************

void putMedianLeft(int list[], int left, int right, int& comp, int& cpy)
{
    int center = (right + left) / 2;

    if ((++comp) && (list[left] < list[center]))
    {
        swap(list[left], list[center]);
        cpy += 3;
    }
    if ((++comp) && (list[right] < list[center]))
    {
        swap(list[right], list[center]);
        cpy += 3;
    }
    if ((++comp) && (list[left] > list[right]))
    {
        swap(list[left], list[right]);
        cpy += 3;
    }
    
}

//*****************************************************************************************************

int partition(int list[], int left, int right, int& comp, int& cpy)
{
    int lte = left+1;
    int gt = right;


    while (lte <= gt)
    {

        while ((++comp) && (list[lte] <= list[left]))
        {
            lte++;
        }

        while ((++comp) && (list[gt] > list[left]))
        { 
            gt--;
        }

        if (lte < gt)
        {
            swap(list[lte], list[gt]);
            cpy += 3;
            lte++;
            gt--;
        }
    }

    swap(list[left], list[gt]);
    cpy += 3;
    return gt;
}

//*****************************************************************************************************

void calcResults(Results& result)
{
    result.avgCompares = (result.ordCompares + result.unOrdCompares + result.revOrdCompares) / 3;
    result.avgCpy = (result.ordCpy + result.unOrdCpy + result.revOrdCpy) / 3;
}

//*****************************************************************************************************

void displayResults(Results iResults, Results sResults, Results bResults, Results shResults, Results hResults, Results qResults)
{
    cout << string(32, '=') << "cpompares/copies" << string(32, '=') << endl;
    cout <<"sorts" << setw(16) << "Ordered List" << setw(19) << "UnOrdered List" << setw(18) << "Reversed List" << setw(13) << "average" << endl;
    displayReuslt(iResults, "Insert");
    displayReuslt(sResults, "Select");
    displayReuslt(bResults, "bubble");
    displayReuslt(shResults, "Shell ");
    displayReuslt(hResults, "Heap  ");
    displayReuslt(qResults, "Quick ");
    cout << string(80, '=');
}

//*****************************************************************************************************

void displayReuslt(Results result, const char* sort)
{

    cout << sort << setw(9) << result.ordCompares << "/" << setw(7) << result.ordCpy << setw(9)
        << result.unOrdCompares << "/" << setw(7) << result.unOrdCpy << setw(11)
        << result.revOrdCompares << "/" << setw(7) << result.revOrdCpy << setw(11)
        << result.avgCompares << "/" << setw(7) << result.avgCpy << endl;
}

//*****************************************************************************************************

//output 

//the spaceing is correct in the program output it did not stay in the copy

//================================cpompares / copies================================
//sorts    Ordered List     UnOrdered List     Reversed List      average
//Insert      999 / 1998   257314 / 258317     499500 / 501498     252604 / 253937
//Select   499500 / 2997   499500 / 2997     499500 / 2997     499500 / 2997
//bubble      999 / 0   499065 / 768957     499500 / 1498500     333188 / 755819
//Shell      6013 / 12026    20949 / 27513      13781 / 20780      13581 / 20106
//Heap      22462 / 47922    17194 / 28575      15965 / 24948      18540 / 33815
//Quick      8387 / 2760    10994 / 9213       8387 / 4260       9256 / 5411
//================================================================================
