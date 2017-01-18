// Author: Maxwell Nelson
// Assignment: Project 05
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 9/7/2016 Date Modified: 9/26/2016 Date Modified: 10/24/2016
// Description: Book class
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#include "Book.h"
#include "Exception.h"
#include <iostream>

using namespace std;

Book::Book()
{
	title = "";
	pages = 0;
	price = 0.0;
}

Book::Book(Author* a, string t, int pg, double p)
{
	author = *a;
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

void Book::readData(ifstream& file)
{
	try
	{
		if (getline(file, title)) {
			getline(file, title);
		}

		author.readData(file); //NAME //ADDRESS

		string tempPages = "";
		getline(file, tempPages); //PAGES
		pages = stoi(tempPages);

		string tempPrice = "";
		getline(file, tempPrice); //PRICE
		price = stod(tempPrice);

		if (file.bad())
		{
			throw Exception("Error reading file");
		}
	}
	catch (Exception erf)
	{
		cout << "Error: " << erf.getMessage() << endl;
	}
}


void Book::writeData(ofstream& file)
{
	file << title;
	file << endl;
	author.writeData(file);
	file << endl;
	file << pages;
	file << endl;
	file << price;
	file << endl;
}

