#ifndef RESULTS_H
#define RESULTS_H

struct Results
{
	int numSuccesses,
		totalCompares;
	double percSuccesses,
		avgNumCompares;
};

Results::Results()
{
	numSuccesses = 0;
	totalCompares = 0;
	percSuccesses = 0.0;
	avgNumCompares = 0.0;
}


#endif

