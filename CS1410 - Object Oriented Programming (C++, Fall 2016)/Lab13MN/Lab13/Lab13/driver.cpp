// Author: Max Nelson
// Assignment: lab13
// Instructor: David Wagstaff
// Class: CS1410 001
// Date Written: 11/16/2016
// Description: Template introduction driver
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

// your file prologue goes here
#include <iostream>
#include "pair.h"
using namespace std;


int main()
{
	Pair<char> letters('a', 'd');
	cout << "\nThe first letter is: " << letters.getFirst();
	cout << "\nThe second letter is: " << letters.getSecond();

	cout << endl;
	system("Pause");
	return 0;
}