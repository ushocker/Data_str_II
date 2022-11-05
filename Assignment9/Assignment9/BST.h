//*****************************************************************************************************
//
//		File:					BST.h
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

#include <new>
#include <algorithm>
#include "Node.h"


#ifndef BST_H
#define BST_H

//*****************************************************************************************************

template <typename T>
class BST
{
	Node<T>* root;

public:
	BST();
	~BST();
	bool retrieve(T & dataOut) const;
	bool insert(const T & dataIn);
	bool remove(T& dataOut);
	bool update(const T& dataIn);
	void inorderTraverse(void(*func)(T d))const;
	int getCount() const;
	int getHt() const;
	bool isEmpty() const;
	bool isFull() const;
	bool isComplete() const;
	bool isBalanced() const;

private:
	void _destruct(Node<T>* pRoot);
	Node<T>* _retreve(const T& dataOut, Node<T>* pRoot) const;
	Node<T>* _insert(const T& dataIn, Node<T>* pRoot);
	Node<T>* _remove(const T& dataOut, Node<T>* pRoot);
	void _inorderTraverse(void(*func)(T d), Node<T>* pRoot) const;
	int _getCount(Node<T>* pRoot) const;
	int _getHt(Node<T>* pRoot) const;
	bool _isComplete(Node<T>* pRoot) const;
	bool _isBalanced(Node<T>* pRoot) const;

};

//*****************************************************************************************************

template<typename T>
 BST<T>::BST()
{
	 root = nullptr;
}

 //*****************************************************************************************************

 template<typename T>
 inline BST<T>::~BST()
 {
	 _destruct(root);
	 root = nullptr;
 }

 //*****************************************************************************************************

 template<typename T>
 bool BST<T>::retrieve(T& dataOut) const
 {
	 bool success = false;
	 Node<T>* pTemp;

	 pTemp = _retreve(dataOut, root);

	 if (pTemp != nullptr)
	 {
		 dataOut = pTemp->data;
		 success = true;
	 }

	 return success;
 }

 //*****************************************************************************************************

 template<typename T>
 bool BST<T>::insert(const T& dataIn)
 {
	 bool success = false;
	 Node<T>* pTemp = nullptr;

	 pTemp = _retreve(dataIn, root);

	 if (pTemp == nullptr)
	 {
		 root = _insert(dataIn, root);
		 success = true;
	 }

	 return success;
 }

 //*****************************************************************************************************

 template<typename T>
 bool BST<T>::remove(T& dataOut)
 {
	 bool success = false;
	 Node<T>* pTemp;

	 pTemp = _retreve(dataOut, root);

	 if (pTemp != nullptr)
	 {
		 root = _remove(dataOut, root);
		 dataOut = pTemp->data;
		 success = true;
	 }


	 return success;
 }

 //*****************************************************************************************************

 template<typename T>
 bool BST<T>::update(const T& dataIn)
 {
	 bool success = false;
	 Node<T>* pTemp = nullptr;

	 pTemp = _retreve(dataIn, root);

	 if (pTemp != nullptr)
	 {
		 pTemp->data = dataIn;
		 success = true;
	 }

	 return success;
 }

 //*****************************************************************************************************

 template<typename T>
 void BST<T>::inorderTraverse(void(*func)(T d)) const
 {
	 _inorderTraverse(func, root);
 }

 //*****************************************************************************************************

 template<typename T>
 int BST<T>::getCount() const
 {
	 return _getCount(root);
 }

 //*****************************************************************************************************

 template<typename T>
 inline int BST<T>::getHt() const
 {
	 return _getHt(root) - 1;
 }

 //*****************************************************************************************************

 template<typename T>
 bool BST<T>::isEmpty() const
 {
	 bool empty = true;
	 if (root != nullptr)
	 {
		 empty = false;
	 }

	 return empty;
 }

 //*****************************************************************************************************

 template<typename T>
 inline bool BST<T>::isFull() const
 {
	 bool full = true;
	 Node<T>* pNew = new(nothrow) Node<T>;

	 if (pNew != nullptr)
	 {
		 full = false;
		 delete pNew;
	 }

	 return full;
 }

 //*****************************************************************************************************

 template<typename T>
 bool BST<T>::isComplete() const
 {
	 return _isComplete(root);
 }

 //*****************************************************************************************************

 template<typename T>
 bool BST<T>::isBalanced() const
 {
	 return _isBalanced(root);
 }

 //*****************************************************************************************************

 template<typename T>
 void BST<T>::_destruct(Node<T>* pRoot)
 {
	 if (pRoot != nullptr)
	 {
		 _destruct(pRoot->left);
		 _destruct(pRoot->right);
		 delete pRoot;
	 }
 }

 //*****************************************************************************************************

 template<typename T>
 Node<T>* BST<T>::_retreve(const T& dataOut, Node<T>* pRoot) const
 {
	 Node<T>* pTemp = nullptr;

	 if (pRoot != nullptr)
	 {
		 if (pRoot->data > dataOut)
		 {
			 pTemp = _retreve(dataOut, pRoot->left);
		 }
		 else if(pRoot->data < dataOut)
		 {
			 pTemp = _retreve(dataOut, pRoot->right);
		 }
		 else
		 {
			 pTemp = pRoot;
		 }
	 }
	 return pTemp;
 }

 //*****************************************************************************************************

 template<typename T>
 Node<T>* BST<T>::_insert(const T& dataIn, Node<T>* pRoot)
 {
	 if (pRoot != nullptr)
	 {
		 if (pRoot->data > dataIn)
		 {
			 pRoot->left = _insert(dataIn, pRoot->left);
		 }
		 else
		 {
			 pRoot->right = _insert(dataIn, pRoot->right);
		 }
	 }
	 else
	 {
		 pRoot = new (nothrow) Node<T>(dataIn);
	 }


	 return pRoot;
 }

 //*****************************************************************************************************

 template<typename T>
 Node<T>* BST<T>::_remove(const T& dataOut, Node<T>* pRoot)
 {
	 Node<T>* pDel;
	 Node<T>* pTemp;

	 if (pRoot != nullptr)
	 {
		 if (pRoot->data > dataOut)
		 {
			 pRoot->left = _remove(dataOut, pRoot->left);
		 }
		 else if (pRoot->data < dataOut)
		 {
			 pRoot->right = _remove(dataOut, pRoot->right);
		 }
		 else
		 {
			 if ((pRoot->left != nullptr) && (pRoot->right != nullptr))
			 {
				 pTemp = pRoot->left;
				 
				 while ((pTemp != nullptr) && (pTemp->right != nullptr))
				 {
					 pTemp = pTemp->right;
				 }
				 pRoot->data = pTemp->data;
				 pRoot->left = _remove(dataOut, pRoot->left);
			 }
			 else
			 {
				 pDel = pRoot;
				 if (pRoot->left != nullptr)
				 {
					 pRoot = pRoot->left;
				 }
				 else
				 {
					 pRoot = pRoot->right;
				 }
				 delete pDel;
			 }
		 }
		 
	 }

	 return pRoot;
 }

 //*****************************************************************************************************

 template<typename T>
 void BST<T>::_inorderTraverse(void(*func)(T d), Node<T>* pRoot) const
 {
	 if (pRoot != nullptr)
	 {
		 _inorderTraverse(func, pRoot->left);
		 func(pRoot->data);
		 _inorderTraverse(func, pRoot->right);
	 }
 }

 //*****************************************************************************************************

 template<typename T>
 int BST<T>::_getCount(Node<T>* pRoot) const
 {
	 int count = 0;
	
	 if (pRoot != nullptr)
	 {
		 count = 1 + _getCount(pRoot->left) + _getCount(pRoot->right);
	 }

	 return count;
 }

 //*****************************************************************************************************

 template<typename T>
 int BST<T>::_getHt(Node<T>* pRoot) const
 {
	 int height = 0;

	 if (pRoot != nullptr)
	 {
		 height = 1 + max(_getHt(pRoot->left), _getHt(pRoot->right));
	 }

	 return height;
 }

 //*****************************************************************************************************

 template<typename T>
 bool BST<T>::_isComplete(Node<T>* pRoot)  const
 {
	 bool complete = true;
	 if (pRoot != nullptr)
	 {
		 if (_getHt(pRoot->left) == _getHt(pRoot->right))
		 {
			 complete = _isComplete(pRoot->left) && _isComplete(pRoot->right);
		 }
		 else
		 {
			 complete = false;
		 }
	 }
	 return complete;
 }

 //*****************************************************************************************************

 template<typename T>
 bool BST<T>::_isBalanced(Node<T>* pRoot) const
 {
	 bool bal = true;

	 if (pRoot != nullptr)
	 {
		 if (abs(_getHt(pRoot->left) - _getHt(pRoot->right)) <= 1)
		 {
			 bal = _isBalanced(pRoot->left) && _isBalanced(pRoot->right);
		 }
		 else
		 {
			 bal = false;
		 }
	 }
	 return bal;
 }

#endif // !BST_H