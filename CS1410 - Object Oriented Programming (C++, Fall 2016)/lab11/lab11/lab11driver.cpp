// Author: Max Nelson
// Assignment: lab11
// Instructor: David Wagstaff
// Class: CS1410 001
// Date Written: 11/2/2016
// Description: creates then adds two objects. Displays the objects added and subtracted
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

//main driver file
#include "lab11driver.h"

int main()
{
	const int centSubstrStart = 3;
	const int centSubstrLength = 2;
	int dollars;
	int cents;
	string dollarsString;


	//FIRST object
	//1a. Asks the user to input some monetary value in dollars and cents. 
	cout << endl << "Please enter an amount of money. IE: \"12.34\" : ";
	cin >> dollarsString;
	//1b. divide the dollars and cents
	dollars = stoi(dollarsString);
	cents = stoi(dollarsString.substr(centSubstrStart, centSubstrLength));
	cout << cents;
	//2. create the first money object
	Money firstAmount(dollars, cents);
	//FIRST object


	
	//SECOND object
	//3a.Asks the user to input a second monetary value in dollars and cents. 
	cout << "Please enter an amount of money. IE: \"56.78\" : ";
	cin >> dollarsString;

	//3b. divide the dollars and cents
	
	dollars = stoi(dollarsString);
	cents = stoi(dollarsString.substr(3, 2));
	cout << cents;
	//4. create the second money object
	Money secondAmount(dollars, cents);
	//SECOND object

	Money subtractedAmount = secondAmount - firstAmount;

	Money addedAmount = secondAmount + firstAmount;
	cout << endl << "Add " << addedAmount << endl;
	//5.Adds the two Money objects togther and outputs the result using the overloaded stream insertion operator.

	
	cout << endl << "Subtract " << subtractedAmount << endl << endl;
	//6.Subtracts the first Money object from the second and outputs the result using the overloaded stream insertion operator.

	system("PAUSE");
	//7.Keep the console window open so that the user can see the results.
	return 0;
}

ostream& operator<<(ostream& out, const Money& moneyObj)
{
	const int dime = 10;
	string seperator = ".";
	if (moneyObj.getCents() < dime)
		 seperator = ".0";

	out << "Amount: $" << moneyObj.getDollars() << seperator << moneyObj.getCents();
	return out;
}

