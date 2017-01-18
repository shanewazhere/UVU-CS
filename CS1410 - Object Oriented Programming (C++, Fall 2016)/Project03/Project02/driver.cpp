// CS 1410 Programming Project #2
// Copyright 2014, Utah Valley University
//Author: Roger deBry
// Date last modified: October 2015
// Implementation file for main
// =======================================

// Author: Maxwell Nelson
// Assignment: Project 05
// Instructor: David Wagstaff
// Class: CS 1410 section 01
// Date Written: 10/24/2016
// Description: driver for project 5. I changed functions displayBooks, readTestFile.
//
//I declare that the following source code was written solely by me.
//I understand that copying any source code, in whole or in part, 
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy. 
#include "driver.h"
#include "Exception.h"

int main()
{
	// Display Menu 
	int option = 0;
	const int CREATE = 1;
	const int READ = 2;

	cout << "\nCS 1410 Project 5";
	cout << "\nSelect one of the following two options: ";
	cout << "\n   1 - create a test file";
	cout << "\n   2 - read the test file and display the results";
	cout << "\n>> ";

	// run the selected option
	cin >> option;
	if (option == CREATE)
	{
		createTestFile();
		cout << "\nTest file has been created.";
	}
	else if (option == READ)
	{
		readTestFile( );
	}
	else
	{
		cout << "\nInvalid option.";
	}

	system("PAUSE");
	return 0;
}

void displayBooks(const vector<Book*>& books)
{//reference to a pointer
	// set up cout to display currency
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	// display heading
	cout << "\nRecommended Reading List\n";


		// you provide the rest of this code

	for (unsigned i = 0; i < books.size(); i++)
	{
		
		Author p = books.at(i)->getAuthor();
		cout << books.at(i)->getTitle() << '\n';
		cout << p.getName() << '\n';
		cout << p.getAddress() << '\n';
		cout << books.at(i)->getPages() << " pages\n";

		AudioBook* audi = dynamic_cast<AudioBook*>(books.at(i));
		if (audi)
		{
			//book is audio. Display the length in minutes
			cout << "The length of this audio book is: " << audi->getLength() << " minutes\n";
		}
	
		DigitalBook* dig = dynamic_cast<DigitalBook*>(books.at(i));
		if (dig)
		{
			//book is digital. Display the format
			cout << "The format of this digital book is: "<< dig->getFormat() << "\n";
		}

		cout << '$' << books.at(i)->getPrice() << "\n\n";
	}
}



void createTestFile()
{
	// create a vector for storing the account objects
	vector<Book*> myBooks;

	// add the books to the vector
	// create eveything on the heap because we need to work with Book*
	myBooks.push_back(new AudioBook(new Author("J.K.Rowling", "Edinburgh, Scotland"), "Harry Potter and the Sorcerer's Stone", 256, 24.95, 415) );
	myBooks.push_back(new DigitalBook(new Author("Suzanne Collins", "Connecticut, USA"), "Mockingjay", 400, 12.99, "PDF") );
	myBooks.push_back(new Book(new Author("J.R.R. Tolkien", "Bournmouth, England"), "The Hobbit", 322, 14.29) );

	// write the books to a file
	// the file will be in the same folder as the executable file
	// assume that the file opens
	ofstream outputFile;
	outputFile.open("bookData.txt");

	for (unsigned i = 0; i < myBooks.size(); ++i)
	{
		// Use RTTI to get the type of object being pointed to, cast returns null if cast fails
		// see if it is an audiobook and if it is, output "AUDIOBOOK" to the file to mark the output
		AudioBook* bp = dynamic_cast<AudioBook*>(myBooks[i]);
		if (bp)
		{
			outputFile << "AUDIOBOOK" << endl;
		}
		else
		{
			// see if it is a digital book, if it is output "DIGITALBOOK" to the file
			DigitalBook* bp = dynamic_cast<DigitalBook*>(myBooks[i]);
			if (bp)
			{
				outputFile << "DIGITALBOOK" << endl;
			}
			else // It is not one of the child classes, so it must be a base class (BOOK) object
			{
				outputFile << "BOOK" << endl;
			} 
		}
		// now have the book object write itself to the file
		myBooks[i]->writeData(outputFile);
	}
}

void readTestFile()
{
	vector<Book*> myBooks;
	string type;
	Book* bookPtr = NULL;
	int count = 0;

	ifstream in("bookData.txt");
	while (in >> type)
	{
		if (type == "AUDIOBOOK")
			bookPtr = new AudioBook();
		else if (type == "DIGITALBOOK")
			bookPtr = new DigitalBook();
		else if (type == "BOOK")
			bookPtr = new Book();
		else
		{
			cout << "\n bad data in file termination iminent..";
			system("PAUSE");
		}
		//oh, values are good, read the data using polymorphism and save pointer in array
		bookPtr->readData(in);
		myBooks.push_back(bookPtr);

	}
	displayBooks(myBooks);
	system("PAUSE");

	/*
		1.Dynamically allocate an object of the required kind, either a Book object, an AudioBook object, or a DigitalBook object. 
		2.Tell the object to read its data from the file. 
		3.Push the pointer to the object into the vector. 
		4.Repeat this until you reach the end of the file.
	*/

}


void openFile(ifstream& in, const string& _name)
{
	// try to open the file
	in.open(_name);

	// if the fail but is set, teh file won't open ... throw an open error
	if (!in)
	{
		throw Exception("OPEN_ERROR");
	}
}