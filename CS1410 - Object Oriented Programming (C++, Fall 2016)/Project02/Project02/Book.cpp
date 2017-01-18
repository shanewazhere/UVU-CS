// Author: Maxwell Nelson
// Assignment: Project 01
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016
// Description: Book class
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#include "Book.h"
using namespace std;

Book::Book()
{

	title = "";
	pages = 0;
	price = 0.0;
}

Book::Book(Author a, string t, int pg, double p)
{
	author = a;
	title = t;
	pages = pg;
	price = p;
}

//
void Book::setAuthor(Author newAuthor)
{
	author = newAuthor;
}

Author Book::getAuthor() const
{
	return author;
}

//
void Book::setTitle(string newTitle)
{
	title = newTitle;
}

string Book::getTitle() const
{
	return title;
}

//
void Book::setPages(int newPages)
{
	pages = newPages;
}

int Book::getPages() const
{
	return pages;
}

//
void Book::setPrice(double newPrice)
{
	price = newPrice;
}

double Book::getPrice() const
{
	return price;
}

