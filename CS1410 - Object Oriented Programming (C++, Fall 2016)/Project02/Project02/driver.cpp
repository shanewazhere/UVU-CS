// Copyright 2015, Utah Valley University
//Author: Roger deBry
// Date last modified: October 2015
// Driver code, Programming Project #2
// =======================================
//
// Author: Maxwell Nelson
// Assignment: Project 02
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016
// Description: driver cpp file
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.
#include "driver.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	// create a vector for storing the account objects
	vector<Book> myBooks;

	// create three Author objects
	Author p1("J.K.Rowling", "Edinburgh, Scotland");
	Author p2("Suzanne Collins", "Connecticut, USA");
	Author p3("J.R.R. Tolkien", "Bournmouth, England");

	// Create three Book objects
	Book b1(p1, "Harry Potter and the Sorcerer's Stone", 256, 24.95);
	Book b2(p2, "Mockingjay", 400, 12.99);
	Book b3(p3, "The Hobbit",  322, 14.29);

	// add the books to the vector
	myBooks.push_back(b1 );
	myBooks.push_back(b2);
	myBooks.push_back(b3);

	// call the displayBooks function to display the books
	displayBooks(myBooks);
	cout << "\n\n";

	system("PAUSE");
	return 0;
}

void displayBooks(const vector<Book>& books)
{
	const double precision = 2;
	 // students need to write the code for this function
	for (int i = 0; i < books.size(); i++)
	{
		Book temp = books.at(i);
		const Author author = temp.getAuthor();

		const string title = temp.getTitle();
		const string name = author.getName();
		const string address = author.getAddress();
		const string pages = to_string(temp.getPages());
		const double price = temp.getPrice();

		cout << endl;
		cout << title << endl;
		cout << name << endl;
		cout << address << endl;
		cout << pages << " Pages" << endl;
		cout << "$" << setprecision(precision) << fixed << price << endl;
	}
}