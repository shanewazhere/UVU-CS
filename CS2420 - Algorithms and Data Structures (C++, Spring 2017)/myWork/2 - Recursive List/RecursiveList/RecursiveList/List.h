
//Recursive List - 01/24/2017
//Max Nelson
//Section 002
//List.h
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

#pragma once

#include <cstdlib>
#include <iostream>
#include "Node.h"

namespace list_2
{
	class List
	{
		Node *head;

		int listSize;

		// helper function for the destructor
		// add other helper functions here to complete your program.
		// they should all contain one or more Node* as parameters
		void destroy(Node *n);
		//helper function for addEnd 
		void addEndHelper(int d, Node* temp);
		//helper function for print
		void printHelper(Node* temp);
		//helper function for insert
		void insertHelper(int d, Node* temp);
		//helper function for find
		bool findHelper(int d, Node* temp);
		//helper function for size
		int sizeHelper(Node* temp);

	public:
		// postcondition: list is initialized
		List();
		// postcondition: all nodes are destroyed using recursion
		~List();

		// postcondition: add element d at the end of the list
		//                using recursion
		void addEnd(int d); 

		// postcondition: print the list ussing recursion
		void print();

		// precondition: list is in sorted order
		//                 (don't use addEnd with this function)
		// postcondition: d is inserted into the list so the list maintains
		//                sorted order. using recursison.
		void insert(int d); 

		// postcondition: if d is in the list then find returns true
		//                else find returns false
		bool find(int d);

		// postcondition: size is returned. Must be calculated using recursion.
		int size(); 

	};
}