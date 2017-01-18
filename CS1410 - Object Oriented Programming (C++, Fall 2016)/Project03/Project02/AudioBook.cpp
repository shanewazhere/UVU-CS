// Author: Maxwell Nelson
// Assignment: Project 05
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 10/23/2016
// Description: Header for AudioBook class
//
//I declare that the followqng source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 

#include "AudioBook.h"
#include <iostream>
using namespace std;

AudioBook::AudioBook()
{
	length = 0;
};

AudioBook::AudioBook(Author* a, string t, int pg, double p, int l)
	:Book(a, t, pg, p)
{
	length = l;
}

void AudioBook::setLength(int l)
{
	length = l;
}

int AudioBook::getLength() const
{
	return length;
}

void AudioBook::readData(ifstream& file)
{

	//read length
	file >> length;
	//read parent data
	Book::readData(file);
}

void AudioBook::writeData(ofstream& file)
{

	//write length
	file << length;
	file << endl;
	//write parent data
	Book::writeData(file);
}
