//*****************************************************************************************************
//
//		File:					Node.h
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
//		This program Creates the student data structure (Edited for HW 07-10 for BIN tree)
//	
//		Other files required: 
//			1.	Student.h
//			2.	StudentList.cpp
//          3.  BST.h
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
	union
	{
		Node<T>* next;
		Node<T>* left;
	};

	union
	{
		Node<T>* prev;
		Node<T>* right;
	};

	Node();
	Node(const T&, Node<T>* = nullptr, Node<T>* = nullptr);

};

//*****************************************************************************************************

template<typename T>
Node<T>::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
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

