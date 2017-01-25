
//Recursive List - 01/24/2017
//Max Nelson
//Section 002
//Node.h
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

#pragma once

namespace list_2
{
	struct Node
	{
		int data;
		Node* next;

		//Postcondition: Node data is initialized
		Node(int d)
		{
			data = d;
			next = nullptr;
		}
	};
}