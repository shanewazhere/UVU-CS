
//Linked List Iterator - project 7 - 03/15/2017
//Max Nelson
//Section 002
//driver.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: driver.cpp
#include <iostream>
#include <cstdlib> 
#include <cctype>

#include "BST.h" 
using namespace std;

//precondition: no
//postcondition: PRints out a menu of things the user can do
void showmenu();
//precondition: no
//postcondition: asks user for cmd
char getcmd();
//precondition: no
//postcondition: gets num
int getnum();

int main()
{
	BST test;
	char userChoice;

	cout << "Empty Binary Search Tree Has Been Created" << endl;

	do
	{
		showmenu();
		userChoice = toupper(getcmd());
		switch (userChoice)
		{
		case 'S': cout << "Size is " << test.Size() << '.' << endl;
			break;
		case 'I': test.Insert(getnum());
			break;
		case 'A': test.preOrderTraversal();
			break;
		case 'B': test.postOrderTraversal();
			break;
		case 'C': test.inOrderTraversal();
			break;
		case 'E': test.Erase(getnum());
			break;
		case 'P': test.Print();
			break;
		case 'Q': cout << "Have a good day!" << endl;
			break;
		default:  cout << userChoice << " is invalid." << endl;
		}
	} while ((userChoice != 'Q'));

	return EXIT_SUCCESS;
}

void showmenu()
{
	cout << endl << "The following choices are available: " << endl;
	cout << " P   Print the Binary Search Tree - print()" << endl;
	cout << " S   Print the result - size()" << endl;
    cout << " E   Remove a number - erase()" << endl;
	cout << " I   Insert a new number - insert()" << endl;
	cout << " A   Prints list in pre-order traversal" << endl;
	cout << " B   Prints list in post-order traversal" << endl;
	cout << " C   Prints list in in-order traversal" << endl;
	cout << " Q   Quit this test program" << endl;
}

char getcmd()
{
	char command;
	cout << "Enter choice: ";
	cin >> command;
	return command;
}

int getnum()
{
	int result;
	cout << "Please enter an integer: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}
