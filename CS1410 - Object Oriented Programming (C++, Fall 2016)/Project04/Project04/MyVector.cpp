// Author: Max Nelson
// Assignment: project 04
// Instructor: David Wagstaff
// Class: CS1410 001
// Date Written: 10/7/2016
// Description: implementation code for vector header. vector class.
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

//class for vector object
#include "MyVector.h"
#include <cstdlib>

//1.A default constructor that creates an vector with a default capacity of 2
MyVector::MyVector()
{
	const int SIZE = 2;

	vectorSize = 0;
	vectorCapacity = SIZE;

	//double the size to get the capacity of the array. half empty cells;
	//dynamically allocate an array for the vector
	theArray = NULL;
	theArray = new int[vectorCapacity];
	//init elements to 0

	for (int i = 0; i < vectorCapacity; i++)
	{
		theArray[i] = 0;
	}
}

//2.A parameterized constructor that creates a vector of capacity n
MyVector::MyVector(int size)
{
	vectorSize = 0;
	vectorCapacity = size;
	//double the size to get the capacity of the array. half empty cells;
	//dynamically allocate an array for the vector
	theArray = NULL;
	theArray = new int[vectorCapacity];

}

//Note that you program should not have any memory leaks.
//3.A destructor that deletes any dynamically allocated storage. The destructor has the same name as the class, but begins with a ~. The destructor has no return type and takes no parameters, for example ~MyVector( )
MyVector::~MyVector()
{
	//free memory with delete 
	//then delete the object
	delete[] theArray;
	theArray = NULL;     
}

// Overloaded assignment operator
// Purpose: to do assignment from one vector to another
// Parameters: a MyVector object
// Returns: A MyVector object



MyVector& MyVector::operator=(const MyVector& assigning)
{
	// test for self assignment
	// just return it bc it's the same thing. Saves time yo.
	if (this == &assigning)
		return *this;

	//delete theArray of MyVector object getting assigned
	delete[] this->theArray;

	//gather the vectorCapacity of assigning MyVector object
	vectorCapacity = assigning.vectorCapacity;

	//dynamically allocate the new capacity, taken from assinging MyVector theArray size
	this->theArray = new int[vectorCapacity];

	//copy theArray data from the assigning MyVector Object theArray
	//and Put this old theArray data
	//in the current object getting assigned's theArray member
	for (int i = 0; i < vectorSize; i++)
	{
		this->theArray[i] = assigning.theArray[i];
	}

	//the current object being assigned has now succesfully replaced its
	//own theArray field with the assigning MyVector objects theArray data "ie: the object getting passed in"
	//return the new theArray size, son. deal with it.
	return *this;
}

//4.A function, size( ), that returns the size of your vector.
int MyVector::size() const
{
	return vectorSize;
}

//5.A function, capacity( ), that returns the capacity of the vector.
int MyVector::capacity() const
{
	return vectorCapacity;
}

//6.A function, clear( ), that deletes all of the elements from the vector and resets its size to zero and its capacity to two.
void MyVector::clear()
{
	const int DEFAULT_SIZE = 2;
	int* resetArray = NULL;
	vectorSize = 0;
	vectorCapacity = DEFAULT_SIZE;
	resetArray = new int[vectorCapacity];

	delete[] theArray;
	theArray = NULL;

	theArray = resetArray;
	//set the default values to 0


}


//7.A function push_back(int n) that adds the integer value n to the end of the vector.If the vector is not large enough to 
//hold this additional value, you must make the vector grow.Your grow algorithm should double the current capacity of the vector
//Don't forget to consider the case where the initial capacity of the vector is zero.
void MyVector::push_back(int n)
{
	if (size() != capacity())
	{
		//increment the vector size by one each time an element is pushed
		theArray[vectorSize] = n;
		vectorSize++;
		//set the value of the current index to the new num;
	} else
	if (size() == capacity())
	{
		const int MULTIPLIER = 2;
		int oldCapacity = vectorCapacity;
		//if the vector size is now the size of the capacity
		//we need to create more room for the nums
		//so dynamically allocate a new array of integers
		int capacityNewArray = vectorCapacity * MULTIPLIER;
		int* newArray = NULL;
		newArray = new int[capacityNewArray];
		vectorCapacity = capacityNewArray;
		//copy the nums of previous array to the new array

		for (int i = 0; i < size(); i++)
		{
			newArray[i] = theArray[i];
		}
		newArray[vectorSize] = n;
		vectorSize++;
		//destroy the old array
		delete [] theArray;
		theArray = NULL;
		//change the pointer to point to the new array

		theArray = newArray;
	}
}


//8.A function at(int n) that returns the value of the element at position n in the vector.If the index n is greater than the size() of the vector, this function should throw an exception.
int MyVector::at(int n) 
{
	
	if (n < size())
	{
		int rValue = theArray[n];
		return rValue;
	}
	else
	{
		throw int(n);

		//throw exception
	}
}

