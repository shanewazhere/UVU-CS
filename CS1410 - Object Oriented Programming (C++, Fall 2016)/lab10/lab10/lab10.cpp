// Author: Max Nelson
// Assignment: Lab10
// Instructor: David Wagstaff
// Class: CS1410
// Date Written: 10/27/2016
// Description: using recursion, the amount of a's are counted from a user entered string.
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
#include "lab10.h"

//main
int main()
{
	cout << endl << "Enter a string: ";
	getline(cin, input);

	//ask the user for a string
	//put that string in input

	countAyys();
	//assign amount of a's the return value of countAyys(string &input);

	cout << endl << "There are " << amountOfAyys << " a's in your input." << endl << endl;
	system("PAUSE");
	return 0;
	//tell the user how many a's are in their string and exit the program
}

void countAyys()
{
	//pass input by ref, no need to duplicate the data.
	char aLetter = 'a';
	//no magic letters?

	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (input.at(i) == aLetter)
		{
			amountOfAyys++;
			//increment amount of a's by 1
		}
		else {
			//no a, this else block isn't exactly necessary but wrote it just to complete the if statement
		}
	}
}