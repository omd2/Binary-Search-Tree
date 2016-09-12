//
//  BinaryTree.h
//  BST
//


#ifndef BST_BinaryTree_h
#define BST_BinaryTree_h

#include "BNode.h"
#include "int.h"
#include "char.h"

template<typename T>
class BinaryTree{
    
public:
    BinaryTree();
    BinaryTree(T&);
    
    void insert(T&);
    void printInOrder();
    void printPostOrder();
    void printPreOrder();
    bool find(T&);
    void deleteThis(T&);
    void deleteAll();
    int height();
    
    ~BinaryTree();
    
private:
    BNode<T>* root;
    unsigned size;
    
    void insert(T&, BNode<T>*&);
    bool find(T&, BNode<T>*&);
    void printSub(BNode<T>*&);
    void printPre(BNode<T>*&);
    void printPost(BNode<T>*&);
    void deleteSub(BNode<T>*&);
    BNode<T>*& findReference(T&, BNode<T>*&);
    int height(BNode<T>*&);
};

// Default constructor
template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
    size = 0;
}

// Constructor
template<typename T>
BinaryTree<T>::BinaryTree(T& key)
{
    root = new BNode<T>;
    *root = key;
    size++;
}

// Inserts key
template<typename T>
void BinaryTree<T>::insert(T& key)
{
    insert(key, this->root);
    size++;
}

// Private insert, recursively finds pointer to insert to
template<typename T>
void BinaryTree<T>::insert(T& key, BNode<T>*& temp)
{
    if (temp == NULL)
    {
        temp = new BNode<T>;
        *temp = key;
    }
    else
    {
        if (key < *(temp->getObject())) {
            insert(key, temp->getLeft());
        }
        if (key > *(temp->getObject())) {
            insert(key, temp->getRight());
        }
        if (key == *(temp->getObject())) {
            cout << "Key already exists." << endl;
        }
    }
}
            
// Find key, returns tru if found
template<typename T>
bool BinaryTree<T>::find(T& key)
{
    return find(key, root);
}
            
// Returns true if it can recursively find key
template<typename T>
bool BinaryTree<T>::find(T& key, BNode<T>*& current)
{
    if (current == NULL)
    {
        return false;
    }
    else
    {
        if (key < *(current->getObject())) {
            return find(key, current->getRight());
        }
        if (key > *(current->getObject())) {
            return find(key, current->getLeft());
        }
        if (key == *(current->getObject())) {
            return true;
        }
    }
    return false;
}

// Returns reference to node with key, returns NULL if doesn't exist
template<typename T>
BNode<T>*& BinaryTree<T>::findReference(T& key, BNode<T>*& current)
{
    if (current == NULL)
    {
        return current;
    }
    else
    {
        if (key < *(current->getObject())) {
            return findReference(key, current->getRight());
        }
            if (key > *(current->getObject())) {
            return findReference(key, current->getLeft());
        }
            if (key == *(current->getObject())) {
            return current;
        }
    }
    
    return current;
}

// Print in order
template<typename T>
void BinaryTree<T>::printInOrder()
{
    if (root == NULL)
        cout << "Tree is empty." << endl;
    else
    {
        printSub(root);
    }
}
                
// Print pre order
template<typename T>
void BinaryTree<T>::printPreOrder()
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
    }
    else
    {
        printPre(root);
    }
}

// Print post order
template<typename T>
void BinaryTree<T>::printPostOrder()
{
    if (root == NULL)
        cout << "Tree is empty." << endl;
    else
    {
        printPost(root);
    }
}
                
// Print in order internal
template<typename T>
void BinaryTree<T>::printSub(BNode<T>*& current)
{
    if (current == NULL)
        return;
    
    printSub(current->getLeft());
    cout << *(current->getObject()) << endl;
    printSub(current->getRight());
}
                
// Print pre order internal
template<typename T>
void BinaryTree<T>::printPre(BNode<T>*& current)
{
    if (current == NULL)
        return;
    
    cout << *(current->getObject()) << endl;
    printPre(current->getLeft());
    printPre(current->getRight());
}
                
                
// Print post order internal
template<typename T>
void BinaryTree<T>::printPost(BNode<T>*& current)
{
    if (current == NULL)
        return;
    
    printPost(current->getLeft());
    printPost(current->getRight());
    cout << *(current->getObject()) << endl;
}

// Deletes a key, returns an error message if not found
template<typename T>
void BinaryTree<T>::deleteThis(T& key)
{
    BNode<T> temp;
    
    if(!(find(key)))
    {
        cout << "Key Not Found." << endl;
        return;
    }
    
    BNode<T>*& current = findReference(key, root);
    
    if (current == NULL)
    {
        cout << "Key Not Found." << endl;
        return;
    }
    
    if ((current->getLeft() == NULL) && (current->getRight() == NULL))
    {
        temp = current;
        current = NULL;
        delete temp;
        size--;
        cout << "Key Deleted." << endl;
        return;
    }
    
    if ((current->getLeft() != NULL) && (current->getRight() == NULL))
    {
        temp = current;
        current = current->getLeft();
        delete temp;
        size --;
        cout << "Key Deleted." << endl;
        return;
    }

    if ((current->getLeft() == NULL) && (current->getRight() != NULL))
    {
        temp = current;
        current = current->getRight();
        delete temp;
        size --;
        cout << "Key Deleted." << endl;
        return;
    }

    if ((current->getLeft() != NULL) && (current->getRight() != NULL))
    {
        BNode<T> *nextHighest, *remove;
        temp = remove = current;
        nextHighest = current->getRight();
        
        if (nextHighest->getLeft() == NULL)
        {
            current = nextHighest;
            current->setLeft(remove->getLeft());
            delete remove;
            size --;
            cout << "Key Deleted." << endl;
            return;
        }
        
        while (nextHighest->getLeft() != NULL)
        {
            temp = nextHighest;
            nextHighest = nextHighest->getLeft();
        }
        
        temp->setLeft(NULL);
        current = nextHighest;
        nextHighest->setLeft(remove->getLeft());
        nextHighest->setRight(remove->getRight());
        delete remove;
        size --;
        cout << "Key Deleted." << endl;
    }
}
           
// Returns height
template<typename T>
int BinaryTree<T>::height()
{
    if (root == NULL)
        return 0;
    
    return height(root);
}

// Recursively finds height
template<typename T>
int BinaryTree<T>::height(BNode<T>*& current)
{
    if (current == NULL)
        return -1;
    int rightHeight = height(current->getRight());
    int leftHeight = height(current->getLeft());
    
    if (rightHeight>leftHeight)
        return rightHeight + 1;
    else
        return leftHeight + 1;
}
                
// Recursively deletes
template<typename T>
void BinaryTree<T>::deleteSub(BNode<T>*& current)
{
    BNode<T>*& temp = current;
    
    if (current == NULL)
        return;
    
    // Deletes a leaf with no children
    if ((current->getRight() == NULL) && (current->getLeft() == NULL))
    {
        temp = current;
        current = NULL;
        delete temp;
        return;
    }

    // Leaf with left child
    if ((current->getRight() != NULL) && (current->getLeft() == NULL))
    {
        deleteSub(current->getRight());
        temp = current;
        current = NULL;
        delete temp;
        return;
    }

    // Leaf with right child
    if ((current->getRight() == NULL) && (current->getLeft() != NULL))
    {
        deleteSub(current->getLeft());
        temp = current;
        current = NULL;
        delete temp;
        return;
    }

    // Leaf with two children
    if ((current->getRight() != NULL) && (current->getLeft() != NULL))
    {
        deleteSub(current->getLeft());
        deleteSub(current->getRight());
        temp = current;
        current = NULL;
        delete temp;
        return;
    }
}
    
// Deletes tree
template<typename T>
void BinaryTree<T>::deleteAll()
{
    deleteSub(root);
    size = 0;
    
}
                
// Destructor
template<typename T>
BinaryTree<T>::~BinaryTree<T>()
{
    deleteAll();
}
    
#endif
