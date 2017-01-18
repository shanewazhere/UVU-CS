#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 

// Author: Maxwell Nelson
// Assignment: lab 02
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 8/31/2016
// Description: This file stores doubles in a vector then stores them in an array from the vector then prints the sum of all the doubles within the array;
// --------------------------- #include "lab02.h" 
double SumArrayElements(double arrayDoubles[]);

int main() {
	//declare a vector of doubles
	vector<double> vectorDoubles;

	const int precision = 2;
	//declare an array with 5 elements for doubles
	const int ARRAY_SIZE = 5;
	double arrayDoubles[ARRAY_SIZE];

	//Loop that promts the user to enter in a decimal value.
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << "Please enter a decimal value at index " << i << " : ";
		//creates a temporary variable and stores user input within
		double temp;
		cin >> temp;
		//push_back function adds each number to the vector
		vectorDoubles.push_back(temp);
	}

	// Loop that copies each element of the vector inside of the array
	for (int k = 0; k < ARRAY_SIZE; k++) {
		//create a temporary variable
		double temp;
		temp = vectorDoubles.at(k);
		arrayDoubles[k] = temp;
	}
	
	cout << "The sum is: " << setprecision(precision) << fixed << SumArrayElements(arrayDoubles) << endl;
	//pass array to a function that sums the elements in the array
	system("PAUSE");
	
	return 0;
}



// Function Name: SumArrayElements
// Purpose:    sums up the doubles stored in an array
// Parameters:    array of doubles
// Returns:    none 
// Pre-conditions: none  
// Post-conditions:none 

double SumArrayElements(double arrayDoubles[]) {

	const int AMT_OF_NUMS = 5;
	double sum = 0;

	for (int i = 0; i < AMT_OF_NUMS; i++){
		//Create a temp variable store the double. 
		double temp;
		temp = arrayDoubles[i];
		//add variable at index to the sum
		sum += temp;
	}

	//return the sum
	return sum;
}