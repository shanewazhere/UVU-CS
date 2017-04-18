//AVL Tree - project 8 - 04/3/2017
//Max Nelson
//Section 002
//Node.h
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: Node.h

#pragma once

struct Node
{
	//Postcondition: Node data is initialized
	Node(int val);
	Node* right;
	Node* left;
	int val;
	int height;
	void updateHeight();
};