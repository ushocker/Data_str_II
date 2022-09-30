//*****************************************************************************************************
//
//		File:					Node.h
//
//		Student:				Urban Shocker
//
//		Assignment:				Program #07
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					22/09/22
//
//
//		This program Creates the student data structure
//	
//		Other files required: 
//			1.	Student.h
//			2.	StudentList.cpp
//          3.  Hashtable.h
//			
//*****************************************************************************************************

#ifndef Node_H
#define Node_H

//*****************************************************************************************************

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;

	Node();
	Node(const T&, Node<T>* = nullptr, Node<T>* = nullptr);

};

//*****************************************************************************************************

template<typename T>
Node<T>::Node()
{
	data = 0;
	next = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(const T& dataIn, Node<T>* n, Node<T>* p)
{
	data = dataIn;
	next = n;
	prev = p;
}

#endif // !Node_H

