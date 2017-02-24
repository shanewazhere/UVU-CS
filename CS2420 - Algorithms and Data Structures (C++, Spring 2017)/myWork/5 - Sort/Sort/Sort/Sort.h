
//Sort - Binary Sort - 02/9/2017
//Max Nelson
//Section 002
//Sort.h
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: Sort.h, My header file for my Sort.cpp class.

#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Sort
{

public:
    //constructor
    //params: int size, int seed
    Sort(size_t size,int seed=0);
    
    //destructor
    //frees memory
    ~Sort();
    
    //precondition: none
    //postcondition: insertionsorted array
    void insertion();
    //precondition: data array with n components
    //postcondition: insertionsorted array
    void insertionSort(int data[], size_t n);
    
    //precondition: none
    //postcondition: selectionsorted array
    void selection();
    //precondition: data array with n components
    //postcondition: selectionsorts an array uses swap
    void selectionSort(int data[], size_t n);

    //precondition: none
    //postcondition: mergesorts array
    void merge();
    //precondition: data array with n components
    //postcondition: splits then merges uses mergehelp
    void mergeSort(int data[], size_t n);
    //precondition: two arrays to be sorted
    //postcondition: sorted halves
    void mergeHelp(int data[], size_t n1, size_t n2);
    
    //precondition: none
    //postcondition: quick(ly)sorts an array
    void quick();
    //precondition: data array and left and right lengths
    //postcondition: quicksorted array uses partition
    void quickSort(int data[], size_t left, size_t right);
    //precondition: data array, start, end and pivot index
    //postcondition: changed pivot index, uses swap
    void partition(int data[], size_t start, size_t end, size_t &pivot_index);
    
    //precondition: reference to n. reference to n1
    //postcondition: swaps two ints
    void swap(int &n, int &n1);


	//precondition: array has not been initialized or array == nullptr
	//postcondition: inits an array with tons of data 
	void init_array();

	//precondition: nada
	//postcondition: sets the random seed 
	void set_seed(int seed);

    //precondition: nope
    //postcondition returns the size of the array
    size_t getSize();


	// this is just for practice and debugging.
	friend ostream& operator<< (ostream& out, const Sort& s)
	{
		// put the code in here.
		for (int i = 1; i < s.size + 1; i++)
		{
			out << i << ": " << s.finalArray[i] << endl;
		}

		return out;
	}

private:
	//yeah data
	size_t size;
	int* finalArray;

};

