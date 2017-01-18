// Author: Maxwell Nelson
// Assignment: Project 09
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 12/8/2016
// Description: Node implementation file.
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 

#include "Node.h"

Node::Node()
{
	next_node = nullptr;
	bookObj = nullptr;
}

Node::Node(Book* b)
{
	next_node = nullptr;
	bookObj = b;
}

Node::~Node()
{
	delete bookObj;
}

Node* Node::getNextNode()
{
	return next_node;
}

Book* Node::getBook()
{
	return bookObj;
}

void Node::setNextNode(Node* n)
{
	next_node = n;
}

void Node::setBook(Book* b)
{
	bookObj = b;
}
