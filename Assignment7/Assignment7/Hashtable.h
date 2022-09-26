
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <new>
#include "Node.h"



template <typename T>
class Hashtable
{
private:
	Node<T>* table;
	int size;

	bool _isPrime(int) const;
	int _hash(const T&) const;

public:
	Hashtable(int = 23);
	~Hashtable();
	bool insert(const T&);
	
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
	Node<T>* pTemp;
	int hash = _hash(input);

	if (table[hash].data)  
	{
		nNode = new (nothrow) Node<T>(input, nullptr);

		if (table[hash].next != nullptr)
		{
			pTemp = table[hash].next;
			while (pTemp->next != nullptr)
			{
				pTemp = pTemp->next;
			}

			pTemp->next = nNode;

		}
		else
		{
			table[hash].next = nNode;
		}
		success = true;
	}
	else
	{
		table[hash].data = input;
		success = true;
	}

	return success;
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

#endif