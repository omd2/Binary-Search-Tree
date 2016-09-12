//
//  BNode.h
//  BST
//

#ifndef BST_BNode_h
#define BST_BNode_h

#include <iostream> 
#include <stdexcept>
#include <string>
#include <new> 
#include "int.h"
#include "char.h"

using namespace std;

template <typename T>
class BNode{
    
    template <typename B>
    friend class BinaryTree;
    
public:
    BNode();
    BNode(T&);
    BNode(const BNode<T>&);
    
    void setObject(T&);
    void setRight(BNode<T>*);
    void setLeft(BNode<T>*);
    BNode<T>*& getRight();
    BNode<T>*& getLeft();
    T*& getObject();
    
    BNode<T>& operator = (const BNode<T>&);
    bool operator < (const BNode<T>&)const;
    bool operator > (const BNode<T>&)const;
    bool operator == (const BNode<T>&)const;
    
    void linkNew(BNode<T>*&, T&);
    void print();
    
    ~BNode();
    
private:
    T * data;
    BNode<T>* left;
    BNode<T>* right;
};

// Default constructor
template<typename T>
BNode<T>::BNode()
{
    data = NULL;
    left = NULL;
    right = NULL;
}

// Constructor
template<typename T>
BNode<T>::BNode(T& data)
{
    this->data = new T;
    *(this->data) = data;
    left = NULL;
    right = NULL;
}

// Copy Constructor
template<typename T>
BNode<T>::BNode(const BNode<T>& bnode)
{
    *this = bnode;
}

// Returns right pointer
template<typename T>
BNode<T>*& BNode<T>::getRight()
{
    return right;
}

// Returns left pointer
template<typename T>
BNode<T>*& BNode<T>::getLeft()
{
    return left;
}

// Sets objects
template<typename T>
void BNode<T>::setObject(T& data)
{
    if (this->data != NULL)
        delete this->data;
    this->data = new T;
    *(this->data) = data;
}

// Set right pointer
template<typename T>
void BNode<T>::setRight(BNode<T> *right)
{
    if (this->right != NULL)
        delete this->right;
    this->right = right;
}

// Set left pointer
template<typename T>
void BNode<T>::setLeft(BNode<T> *right)
{
    if (this->left != NULL)
        delete this->left;
    this->left = left;
}

// Returns data
template<typename T>
T*& BNode<T>::getObject()
{
    return data;
}

// Assignment operator
template<typename T>
BNode<T>& BNode<T>::operator=(const BNode<T> & bnode)
{
    if (data != NULL)
    {
        delete data;
    }
    
    this->data = new T;
    *(this->data) = (*bnode.data);
    return *this;
}

// Returns true if less than
template<typename T>
bool BNode<T>::operator<(const BNode<T> & bnode)const
{
    if (*(data) < *(bnode.data)) {
        return true;
    }
    else
        return false;
}

// Returns true if greater than
template<typename T>
bool BNode<T>::operator>(const BNode<T> & bnode)const
{
    if (*(data) > *(bnode.data)) {
        return true;
    }
    else
        return false;
}

// Returns true if equal to
template<typename T>
bool BNode<T>::operator==(const BNode<T> & bnode)const
{
    if (*(data) == *(bnode.data)) {
        return true;
    }
    else
        return false;
}

// Prints data
template<typename T>
void BNode<T>::print()
{
    cout << *data;
}

// Destructor
template<typename T>
BNode<T>::~BNode()
{
    delete data;
}

#endif
