
//AVL Tree - project 8 - 04/3/2017
//Max Nelson
//Section 002
//Driver.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: Driver.cpp

#include <cctype>     
#include <iostream>   
#include <cstdlib>      
#include "AVL.h"  

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

void main()
{
	AVL test; 
	char userdecision;  

	do
	{
		showmenu();
		userdecision = toupper(getcmd());
		switch (userdecision)
		{
		case 'I': test.insert(getnum());
			break;
		case 'P': test.print();
			break;
		case 'E': test.eraseAll();
			break;
		case 'O': test.inOrder();
			break;
		case 'Q':
			break;
		default:  cout << userdecision << " is an invalid decision." << endl;
		}
	} while ((userdecision != 'Q'));
}

void showmenu()
{
	//print menu
	cout << endl << "The following choices are available: " << endl;
	cout << " I   Insert using insert()" << endl;
	cout << " P   Print tree using print()" << endl;
	cout << " E   Erase the ENTIRE tree" << endl;
	cout << " O   In Order" << endl;
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
