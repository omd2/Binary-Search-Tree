//
//  int.h
//  BST
//

#ifndef BST_int_h
#define BST_int_h

#include <iostream>
#include <new>

using namespace std;

struct INT {
    
    int *data;

    INT();
    INT(int);
    INT(INT&);
    
    ~INT();
    
    bool operator == (const INT&);
    bool operator < (const INT&);
    bool operator > (const INT&);
    INT& operator = (const INT&);
    
    void print();
    
};

// ostream operator
ostream& operator << (ostream &out, INT &i)
{
    out << *(i.data);
    return out;
}

// default constructor
INT::INT()
{
    data = NULL;
}

// constructor with parameters
INT::INT(int c)
{
    data = new int;
    *data = c;
}

// copy constructor
INT::INT(INT& i)
{
    *this = i;
}


// Returns true if equal
bool INT::operator == (const INT& c)
{
    if (*(c.data) == *(data))
        return true;
    else
        return false;
}


// Returns true if greater than
bool INT::operator > (const INT& c)
{
    if (*(c.data) > *(data))
        return true;
    else
        return false;
}

// Returns true if less than
bool INT::operator < (const INT& c)
{
    if (*(c.data) < *(data))
        return true;
    else
        return false;
}

// Prints
void INT::print()
{
    cout << *data;
}

// Assignment operator
INT& INT::operator = (const INT& c)
{
    if (data != NULL)
        delete data;
    
    data = new int;
    *data = (*(c.data));
    
    return *this;
}

// Destructor
INT::~INT()
{
    delete data;
}

#endif
