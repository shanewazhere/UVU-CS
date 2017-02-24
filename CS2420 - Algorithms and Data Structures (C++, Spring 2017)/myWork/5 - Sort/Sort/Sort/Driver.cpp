//Sort - Sorting Algorithims. Sorting Project - 02/23/2017
//Max Nelson
//Section 002
//Driver.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

#include "Sort.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <array>

#define mem(object,ptrToMember)  ((object).*(ptrToMember))

typedef void(Sort::*sorting_algorithms) ();

using namespace std;

void perform_said_sorts(Sort& S, int sort_type);


int main()
{
    const int TINY = 500;
	const int BIG = 1000;
	const int MASSIVE = 1500;
 
	cout << fixed << setprecision(2) << boolalpha;
 
    //create object and set seed
	Sort tiny = Sort(TINY);
    tiny.set_seed(TINY);
    //perform all sorts on size 500 then destroy
	perform_said_sorts(tiny, TINY);
	//destroy
	tiny.~Sort();
    
    
    //create object and set seed
    Sort big = Sort(BIG);
    big.set_seed(BIG);
    //perform all sorts on size 1000 then destroy
	perform_said_sorts(big, BIG);
	//destroy
	big.~Sort();
 
    
    //create object and set seed
	Sort massive = Sort(MASSIVE);
	massive.set_seed(MASSIVE);
    //perform all sorts on size 1500 then destroy
	perform_said_sorts(massive, MASSIVE);
	massive.~Sort();
 
    
	system("PAUSE");
 }



//performs the follwing sorts
//a. quickSort
//b. mergeSort
//c. selectionSort
//d. insertionSort
void perform_said_sorts(Sort& S, int sort_type)
{

    cout << "please wait for all searches on size " << sort_type << " to complete" << endl << endl;
	//3 SORTS //SORTS[] holds pointer references to the member functions in the search class for really easy cool use.
	const string SORT_TYPES[] = { "quick sort","merge sort", "selection sort", "insertion sort"};
	const sorting_algorithms SORTS[] = { &Sort::quick, &Sort::merge, &Sort::selection, &Sort::insertion };


	//perform each sort on the given search object
	for (int i = 0; i < 4; i++)
	{
		//begin clock
		const int large_loop_length = 1;
		clock_t begin = clock();

        //new random array for each search
        S.init_array();
       
		for (int k = 0; k < large_loop_length; k++)
		{
            //this performs all searches
            mem(S, SORTS[i]) ();
        }

		//end the clock
		clock_t finish = clock();
    
		finish = finish - begin;

		double time_taken = (finish / (double)CLOCKS_PER_SEC) / large_loop_length;
		string types = SORT_TYPES[i];
		cout << types << " on random array of size " << sort_type << " took: " << time_taken << " miliseconds" << endl;
		
		//for testing
		//cout << S;
	}
	cout << endl << sort_type << " search complete." << endl << endl;
}
