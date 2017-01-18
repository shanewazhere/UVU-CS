// Author: Maxwell Nelson
// Assignment: Project 09
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 12/8/2016
// Description: List header file.
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#pragma once
#include "Node.h"
#include <vector>

class List
{
private:
	// pointer to first_node
	Node* first_node;
	// pointer to last_node
	Node* last_node;
	// amount of nodes/ list size
	int num_nodes;
public:
	// Purpose: default constructor
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	List();

	// Purpose: default destructor
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	~List();

	// Purpose: pushes node to front of list
	// Parameters: Node* node pointer
	// Returns: none
	// Pre-conditions: none
	void push_front(Node*);

	// Purpose: pops node pointer off the front of list and returns pointer to such node
	// Parameters: Node* node pointer
	// Returns: none
	// Pre-conditions: none
	Node* pop_front();

	// Purpose: pushes node to back of list
	// Parameters: None
	// Returns: none
	// Pre-conditions: none
	void push_back(Node*);

	// Purpose: pops node pointer off the back of list and returns pointer to such node
	// Parameters: None
	// Returns: none
	// Pre-conditions: none
	Node* pop_back();

	// Purpose:  returns pointer first_node
	// Parameters: None
	// Returns: none
	// Pre-conditions: none
	Node* getFirst() const;

	// Purpose:  returns pointer last_node
	// Parameters: None
	// Returns: none
	// Pre-conditions: none
	Node* getLast() const;

	// Purpose:  returns num_nodes/sizeoflist
	// Parameters: None
	// Returns: none
	// Pre-conditions: none
	int listSize() const;
};

