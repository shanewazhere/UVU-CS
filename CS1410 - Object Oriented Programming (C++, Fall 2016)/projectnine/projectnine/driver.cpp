// Author: Maxwell Nelson
// Assignment: Project 09
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 12/8/2016
// Description: Driver file.
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 

#include <iostream>
#include "List.h"
using namespace std;

// the printlist function
// Purpose: Prints out the contents for each Node in the List
// Parameter: A list object, by const reference
// Returns: none
void printList(const List&); 


int main( )
{
	// set up cout for displaying prices
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// create a List object
	List partsList;

	cout << "\nPart I: multiple node test: push_front and pop_front\n";
	cout << "\n----------------------------------\n";
	// build a List using push_front
	partsList.push_front(new Node(new Book("Fun With C++", "I. M. Codemann", 95.00) ) );
	partsList.push_front(new Node(new Book("Lousy Linked Lists", "B. A. Hacker", 74.90) ) );
	partsList.push_front(new Node(new Book("Programming Nuts", "R. U. Krazy", 85.25) ) );
	partsList.push_front(new Node(new Book("Silly Syntax", "Irma Coder", 30.15) ) );

	cout << "\nThe original nodes in the List:\n";
	printList(partsList);
	cout << "\n----------------------------------\n";

	// test push_front function
	cout << "\nAdding to the front of the List:\n";
	cout << "\n----------------------------------\n";
	partsList.push_front(new Node(new Book("Python's a Snake", "C. Rules", 65.45) ) );
	partsList.push_front(new Node(new Book("Programming Fables", "J. Aesop", 73.15) ) );

	printList(partsList);
	cout << "\n----------------------------------\n";

	// test pop-front
	cout << "\nRemoving the first node from the list.\n";
	cout << "\n----------------------------------\n";
	Node* item = partsList.pop_front( );
	printList(partsList);
	if (item != NULL)
		delete item;
	
	cout << "\n----------------------------------\n";
	cout << "\nPart Two: Push_back and pop_back";
	
	// test push_back
	partsList.push_back(new Node(new Book("Coding Shortcuts", "B. Lazy", 110.25) ) );
	partsList.push_back(new Node(new Book("Famous Programmers I Know", "M. T. Set", 126.00) ) );

	cout << "\nAdding two nodes at the end\n";
	cout << "\n----------------------------------\n";
	printList(partsList);

	// test pop-back
	cout << "\n----------------------------------\n";
	cout << "\nRemove last node from the list\n";
	cout << "\n----------------------------------\n";
	item = partsList.pop_back( );
	printList(partsList);
	if (item != NULL)
		delete item;

// delete all of the Nodes in the list
	cout << "\nEmpty the list and delete all nodes\n";
	while (partsList.getFirst() != nullptr)
	{
		Node * t = partsList.pop_front();
		delete t;
	}
	printList(partsList);

	// Test Push_front and pop_back - do they handle special case
	cout << "\nTesting special case handling for push_front and pop_back\n";
	partsList.push_front(new Node(new Book("Test Book 1", "nobody", 1.25)));
	Node* t = partsList.pop_back();
	cout << "\nThe Node just removed contains " << t->getBook()->getTitle() << endl;
	delete t;

	// Test push_back and pop_front - do they handle special cases
	cout << "\nTesting special case handling for push_back and pop_front\n";
	partsList.push_back(new Node(new Book("Test Book 2", "nobody", 1.25)));
	t = partsList.pop_front();
	cout << "\nThe Node just removed contains " << t->getBook()->getTitle() << endl;
	delete t;

	// Is the list now empty
	cout << "\nThe list should now be empty...\n";
	printList(partsList);
	
	cout << "\n-------------------------------------------\n";
	cout << "\nEnd of Test";
	cout << "\n-------------------------------------------\n";
	system("PAUSE");
	return 0;
}

void printList(const List& theList)
{
	Node* firstNode = theList.getFirst();
	Book* bp;
	
	if (theList.listSize() == 0) {
		cout << endl << "Empty list" << endl;
	}
	else {
		for (int i = 0; i < theList.listSize(); i++)
		{
			bp = firstNode->getBook();
			firstNode = firstNode->getNextNode();

			cout << bp->getTitle() << ' ';
			cout << bp->getAuthor() << ' ';
			cout << "$" << bp->getPrice() << endl;
			//get the next node
		}
	}
}

void printFirstNode(List theList)
{
	Node* t= theList.getFirst( );
	Book* bp = t->getBook();
		cout << bp->getTitle() << ' ';
		cout << bp->getAuthor( ) << ' ';
		cout << "$" << bp->getPrice( ) << endl;
		t = t->getNextNode( );
}