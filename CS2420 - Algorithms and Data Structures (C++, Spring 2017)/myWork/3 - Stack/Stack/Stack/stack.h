
//Stack - infix to postfix - 02/2/2017
//Max Nelson
//Section 002
//stack.h
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: Stack. My stack class.
#pragma once

#ifndef CUSTOM_STACK
#define CUSTOM_STACK
#include <cstdlib>
#include <cassert>

namespace custom_stack {
	template <class T>
	class stack
	{
	public:
		//constructor
		stack();
		//destructor
		~stack();

		//precondition: size() > 0
		//post condition: The return value is the top item of the stack. but the stack is unchanged
		T top() const;

		//precondition: size() > 0
		//postcondition: the top item of the stack has been removed
		void pop(); 

		//precondition: size() < CAPACITY
		//postcondition: A new copy of entry has been pushed onto the stack
		void push(const T& entry);

		//postcondition: The return value is true if the stack is empty, and false otherwise
		bool empty() const; 

		//postcondition: the return value is the total number of items in the stack
		int size() const; 

	private:
		static const int CAPACITY = 30;
		T data[CAPACITY];
		int used;
	};


	template <class T>
	stack<T>::stack()
	{
		used = 0;
	}

	template <class T>
	stack<T>::~stack()
	{

	}

	template <class T>
	void stack<T>::pop()
	{
		assert(!empty());
		--used;
	}

	template <class T>
	void stack<T>::push(const T& entry)
	{
		assert(used != 30);
		data[used] = entry;
		++used;
	}

	template <class T>
	bool stack<T>::empty() const
	{
		if (used == 0)
			return true;

		return false;
	}

	template <class T>
	int stack<T>::size() const
	{
		return used;
	}

	template <class T>
	T stack<T>::top() const
	{
		assert(!empty());
			return data[used - 1];
	}
}
#endif
