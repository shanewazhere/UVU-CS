// Author: Max Nelson
// Assignment: lab13
// Instructor: David Wagstaff
// Class: CS1410 001
// Date Written: 11/16/2016
// Description: Template introduction
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

#pragma once
template <class T>
class Pair
{
private:
	T first;
	T second;
public:
	Pair(const T& fi, const T& se);
	T getFirst();
	T getSecond();
};

// Purpose: paramatarized constructor for template class
// Parameters: two constant refered any types
// Returns: none
// Pre-conditions: none
// Post-conditions: none
template<class T>
Pair<T>::Pair(const T& fi, const T& se)
{
	first = fi;
	second = se;
}

// Purpose: returns first data memeber
// Parameters: none
// Returns: first
// Pre-conditions: none
// Post-conditions: none
template<class T>
T Pair<T>::getFirst()
{
	return first;
}

// Purpose: returns second data member
// Parameters: none
// Returns: second
// Pre-conditions: none
// Post-conditions: none
template<class T>
T Pair<T>::getSecond()
{
	return second;
}