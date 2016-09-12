//
//  main.cpp
//  BST
//

#include <iostream>
#include <string>
#include <fstream> 
#include <cctype> 
#include "BNode.h"
#include "BinaryTree.h"
#include "int.h"
#include "char.h"
#include <stdexcept>

using namespace std;

void load(string filename)
{
    BinaryTree<INT> integerTree;
    BinaryTree<CHAR> charTree;
    
    string inFileName = filename;
    ifstream infile;
    int integer = 0;
    char* character = nullptr;
    string string1 = "0";

    infile.open(inFileName.c_str());
    
    while (!infile)
    {
        if (!infile)
        {
            cout << "File not Found." << endl;
        }
        
        cout << "Please enter the name of the input file:";
        cin >> inFileName;
        
        infile.open(inFileName.c_str());
    }
    
    char x = infile.peek();
    if (isdigit(x))
    {
        while (infile>>integer)
        {
            INT int1(integer);
            integerTree.insert(int1);
        }
        
        integerTree.printInOrder();
    }
    else{
        while (infile>>string1)
        {
            character = new char[string1.length()];
            
            for (unsigned i = 0; i < string1.length(); i++)
            {
                strcpy(character, string1.c_str());
                character[i] = string1.at(i);
            }
            
            CHAR char1(character);
            charTree.insert(char1);
            delete []character;
        }
        
        charTree.printInOrder();
    }
    
    infile.close();
}

int main(int argc, const char * argv[]) {
    
    string inFileName;
    BinaryTree<INT> integerTree;
    BinaryTree<CHAR> charTree;
    
    cout << "Please enter the name of the input file:";
    cin >> inFileName;
    
    load(inFileName);
    
    return 0;
}
