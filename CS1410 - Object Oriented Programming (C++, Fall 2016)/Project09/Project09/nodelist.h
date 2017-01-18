
// Author: Max Nelson
// Assignment: project 09
// Instructor: David Wagstaff
// Class: CS1410 001
// Date Written: 11/29/2016
// Description: header file for node and list classes
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

//Header for node and list
#pragma once

using namespace std;
#include <string>
class Node
{
	Node* nextNode;
	string itemDescription;
	string itemMeasurement;
	int numberOfItems;

public:

	// Purpose: default constructor.
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	Node();

	// Purpose: default destructor.
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: noned
	~Node();

	// Purpose: sets the item description
	// Parameters: string: description
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: noned
	void setDescription(const string d);

	// Purpose: gets the item description
	// Parameters: none
	// Returns: string: description
	// Pre-conditions: none
	// Post-conditions: noned
	string getDescription() const;

	// Purpose: sets the item measurement
	// Parameters: string: measurement
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: noned
	void setMeasurement(const string m);

	// Purpose: gets the item measurement
	// Parameters: none
	// Returns: string: measurement
	// Pre-conditions: none
	// Post-conditions: noned
	string getMeasurement() const;

	// Purpose: default destructor.
	// Parameters: int: items
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: noned
	void setNumItems(const int i);

	// Purpose: gets the number of items
	// Parameters: none
	// Returns: int: numItems
	// Pre-conditions: none
	// Post-conditions: noned
	int getNumItems() const;
};


class List {
private: 
	Node* firstNode;
	Node* lastNode;
	int numOfNodes;
public:

	// Purpose: default constructor. creates empty list.
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	List();

	// Purpose: default destructor.
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	List();

	// Purpose: push_back adds node to end of list
	// Parameters: Node*: n
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	push_back(const Node n);

	// Purpose: push_front adds node to beginning of list
	// Parameters: Node*: n
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	push_front(const Node n);

	// Purpose: pop_back removes last node on list and returns pointer
	// Parameters: none
	// Returns: Node*
	// Pre-conditions: none
	// Post-conditions: none
	Node* pop_back() const;

	// Purpose: pop_front removes first node on list and returns pointer
	// Parameters: none
	// Returns: Node*
	// Pre-conditions: none
	// Post-conditions: none
	Node* pop_front() const;

	// Purpose: get first returns a pointer to the first node in list
	// Parameters: none
	// Returns: Node*
	// Pre-conditions: none
	// Post-conditions: none
	Node* getFirst() const;


	// Purpose: get last returns a pointer to the last node in list
	// Parameters: none
	// Returns: Node*
	// Pre-conditions: none
	// Post-conditions: none
	Node* getLast() const;
};















