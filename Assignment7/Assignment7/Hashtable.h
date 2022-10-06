//*****************************************************************************************************
//
//		File:					Hashtable.h
//
//		Student:				Urban Shocker
//
//		Assignment:				Program #08
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					06/10/22
//
//
//		This program Creates the student data structure
//	
//		Other files required: 
//			1.	Node.h
//			2.	StudentList.cpp
//          3.  student.h
//			
//*****************************************************************************************************

#ifndef Hashtable_H
#define Hashtable_H

#include <new>

#include "Node.h"

//*****************************************************************************************************

template <typename T>
class Hashtable
{
private:
	Node<T>* table;
	int size;

	bool _isPrime(int) const;
	int _hash(const T&) const;
	void _tableOut(ostream& out) const;

public:
	Hashtable(int = 23);
	~Hashtable();
	bool insert(const T&);
	void displayTable() const;
	void writeFile() const;
	bool remove(T& dataOut);
	bool retrieve(T& dataOut) const;
	bool isEmpty() const;
	void statistics() const;
	
};

//*****************************************************************************************************

template<typename T>
Hashtable<T>::Hashtable(int s)
{
	s++;

	if (s % 2 == 0)
	{
		s++;
	}

	while (!_isPrime(s))
	{
		s += 2;
	}

	size = s;
	table = new Node<T>[size];
}

//*****************************************************************************************************

template<typename T>
Hashtable<T>::~Hashtable()
{
	Node<T>* pTemp;

	for (int i = 0; i < size; i++)
	{
		while (table[i].next != nullptr)
		{
			pTemp = table[i].next;
			table[i].next = pTemp->next;
			delete pTemp;
		}
	}

	delete[] table;
	size = 0;
}

//*****************************************************************************************************

template<typename T>
bool Hashtable<T>::insert(const T& datain)
{
	bool success = false;
	Node<T>* nNode;
	int loc;

		loc = _hash(datain);

	if (table[loc].data != 0)  
	{
		nNode = new (nothrow) Node<T>(datain, table[loc].next);

		if (nNode != nullptr)
		{
			table[loc].next = nNode;
			success = true;
		}
	}
	else
	{
		table[loc].data = datain;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
void Hashtable<T>::displayTable() const
{
	_tableOut(cout);
}

//*****************************************************************************************************

template<typename T>
void Hashtable<T>::writeFile() const
{
	ofstream offile("studentTable.txt");
	_tableOut(offile);
	offile.close();

}

//*****************************************************************************************************

template<typename T>
bool Hashtable<T>::remove(T& dataOut)
{
	bool success = false;
	int loc;
	Node<T>* pTemp;
	Node<T>* pPrev;

	loc = _hash(dataOut);
	pTemp = table[loc].next;
	pPrev = &table[loc];
	
	if (table[loc].data == dataOut)
	{
		dataOut = table[loc].data;
		if (table[loc].next != nullptr)
		{
			table[loc] = *pTemp;
			delete pTemp;
		}
		else
		{
			table[loc].data = 0;
		}
		success = true;
	}
	else
	{
		while ((pTemp != nullptr) && (pTemp->data != dataOut))
		{
			pPrev = pTemp;
			pTemp = pTemp->next;
		}
		if ((pTemp != nullptr) && (pTemp->data == dataOut))
		{
			dataOut = pTemp->data;

			if(pPrev != nullptr)
				pPrev->next = pTemp->next;

			delete pTemp;
			success = true;
		}
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool Hashtable<T>::retrieve(T& dataOut) const
{
	bool success = false;
	Node<T>* pTemp;
	int loc;
	
	loc = _hash(dataOut);
	pTemp = table[loc].next;

	if (table[loc].data == dataOut)
	{
		dataOut = table[loc].data;
		success = true;
	}

	while (pTemp != nullptr && pTemp->data != dataOut)
	{
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->data == dataOut)
	{
		dataOut = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool Hashtable<T>::isEmpty() const
{
	bool empty = true;
	for (int i = 0; i < size && empty; i++)
	{
		if (table[i].data != 0)
		{
			empty = false;
		}
	}

	return empty;
}

//*****************************************************************************************************

template<typename T>
void Hashtable<T>::statistics() const
{
	int numberElements = 0,
		emptyElements = 0,
		overflow = 0,
		maxOverflow = 0,
		totalCollisions = 0,
		temp,
		totalSearch = 0;

	double avgLen,
		loadfactor,
		precentCollisions,
		avgSteps;

	Node<T>* pTemp;


	for (int i = 0; i < size; i++)
	{
		pTemp = table[i].next;

		if (table[i].data == 0)
		{

			emptyElements++;

		}
		else
		{
			numberElements++;
			totalSearch++;

			if (pTemp != nullptr)
			{
				temp = 0;
				overflow++;

				while (pTemp != nullptr)
				{
					temp++;
					totalSearch += (temp + 1);
					pTemp = pTemp->next;
					numberElements++;
					totalCollisions++;
				}
				if (temp > maxOverflow)
				{
					maxOverflow = temp;
				}
			}
		}
		
		
	}

	avgLen = totalCollisions / (double) overflow;
	loadfactor = ((size - emptyElements) / (double) size) * 100;
	precentCollisions = (totalCollisions / (double) numberElements) * 100;
	avgSteps = totalSearch / (double)numberElements;

	cout << "Table size:" << setw(15) << size << endl;
	cout << "Number of Elements:" << setw(7) << numberElements << endl;
	cout << "Empty Positions:" << setw(10) << emptyElements << endl;
	cout << "Num.of Chains:" << setw(12) << overflow << endl;
	cout << "Max Chain Length:" << setw(9) << maxOverflow << endl;
	cout << "Num. of Collisions:" << setw(7) << totalCollisions << endl;
	cout << "Avg.Chain Length:" << setw(11) << fixed << setprecision(1) << avgLen << "%" << endl;
	cout << "Percentage Collisions:" << setw(6) << precentCollisions << "%" << endl;
	cout << "Load Factor:" << setw(16) << loadfactor << "%" << endl;
	cout << "Avg# Search Steps:" << setw(12) << setprecision(3) << avgSteps << endl;

}

//*****************************************************************************************************

template<typename T>
bool Hashtable<T>::_isPrime(int input) const
{
	bool result = true;

	for (int i = 3; i < 20 && result; i += 2)
	{
		if (input % i == 0)
		{
			result = false;
		}
	}

	return result;
}

//*****************************************************************************************************

template<typename T>
int Hashtable<T>::_hash(const T& data) const
{
	return data % size;
}

//*****************************************************************************************************

template<typename T>
void Hashtable<T>::_tableOut(ostream& out) const
{
	Node<T>* pTemp;

	out << "Address prime area" << setw(18) << "Overflow" << endl;
	for (int i = 0; i < size; i++)
	{
		out << '[' << setfill('0') << setw(2) << i << ']' << setfill(' ') << setw(2) << "";
		if (table[i].data != 0)
		{
			out << table[i].data << setw(7) << "";
			pTemp = table[i].next;

			while (pTemp != nullptr)
			{
				out << setw(3) << "" << pTemp->data;
				pTemp = pTemp->next;
				if (pTemp != nullptr)
					out << ',';
			}
			
		}
		
		out << endl;

	}
}

#endif