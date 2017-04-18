
//Hash Tables - project 9 - 04/17/2017
//Max Nelson
//Section 002
//HashTable.h
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: HashTable.h

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include "Node.h"
using namespace std;


class HashTable {
    private:
        static const int size = 26;
        Node* map[size];
    
    public:
    
    //constructor
    //precondition: none
    //postcondition: hashtable object
    HashTable();

    //destructor //clean
    //precondition: table exists
    //postcondition: clears it deletes it
    ~HashTable();
    
    //hash function
    //precondition: asciival
    //postcondition: alphabetical location/index/location to store new element
    int hashFunction(int asciival) const;
    
    //insert
    //precondition: element string, weight double
    //postcondition: element and its weight inserted alphabetically into the hastable
    void Insert(string element, double weight);
    
    //retrieve
    //precondition: element string
    //postcondition: retrieves said element
    double Retrieve(string element) const;

    //overloaded [] operator
    //precondition: element string
    //postcondition: retrieves said element
    double operator[](string element) const;
    
    void dump();
};
