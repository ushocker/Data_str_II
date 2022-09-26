

#ifndef Node_H
#define Node_H

//*****************************************************************************************************

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node();
	Node(const T&, Node<T>* = nullptr);

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
Node<T>::Node(const T& dataIn, Node<T>* n)
{
	data = dataIn;
	next = n;
}

#endif // !Node_H

