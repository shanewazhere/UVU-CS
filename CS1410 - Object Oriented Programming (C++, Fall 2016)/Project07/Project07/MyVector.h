// Author: Max Nelson
// Assignment: project 04
// Instructor: David Wagstaff
// Class: CS1410 001
// Date Written: 11/10/2016
// Description: header file for vector class
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

//class header for a custom vector object
#pragma once
#include <ostream>
using namespace std;
class MyVector
{
private:
	int vectorSize;
	int vectorCapacity;
	int* theArray;

public:

	// Purpose: A default constructor that creates a vector of default capacity 2
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	MyVector();

	// Purpose: A parameterized constructor that creates a vector of capacity n
	// Parameters: size
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	MyVector(int size);

		//proj 07 additions//

	// Purpose: A destructor that deletes any dynamically allocated storage. The destructor has the same name as the class, but begins with a ~. The destructor has no return type and takes no parameters, for example ~MyVector( )
	// Note that you program should not have any memory leaks.
	// Parameters:none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	~MyVector();

	// Copy constructor
	// Purpose: Copy the data into this vector
	// Parameters: a MyVector object reference
	// Returns: none
	MyVector(const MyVector& b);

	// Overloaded assignment operator
	// Purpose: to do assignment from one vector to another
	// Parameters: a MyVector object
	// Returns: A MyVector object
	MyVector& operator= (const MyVector& );

	// Overloaded stream operator
	// Purpose: to stream data
	// Parameters: ostream, MyVector object
	// Returns: ostream, MyVector object
	friend ostream& operator<<(ostream& out, MyVector& vectorObj);

		//proj 07 additions//

	// Purpose: A function, size( ), that returns the size of your vector.
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	int size() const;

	// Purpose: A function, capacity( ), that returns the capacity of the vector.
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	int capacity() const;

	// Purpose: A function, clear( ), that deletes all of the elements from the vector and resets its size to zero and its capacity to two.
	// Parameters: clears the vector
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void clear();

	// Purpose: A function push_back(int n) that adds the integer value n to the end of the vector. If the vector is not large enough to hold this additional value, you must make the vector grow. Your grow algorithm should double the current capacity of the vector. Don't forget to consider the case where the initial capacity of the vector is zero.
	// Parameters: value to be pushed
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void push_back(int n);

	// Purpose: A function at(int n) that returns the value of the element at position n in the vector. If the index n is greater than the size( ) of the vector, this function should throw an exception.
	// Parameters: index
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	int at(int n);

};

