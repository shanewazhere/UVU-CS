// Author: Maxwell Nelson
// Assignment: Project 05
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 10/23/2016
// Description: Header for DigitalBook class
//
//I declare that the followqng source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 

#include "DigitalBook.h"
#include "iostream"
using namespace std;


DigitalBook::DigitalBook()
{
	format = "";
};

DigitalBook::DigitalBook(Author* a, string t, int pg, double p, string f)
	:Book(a, t, pg, p)
{
	format = f;
}

void DigitalBook::setFormat(string f)
{
	format = f;
}

string DigitalBook::getFormat() const
{
	return format;
}

void DigitalBook::readData(ifstream& file)
{

	//read format
	file >> format;
	//read parent data
	Book::readData(file);
}

void DigitalBook::writeData(ofstream& file)
{
	//write format
	file << format;
	file << endl;
	//write parent data
	Book::writeData(file);
}
