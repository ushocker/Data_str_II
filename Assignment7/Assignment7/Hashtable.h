
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <new>
#include <iomanip>
#include "Node.h"




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
	
};



template<typename T>
Hashtable<T>::Hashtable(int s)
{
	s++;
	if (s % 2)
	{
		s++;
	}
	while (_isPrime(s))
	{
		s += 2;
	}

	size = s;
	table = new Node<T>[size];
}

//******************Here**************************

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
}

//******************Here**************************

template<typename T>
bool Hashtable<T>::insert(const T& input)
{
	bool success = false;
	Node<T>* nNode;
	int hash = _hash(input);

	if (table[hash].data != 0)  
	{
		nNode = new (nothrow) Node<T>(input, table[hash].next);

		if (nNode != nullptr)
		{
			table[hash].next = nNode;
			success = true;
		}
	}
	else
	{
		table[hash].data = input;
		success = true;
	}

	return success;
}

template<typename T>
void Hashtable<T>::displayTable() const
{
	_tableOut(cout);
}

template<typename T>
void Hashtable<T>::writeFile() const
{
	ofstream offile("studentTable.txt");
	_tableOut(offile);
	offile.close;

}

template<typename T>
bool Hashtable<T>::_isPrime(int input) const
{
	bool result = true;

	for (int i = 3; i < 21 && result; i += 2)
	{
		if (input % i == 0)
		{
			result = false;
		}
	}

	return result;
}



template<typename T>
int Hashtable<T>::_hash(const T& data) const
{
	return data % size;
}

template<typename T>
void Hashtable<T>::_tableOut(ostream& out) const
{
	Node<T>* pTemp;

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