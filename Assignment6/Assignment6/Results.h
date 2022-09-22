//*****************************************************************************************************
//
//		File:					Results.h
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
//		This program is an additional file for searches.cpp
//	
//		Other files required: 
//			1.	Searches.cpp
//			
//*****************************************************************************************************

#ifndef RESULTS_H
#define RESULTS_H

//*****************************************************************************************************

struct Results
{
	int numSuccesses,
		totalCompares;
	double percSuccesses,
		avgNumCompares;

	Results();
};

//*****************************************************************************************************

Results::Results()
{
	numSuccesses = 0;
	totalCompares = 0;
}


#endif

