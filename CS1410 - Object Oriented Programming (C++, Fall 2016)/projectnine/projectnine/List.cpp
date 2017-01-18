// Author: Maxwell Nelson
// Assignment: Project 09
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 12/8/2016
// Description: List class implementation file.
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#include "List.h"

List::List()
{
	//creates an empty List object
	first_node = nullptr;
	last_node = nullptr;
	num_nodes = 0;
}

//destructor
List::~List()
{
	//deletes each node if it wasn't already deleted
	Node* temp = pop_back();
	while (num_nodes != 0)
	{
		temp = pop_back();
		delete temp;
	}
}

void List::push_front(Node* n)
{
	//check if there are nodes* present
	if (num_nodes == 0)
	{
		//if not, then set the first and last node* to the node* passed in
		first_node = n;
		last_node = n;
	}
	else {
		//if there are nodes* on the list then set the next node*
		n->setNextNode(first_node);
		//then set first_node* to the new node* so its at the front of the list again
		first_node = n;
	}
	//increment nodes* count
	num_nodes++;
}

//pop_front pops node off the front then returns it
Node* List::pop_front()
{
	//save the node to be popped in a temporary variable
	Node* temp = first_node;

	//if num nodes is 1
	if (num_nodes == 1)
	{
		//if there is only one node then set both last and first node to nullptr;
		first_node = nullptr;
		last_node = nullptr;
		//decrement before we return
		num_nodes--;
		return temp;
	}
	else {
		//if there are multiple nodes on the list
		//then we set the first node to the next node on the list 
		first_node = first_node->getNextNode();
		//decrement before we return
		num_nodes--;
		return temp;
	}
}

//push_back pushes a node to the back of the list/end of list
void List::push_back(Node* n)
{
	//check if there are nodes present
	if (num_nodes == 0)
	{
		//if no nodes then set the first and last node to the node* passed in
		//since it is the only node on the list now
		first_node = n;
		last_node = n;
	}
	else {
		//if there are nodes on the list then set the next node to the node passed in
		last_node->setNextNode(n);
		//then set last_node equal to the node passed in so last_node is set to the actual last node
		last_node = n;
	}
	//increment node count
	num_nodes++;
}

//pop_back removes node on back of list then returns that node
Node* List::pop_back()
{
	//save the last_node in temp so we can return later
	Node *temp = last_node;
	//grab the current first_node so we can iterate through all nodes and find the new last_node
	Node *current = first_node;

	//check for one node
	if (num_nodes == 1)
	{
		//if there is one node on list then set the first and last node pointers to nullptr;
		first_node = nullptr;
		last_node = nullptr;
		//decrement before return
		num_nodes--;
		//return the last_node that we just popped
		return temp;
	}
	else
	{
		//if there are more nodes then find the second to last node
		while (current->getNextNode() != last_node)
		{
			current = current->getNextNode();
		}
		//set last_node to the second to last node so it is the new last_node on the list
		last_node = current;
		//decrement before return
		num_nodes--;
		//return the last_node temporary we saved before removal
		return temp;
	}
}

//return first_node
Node* List::getFirst() const
{
	//returns pointer to the first node in list
	return first_node;
}

//return last_node
Node* List::getLast() const
{
	//returns pointer to last node in list
	return last_node;
}

//return node_count
int List::listSize() const
{
	//returns list size/number of nodes in list
	return num_nodes;
}

