#include <iostream>
#include <string>
using namespace std;
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 

// Author: Maxwell Nelson
// Assignment: lab 01
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 8/25/2016
// Description: This file contains code that asks the user for their name, then greets them to c++;

// Purpose: Asks the user for their name then greets them to c++
// Parameters: n/a
// Returns: returns 0
// Pre-conditions: n/a
// Post-conditions: n/a
int main()
{
	string name;

	cout << "Hello, my name is Hal, what is your name?" << endl;
	getline(cin, name);
	cout << "Welcome to C++ " << name << ", let the adventure begin!" << endl;
	system("PAUSE");


	return 0;
}