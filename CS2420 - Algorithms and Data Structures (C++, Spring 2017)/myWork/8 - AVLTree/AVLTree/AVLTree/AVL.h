//AVL Tree - project 8 - 04/3/2017
//Max Nelson
//Section 002
//AVL.h
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: AVL.h
#pragma once

#include "Node.h"
#include <iostream>

class AVL
{
private:
	Node* root;

public:

	//precondition: none
	//postcondition: creates AVL tree object
	AVL();

	//precondition: AVL tree object exists
	//postcondition: destructor
	~AVL();

	//precondition: AVL tree object exists
	//postcondition: inserts a new node into the AVL Tree. insert
	void insert(int val);

	//precondition: AVL tree object exists
	//postcondition: prints empty or it prints a tabbed AVL tree. print
	void print();

	//precondition: AVL tree object exists
	//postcondition: rotateLeft
	void rotateLeft(Node* node);

	//precondition: AVL tree object exists
	//postcondition: rotateRight
	void rotateRight(Node* node);

	//precondition: AVL tree object exists
	//postcondition: rebalance
	void rebalance();

	int heightAt(Node* node);

	//precondition: AVL tree object exists with nodes
	//postcondition: erase
	void eraseAll();

	//precondition: AVL tree object exists
	//postcondition: erases all of specific number
	void eraseAll(Node* node);

	//precondition: AVL tree object exists with nodes
	//postcondition: inOrder
	void inOrder();
	
	//precondition: AVL tree object exists
	//postcondition: rotateRight
	Node* unbalanced(Node* node);

	//precondition: AVL tree object exists
	//postcondition: insert a node into the list. insert
	void insert(Node*& node, int val);

	//precondition: AVL tree object exists
	//postcondition: print from a specific node with a specified depth/length
	void print(Node* node, int depth);

	//precondition: AVL tree object exists with nodes
	//postcondition: inOrder, specific node.
	void inOrder(Node* node);
};

