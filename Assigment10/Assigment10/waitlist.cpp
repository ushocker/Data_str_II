
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

#include "customer.h"
#include "Heap.h"

void getData(Heap<Customer>& waitList);
void printWaitList(Heap<Customer>& waitList);

int main()
{
    Heap<Customer> waitlist;


    getData(waitlist);
    printWaitList(waitlist);
}

void getData(Heap<Customer>& waitList)
{
    Customer cust;
    ifstream infile("overbooked.bin", ios::binary);



    while (infile.read((char*)&cust, sizeof(cust)))
    {
        cust.Priority = ((cust.mileage / 1000) + cust.years) - cust.arrivalNum;
        waitList.insert(cust);
    }

    infile.close();
}

void printWaitList(Heap<Customer>& waitList)
{
    Customer cust;
    ofstream outfile("waitList.txt");
    
    outfile << string(60,61) << endl; //used to draw lines of =
    outfile << setw(30) << "Wait List" << endl;
    outfile << string(60, 61) << endl; //used to draw lines of =
    outfile << setw(6) << "" << left << setw(16) << "Last Name" << setw(16) << "First Name" << setw(8) << "Arival" << "Priority" << endl;

    while (waitList.remove(cust))
    {
        outfile << setw(6) << "" << cust << endl;
    }

    outfile << string(60, 61) << endl; //used to draw lines of =
}

