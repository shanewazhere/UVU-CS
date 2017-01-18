// Author: Max Nelson
// Assignment: Lab07
// Instructor: David Wagstaff
// Class: CS1410
// Date Written: 10/7/2016
// Description: main
// -----------
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

//main
#include <iostream>
#include "MyVector.h"
using namespace std;

void displaySize(MyVector &vec);

int main()
{
	cout << "welcome to the vector class!" << endl << endl;

	MyVector vec = MyVector(2);

	cout << "the size of your vector is " << vec.size() << endl << endl;

	cout << "the capacity of your vector is " << vec.capacity() << endl << endl;
	vec.push_back(9);
	vec.push_back(5);
	displaySize(vec);

	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(2);
	displaySize(vec);

	vec.clear();
	displaySize(vec);

	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(2);
	displaySize(vec);

	system("PAUSE");
	return 0;
}

void displaySize(MyVector &vec)
{
	cout << endl;
	for (int i = 0; i < vec.capacity(); i++)
	{
		cout << "element at index [";
		cout << i << "] is " << vec.at(i) << endl;
	}
}