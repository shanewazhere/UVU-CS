//Recursive List - 01/24/2017
//Max Nelson
//Section 002
//List.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

#include "List.h"

// postcondition: list is initialized
list_2::List::List()
{
	//creates an empty List object
	head = nullptr;
	listSize = 0;
}

// postcondition: all nodes are destroyed using recursion
list_2::List::~List()
{
	destroy(head);
}

// helper function for the destructor
//paramaters: Node* temp
void list_2::List::destroy(Node *n)
{
	if (n != nullptr)
	{
		destroy(n->next);
		delete n;
	}
	else {
		return;
	}
}

// postcondition: print the list ussing recursion
//paramaters: none
void list_2::List::print()
{
	if (head == nullptr)
	{
		std::cout << std::endl << "no nodes" << std::endl;
	}
	else
	{
		std::cout << std::endl << head->data << std::endl;
		printHelper(head);
	}
}

//helper function for print
//paramaters: Node* temp
void list_2::List::printHelper(Node* temp)
{
	if (temp->next == nullptr)
	{
		std::cout << std::endl << "end of list" << std::endl;
	}
	else {
		std::cout << temp->next->data << std::endl;
		printHelper(temp->next);
	}
}

// precondition: list is in sorted order
//                 (don't use addEnd with this function)
// postcondition: d is inserted into the list so the list maintains
//                sorted order. using recursison.
//paramaters: int d
void list_2::List::insert(int d)
{
	if (head == nullptr)
	{
		head = new Node(d);
		return;
	}
	else if (head->data == d)
	{
		//duplicate
		return;
	}
	else if (d < head->data)
	{
		Node* newNode = new Node(d);
		newNode->next = head;
		head = newNode;
	}
	else {
		insertHelper(d, head);
	}
}

//helper function for insert
//paramaters: int d, Node* temp
void list_2::List::insertHelper(int d, Node* temp)
{
	if (temp->next == nullptr)
	{
		temp->next = new Node(d);
		return;
	}
	else if (temp->next->data == d)
	{
		return;
	}
	else if (d < temp->next->data)
	{
		Node* newNode = new Node(d);
		newNode->next = temp->next;
		temp->next = newNode;
		return;
	}
	else {
		insertHelper(d, temp->next);
	}
}


// postcondition: add element d at the end of the list
//                using recursion
//paramaters: int d
void list_2::List::addEnd(int d)
{
	if (head == nullptr) {
		//none 
		head = new Node(d);
	}
	//need this?
	else if (head->next == nullptr){
		//one
		head->next = new Node(d);
	}
	else {
		addEndHelper(d, head);
		//any size 
		//call recursive function
	}
}

//helper function for addEnd
//paramaters: int d, Node* temp
void list_2::List::addEndHelper(int d, Node* temp)
{
	if (temp->next == nullptr) {
		//one
		temp->next = new Node(d);
		return;
	}
	else {
		addEndHelper(d, temp->next);
		//any size 
	}
}


// postcondition: if d is in the list then find returns true
//                else find returns false
//paramaters: int d
bool list_2::List::find(int d)
{
	if (head == nullptr)
	{
		return false;
	}
	else if (head->next->data == d)
	{
		//d found return true
		return true;
	}
	else {
		//next node isn't null continue 
		return findHelper(d, head);
	}
}

//helper function for find
//paramaters: int d, Node* temp
bool list_2::List::findHelper(int d, Node* temp)
{
	if (temp == nullptr)
	{
		return false;
	}
	else if (temp->data == d)
	{
		//d found return true
		return true;
	}
	else {
		//next node isn't null continue 
		return findHelper(d, temp->next);
	}
}

// postcondition: size is returned. Must be calculated using recursion.
//paramaters: none
int list_2::List::size() 
{
	//returns list size/number of nodes in list
	if (head == nullptr)
	{
		int tempsize = listSize;
		listSize = 0;
		return tempsize;
	}
	else {
		listSize++;
		return sizeHelper(head);
	}

}

//helper function for size
//paramaters: Node* temp
int list_2::List::sizeHelper(Node* temp) //801-361-8356
{
	//returns list size/number of nodes in list
	if (temp->next == nullptr)
	{
		int tempsize = listSize;
		listSize = 0;
		return tempsize;
	}
	else {
		listSize++;
		return sizeHelper(temp->next);
	}
}


