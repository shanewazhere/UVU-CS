
//AVL Tree - project 8 - 04/3/2017
//Max Nelson
//Section 002
//Node.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: Node.cpp

#include "Node.h"

Node::Node(int valIn)
{
	left = nullptr;
	right = nullptr;
	val = valIn;
	height = 1;
}


//precondition: AVL tree object exists. Node exists
//postcondition: updateHeight
void Node::updateHeight()
{
	if (left != nullptr)
	{
		if (right != nullptr && (right->height > left->height)) {
			height = right->height + 1;
		}
		else {
			height = left->height + 1;
		}
	}
	else if (right != nullptr) {
		height = right->height + 1;
	}
	else {
		height = 1;
	}
}
