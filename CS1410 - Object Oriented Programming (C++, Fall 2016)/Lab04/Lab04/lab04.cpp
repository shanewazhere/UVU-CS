
// Author: Maxwell Nelson
// Assignment: lab 04
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/15/2016
// Description: reads data from a file then stores it in an array of doubles then averages the voltages and displays it
// ---------------------------

//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 

#include <iostream>;
#include <array>;
#include <fstream>;
using namespace std;

// Function Name: main
// Purpose: reads data from file and stores in array then gets the average voltage
// Parameters: none
// Returns: 0
// Pre-conditions: none  
// Post-conditions:none 
int main()
{
	
	int arrayIndex = 0;
	const int ARRAY_SIZE = 100;
	double voltages[ARRAY_SIZE];

	ifstream reader;

	reader.open("voltages.txt");

	double tempData;

	do
	{
		reader >> tempData;
		//test the stream state
		//if true, store the data in the array
		if (reader.good())
		{
			voltages[arrayIndex] = tempData;
			arrayIndex++;
		}
		//if the reader has failed, check if it is the end of the file
		//if it is not the end of the file, there was problem
		else if(!reader.eof())
		{
			cout << "\nThere was an issue reading the file";
			return 0;
		}
	} while (!reader.eof());

	//calculate the average voltage value and print
	double averageVolts = 0;

	for (int i = 0; i < arrayIndex; i++)
	{
		averageVolts += voltages[i];
	}

	cout << "The average voltage of the voltages stored in the file is " << averageVolts << endl;

	system("PAUSE");
	return 0;
}