// Author: Maxwell Nelson
// Assignment: Project 09
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 12/8/2016
// Description: Book implementation file.
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#include "Book.h"

Book::Book()
{
	title = "";
	author = "";
	price = 0.0;
}

Book::Book(string t, string a, double p)
{
	title = t;
	author = a;
	price = p;
}

string Book::getTitle() const
{
	return title;
}

string Book::getAuthor() const
{
	return author;
}

double Book::getPrice() const
{
	return price;
}

