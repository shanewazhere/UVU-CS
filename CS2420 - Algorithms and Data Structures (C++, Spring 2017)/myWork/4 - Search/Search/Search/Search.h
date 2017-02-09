
//Search - Binary Search - 02/9/2017
//Max Nelson
//Section 002
//Search.h
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: Search.h, My header file for my Search.cpp class.

#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Search
{

public:

	//precondition: size > 0
	//postcondition: finds value and returns logical response if found
	bool sequential_find(int target);

	//precondition: none boi
	//postcondition: recursivley assists recursive_binary_find
	bool recursive_binary_help(int target, int start, int end);

	//precondition: size > 0
	//postcondition: finds value and returns logical response if found
	bool recursive_binary_find(int target);

	//precondition: size > 0
	//postcondition: finds value and returns logical response if found
	bool iterative_binary_find(int target);


	//precondition: array has not been initialized or array == nullptr
	//postcondition: inits an array with tons of data 
	void init_array();

	//precondition: array has not been initialized or array == nullptr
	//postcondition: inits an array with tons of data but sorted this time
	void init_sorted_array();

	//precondition: nada
	//postcondition: sets the random seed 
	void set_seed(int seed);

	//precondition: nope
	//postcondition returns the size of the array
	int getSize();

	// this is just for practice and debugging.
	friend ostream& operator<< (ostream& out, const Search& s)
	{
		// put the code in here.
		for (int i = 1; i < s.size + 1; i++)
		{
			cout << i << ": " << s.sArray[i] << endl;
		}
	}

	//constructor
	//params: int size, int seed
	Search(int size,int seed=0);

	//destructor
	//frees memory 
	~Search();

private:
	//yeah data
	int size;
	int* sArray;
};

