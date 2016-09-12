//
//  char.h
//  BST
//

#ifndef BST_char_h
#define BST_char_h

#include <iostream>
#include <stdexcept>
#include <string>
#include <new>

using namespace std;

struct CHAR{
    
    char * data;
    unsigned size;
    
    CHAR();
    CHAR(CHAR&);
    CHAR(char*);
    
    bool operator == (const CHAR&);
    bool operator < (const CHAR&);
    bool operator > (const CHAR&);
    CHAR& operator = (const CHAR&);
    
    void print();
    char* getData();
    
    ~CHAR();
};


// ostream operator
ostream& operator << (ostream& out, CHAR& c)
{
    c.print();
    
    return out;
}

// Default constructor
CHAR::CHAR()
{
    data = NULL;
}

// Constructor that passes in a pointer to a character
CHAR::CHAR(char* c)
{
    size = static_cast<unsigned>(strlen(c));
    data = new char[size];
    strcpy(data, c);
}

// Copy constructor
CHAR::CHAR(CHAR& c)
{
    *this = c;
}

// Returns true if equal to
bool CHAR::operator == (const CHAR& c)
{
    int decision = 0;
    
    decision = strcmp(data, c.data);
    
    if (decision == 0)
        return true;
    else
        return false;
}

// Returns true if greater than
bool CHAR::operator > (const CHAR& c)
{
    int decision = 0;
    
    decision = strcmp(data, c.data);
    
    if (decision > 0)
        return true;
    else
        return false;
}

// Returns true if less than
bool CHAR::operator < (const CHAR& c)
{
    int decision = 0;
    
    decision = strcmp(data, c.data);
    
    if (decision < 0)
        return true;
    else
        return false;
}

// Assignment operator
CHAR& CHAR::operator = (const CHAR& c)
{
    if(data != NULL)
    {
        delete []data;
    }
    
    size = static_cast<unsigned>(strlen (c.data));
    data = new char[size];
    strcpy(data, c.data);
    
    return *this;
}

// Returns data
char* CHAR::getData()
{
    return data;
}

// Prints data
void CHAR::print()
{
    unsigned i = 0;
    while(i < size)
    {
        cout << data[i];
        i++;
    }
}

// Destructor
CHAR::~CHAR()
{
    delete []data;
}

#endif