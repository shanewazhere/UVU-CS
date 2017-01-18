// Author: Maxwell Nelson
// Assignment: Project 09
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 12/8/2016
// Description: Node header file.
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#pragma once
#include "Book.h"

class Node
{
private:
	//pointer next_node
	Node* next_node;
	//pointer to book
	Book* bookObj;
public:
	// Purpose: default constructor
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	Node();

	// Purpose: paramaterized constructor
	// Parameters: Book* pointer
	// Returns: none
	// Pre-conditions: none
	Node(Book*);

	// Purpose: default destructor
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	~Node();

	// Purpose:  returns next_node pointer
	// Parameters: None
	// Returns: none
	// Pre-conditions: none
	Node* getNextNode();

	// Purpose:  returns book pointer
	// Parameters: None
	// Returns: none
	// Pre-conditions: none
	Book* getBook();

	// Purpose:  sets the next node with a pointer
	// Parameters: Node* pointer
	// Returns: none
	// Pre-conditions: none
	void setNextNode(Node* n);

	// Purpose: sets the book obj to the Node
	// Parameters: Book* pointer
	// Returns: none
	// Pre-conditions: none
	void setBook(Book* b);
};

