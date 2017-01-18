// Author: Maxwell Nelson
// Assignment: Project 06
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 11/3/2016
// Description: Driver file. asks user for two strings and finds the substring
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 

#include <string>
#include <iostream>
using namespace std;

int index_of(const string& s, const string& t);
int findSub(const string& s, const string& t, int& index);

int main()
{
	string first;
	string second;
	cout << "This codegram will search for a string within a string. Strinception" << endl << endl;
	cout << "Enter a string to be searched: ";
	getline(cin, first);
	cout << endl  << "Now enter the string you want to search for: ";
	getline(cin, second);

	int index = index_of(first, second);
	if (index == -1)
	{
		cout << endl << "substring not found. ";
	}
	else
	{
		cout << endl << "substring found, starting at index: " << index << endl << endl;
	}
	system("PAUSE");
	return 0;
}

// Purpose:index_of. finds string within a string by calling helper function
// Parameters: two strings by reference
// Returns: none
// Pre-conditions: none
// Post-conditions: none
int index_of(const string& s, const string& t)
{
	//declare index and call the helper func boi
	int index = 0;
	return findSub(s, t, index);
}

// Purpose: helper function to recursivley find a string within a string
// Parameters: two strings by reference and an index int
// Returns: index, -1, or a recursive helper function call
// Pre-conditions: none
// Post-conditions: none
int findSub(const string& s, const string& t, int& index)
{
	const int FIRSTLENGTH = s.length();
	const int secondLength = t.length();

	if (s.substr(index, secondLength) == t)
	{
		//if found returnt the index
		return index;
	} else
	if (index == s.length() - 1)
	{
		//if it no there, then return that negative 1
		return -1;
	}
	else {
		//not found
		//and not the end of the string. recall findsub with increased index
		return findSub(s, t, index+=1);
	}
}



