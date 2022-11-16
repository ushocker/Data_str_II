#ifndef HEAP_H
#define HEAP_H

#include <New>


template <typename T>
class Heap
{
private:
	T* heap;
	int numValues;
	int capacity;

	void _siftUp(int c);
	void _siftDown(int p);
	int _leftChildOf(int p) const;
	int _parentOf(int c) const;


public:
	Heap(int c = 100);
	~Heap();
	bool insert(const T& dataIn);
	bool remove(T& dataOut);
	bool viewMax(T& dataOut) const;
	int getCapacity();
	int getNumValues() const;
	bool isEmpty() const;
	bool isFull() const;

};

template<typename T>
void Heap<T>::_siftUp(int c)
{
	int parent;

	if (c > 0)
	{
		parent = _parentOf(c);

		if (heap[c] > heap[parent])
		{
			swap(heap[c], heap[parent]);
			_siftUp(parent);
		}
	}
}

template<typename T>
void Heap<T>::_siftDown(int p)
{
	int child;
	child = _leftChildOf(p);

	if (child < numValues)
	{
		if (child + 1 < numValues && heap[child + 1] > heap[child])
		{
			child++;
		}

		if(heap[p] < heap[child])
		{
			swap(heap[p], heap[child]);
			_siftDown(child);
		}
	}
}

template<typename T>
int Heap<T>::_leftChildOf(int p) const
{
	return ((p*2)+1);
}

template<typename T>
int Heap<T>::_parentOf(int c) const
{
	return ((c - 1) / 2);
}

template<typename T>
Heap<T>::Heap(int c)
{
	capacity = c;
	heap = new T[capacity];
	numValues = 0;
}

template<typename T>
Heap<T>::~Heap()
{
	delete[] heap;
	numValues = 0;
	capacity = 0;
	heap = nullptr;
}

template<typename T>
bool Heap<T>::insert(const T& dataIn)
{
	bool success = false;

	if (numValues < capacity)
	{
		heap[numValues] = dataIn;
		_siftUp(numValues);
		numValues++;
		success = true;
	}

	return success;
}

template<typename T>
bool Heap<T>::remove(T& dataOut)
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = heap[0];
		numValues--;
		heap[0] = heap[numValues];
		_siftDown(0);
		success = true;
	}

	return success;
}

template<typename T>
bool Heap<T>::viewMax(T& dataOut) const
{
	bool success = false;

	if (numValues > 0)
	{
		dataOut = heap[0];
		success = true;
	}

	return success;
}

template<typename T>
int Heap<T>::getCapacity()
{
	return capacity;
}

template<typename T>
int Heap<T>::getNumValues() const
{
	return numValues;
}

template<typename T>
bool Heap<T>::isEmpty() const
{
	return numValues == 0;
}

template<typename T>
bool Heap<T>::isFull() const
{
	return numValues > capacity;
}

#endif // !HEAP_H