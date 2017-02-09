


//Search - Binary Search - 02/9/2017
//Max Nelson
//Section 002
//Search.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: Search, My implementation code for Search.h.

#include "Search.h"

//constructor
//params: int size, int seed
Search::Search(int size, int seed)
{
	this->size = size;
	sArray = nullptr;
}

//destructor
//frees memory 
Search::~Search()
{
	if (sArray != nullptr)
	{
		delete[] sArray;
	}
	sArray = nullptr;
}

bool Search::sequential_find(int target)
{
	//linear search 
	for (int i = 0; i < getSize() - 1; i++)
	{
		if (sArray[i] == target)
		{
			return true;
		}
	}

	return false;
}

//precondition: none boi
//postcondition: recursivley assists recursive_binary_find
bool Search::recursive_binary_help(int target, int start, int end)
{
	//binary search - Recursive my dood
	int middle;

	//if there are no more elemnts to look at then return false;
	if (start > end)
	{
		return false;
	}
	//reset the middle
	middle = (start + end) / 2;
	//if the target is located at the middle of the array then return true
	if (sArray[middle] == target) {
		//target found
		return true;
	}
	//else if the target is located somewhere to the left of the array 
	else
	{
		if (target < sArray[middle])
		{
			//return middle - 1 to take place of end
			//start stays the same
			return recursive_binary_help(target, start, middle - 1);
		}
		//else if the target is located somehwere right of the array
		else if (target > sArray[middle])
		{
			//return middle + 1 to take place of start
			//end stays the same
			return recursive_binary_help(target, middle + 1, end);
		}
	}

	return false;
}

//precondition: size > 0
//postcondition: finds value and returns logical response if found
bool Search::recursive_binary_find(int target)
{
	return recursive_binary_help(target, 0, getSize());
}



//precondition: size > 0
//postcondition: finds value and returns logical response if found
bool Search::iterative_binary_find(int target)
{	//n
	//over
	//2^k = k = logbase2n
	//best case: 1 comparision

	//binary search - Iterative my dood
	int middle;

	int start;
	int end;

	start = 0;
	end = getSize();

	//while there are still elements to be searched for
	while (start < end)
	{
		//reset the middle
		middle = (start + end) / 2;
		//if the target is located at the middle of the array then treturn
		if (sArray[middle] == target) {
			//target found
			return true;
		}
		//else if the target is located somewhere to the left of the array 
		else if (target < sArray[middle])
		{
			end = middle - 1;

		}
		//else if the target is located somehwere right of the array
		else if (target > sArray[middle])
		{
			start = middle + 1;
		}
	}

	return false;
}


//precondition: array has not been initialized or array == nullptr
//postcondition: inits an array with tons of data 
void Search::init_array()
{
	int high = getSize() * 3; // for example 20 * 3 would be a limit of 60
	int low = size - (size - 1); //and 20 - 19 would be a starting point of 1 // I did this bc it says 1-60 for an example of 20

	//check if !initialized already
	if (sArray == nullptr) {

		//dynamic rrayyy
		sArray = new int[size];
		//fill tharray up
		for (int i = 0; i < getSize(); i++)
		{
			if (i == 0) {
				//first in
				sArray[0] = rand() % 5;
			}
			//random number between 60 and 1
			int randN = rand() % (high - low);
			cout << randN;
			sArray[i] = randN;
		}
	}

}


//precondition: array has not been initialized or array == nullptr
//postcondition: inits an array with tons of data but sorted this time
void Search::init_sorted_array()
{
	if (sArray == nullptr)
	{
		//mmm dynamic tho.
		sArray = new int[size];

		for (int i = 0; i < size - 1; i++)
		{
			if (i == 0)
			{
				//first in
				sArray[0] = rand() % 5;
			}
			sArray[i] = (sArray[i - 1] + rand() % 5) + 1;
		}
	}
    
}

//precondition: nada
//postcondition: sets the random seed 
void Search::set_seed(int seed)
{
	//ummmmmm unk.
	srand(seed);
}

//precondition: nope
//postcondition returns the size of the array
int Search::getSize()
{
	return sizeof(sArray);
}