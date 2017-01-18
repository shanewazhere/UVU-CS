#include <iostream>
#include <limits>
#include <string>
#include <iomanip>
using namespace std;

// Author: Maxwell Nelson
// Assignment: PROJECT 01
// Instructor: DAVID WAGSTAFF
// Class: CS 1410 SECTION 01
// Date Written: August 26th 2016
// Description: main file. calculates tax return

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

// Purpose:  Main function. Calculates tax return
// Parameters: N/A
// Returns: 0
// Pre-conditions: Conditions that must exist for function to work
// Post-conditions:Conditions that exist after function has executed
// -----------------------------------------------------------------
int main()
{

	//SINGLE taxable income constants
	const double singleIncome0 = 863;
	const double singleIncome1 = 864;
	const double singleIncome2 = 2588;
	const double singleIncome3 = 2589;
	const double singleIncome4 = 4313;
	const double singleIncome5 = 4313;
	//SINGLE subtract constants
	const double singleSubtract1 = 863;
	const double singleSubtract2 = 2588;
	const double singleSubtract3 = 4313;
	//SINGLE add constants
	const double singleAdd1 = 25;
	const double singleAdd2 = 85;
	const double singleAdd3 = 181;

	//MARRIED taxable income constants
	const double marriedIncome0 = 1726;
	const double marriedIncome1 = 1727;
	const double marriedIncome2 = 5176;
	const double marriedIncome3 = 5177;
	const double marriedIncome4 = 8626;
	const double marriedIncome5 = 8626;
	//MARRIED subtract constants
	const double marriedSubtract1 = 1726;
	const double marriedSubtract2 = 5176;
	const double marriedSubtract3 = 8626;
	//MARRIED add constants
	const double marriedAdd1 = 40;
	const double marriedAdd2 = 175;
	const double marriedAdd3 = 390;

	//TAX rates
	const double taxRate0 = .022;
	const double taxRate1 = .033;
	const double taxRate2 = .062;
	const double taxRate3 = .075;

	//variables to be used for the final calculation
	double calcSubtract;
	double calcTaxrate;
	double calcAdd;
	double calculateAgain = true;

	//return types
	string jointReturn = "joint return.";
	string sepReturn = "separate return.";
	string returnType;

	//variables used for storing user input
	//income and filing status
	double income;
	string status = "n";
	//m for married.. s for single
	string m = "m";
	string s = "s";
	//promt the user for their taxable income and store it in income

	while (calculateAgain)
	{
		cout << "Please enter your taxable income: ";
		cin >> income;

		//handle bad input
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a numeric value: ";
			cin >> income;
		}

		while (status != m || status != s)
		{
			//handle input to take an m or an s
			//promt the user for their filing status and store it in status
			cout << endl << "Please enter a filing status. \"s\" for single; \"m\" for married: ";
			cin >> status;
			//handle input
			if (status == m || status == s)
			{
				break;
			}

		}
		//if status is single
		if (status == s)
		{
			returnType = sepReturn;
			if (income >= 0 && income <= singleIncome0)
			{
				calcSubtract = 0;
				calcTaxrate = taxRate0;
				calcAdd = 0;
			}
			if (income >= singleIncome1 && income <= singleIncome2)
			{
				calcSubtract = singleSubtract1;
				calcTaxrate = taxRate1;
				calcAdd = singleAdd1;
			}
			if (income >= singleIncome3 && income <= singleIncome4)
			{
				calcSubtract = singleSubtract2;
				calcTaxrate = taxRate2;
				calcAdd = singleAdd2;
			}
			if (income > singleIncome5)
			{
				calcSubtract = singleSubtract3;
				calcTaxrate = taxRate3;
				calcAdd = singleAdd3;
			}
		}
		else
		//if status is married
		if (status == m)
		{
			returnType = jointReturn;
			if (income >= 0 && income <= marriedIncome0)
			{
				calcSubtract = 0;
				calcTaxrate = taxRate0;
				calcAdd = 0;
			}
			if (income >= marriedIncome1 && income <= marriedIncome2)
			{
				calcSubtract = marriedSubtract1;
				calcTaxrate = taxRate1;
				calcAdd = marriedAdd1;
			}
			if (income >= marriedIncome3 && income <= marriedIncome4)
			{
				calcSubtract = marriedSubtract2;
				calcTaxrate = taxRate2;
				calcAdd = marriedAdd2;
			}
			if (income > marriedIncome5)
			{
				calcSubtract = marriedSubtract3;
				calcTaxrate = taxRate3;
				calcAdd = marriedAdd3;
			}
		}

		//make calculation and tell the user
		double finalCalculation = ((income - calcSubtract) * calcTaxrate) + calcAdd;
		cout << endl << "Your taxable income is $" << setprecision(2) << fixed << income << endl;
		cout << "and you are filing for a " << returnType << endl;
		cout << "Your income tax will be $" << finalCalculation << endl;

		//ask the user if they would like to compute again
		cout << endl << "Would you like to do another calculation? (y or n): ";
		char ans;
		//answers yes or no. 
		char y = 'y';
		char n = 'n';
		cin >> ans;

		//handle bad input
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter \"y\" or \"n\": ";
			cin >> income;
		}

		if (ans == y) 
		{
			//calculate again
			calculateAgain = true;
		}
		else 
		if (ans == n)
		{
			//quit the program
			calculateAgain = false;
			cout << endl << "Press any key to exit the program" << endl;
			system("PAUSE");
		}
	}

	return 0;
}