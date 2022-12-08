//*****************************************************************************************************
//
//		File:					Results.h
//
//		Customer:				Urban Shocker
//
//		Assignment:				Program #10
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					16/11/22
//
//
//		This program is the driver program for Heap
//	
//		Other files required: 
//			1.	sortComp.cpp
//			
//*****************************************************************************************************

#ifndef RESULTS_H
#define RESULTS_H

//*****************************************************************************************************

struct Results
{
	int ordCompares;
	int unOrdCompares;
	int revOrdCompares;
	int avgCompares;
	int ordCpy;
	int unOrdCpy;
	int revOrdCpy;
	int avgCpy;
	Results();
};
//*****************************************************************************************************
Results::Results()
{
	ordCompares = 0;
	unOrdCompares = 0;
	revOrdCompares = 0;
	avgCompares = 0;
	ordCpy = 0;
	unOrdCpy = 0;
	revOrdCpy = 0;
	avgCpy = 0;
}
//*****************************************************************************************************
#endif // !RESULTS_H
