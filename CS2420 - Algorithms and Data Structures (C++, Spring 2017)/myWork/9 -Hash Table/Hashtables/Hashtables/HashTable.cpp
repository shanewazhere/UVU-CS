
//Hash Tables - project 9 - 04/17/2017
//Max Nelson
//Section 002
//HashTable.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: HashTable.cpp

#include "HashTable.h"
using namespace std;

//constructor
//precondition: none
//postcondition: hashtable object
HashTable::HashTable() {
    for (int i = 0; i < size; i++) {
        map[i] = nullptr;
    }
}

//destructor //clean
//precondition: table exists
//postcondition: clears it deletes it
HashTable::~HashTable() {
    if (map[0] != nullptr) {
        for (int i = 0; i < size; i++) {
            Node* entry = map[i];
            
            while (entry != nullptr) {
                Node* prev = entry;
                entry = entry->next;
                delete prev;
                prev = nullptr;
                
            }
            map[i] = nullptr;
        }
    }
}

//hash function
//precondition: asciival
//postcondition: alphabetical location/index/location to store new element
int HashTable::hashFunction(int asciival) const {
    int aAscii = 65;
    return asciival - aAscii;
}

//Insert (including a good hash function (not a simple modulus))
//precondition: element string, weight double
//postcondition: element and its weight inserted alphabetically into the hastable
void HashTable::Insert(string element, double weight) {
    
    
    int asciiVal = element[0];
    
    int index = hashFunction(asciiVal);
    
    Node* n = new Node(element, weight);
    
    Node* location = map[index];
    
    if (location == nullptr) {
        map[index] = n;
    } else {
        while (location->next != nullptr) {
            location = location->next;
        }
        
        location->next = n;
    }
    

}

//retrieve
//precondition: element string
//postcondition: retrieves said element
double HashTable::Retrieve(string element) const {
    const int NOT_ALPHA = 0;
    int key = element[0];
    int index = hashFunction(key);
    if (index < NOT_ALPHA) {
        return -1;
    }
    
    Node* location = map[index];
    while (location != nullptr) {
        if (location->element == element)
        {
            return location->weight;
        }
        location = location->next;
    }
    
    return 0;
}

//overloaded [] operator
//precondition: element string
//postcondition: retrieves said element
double HashTable::operator[](string element) const {
    return Retrieve(element);
}

