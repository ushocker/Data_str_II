

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void displayNum(long long int, int);


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

        while (infile)
        {

            infile >> input;
            infile.ignore();
            infile >> num;
            infile.ignore();

            displayNum(input, (int)pow(10, num));

        }

    }
    infile.close();

}

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
