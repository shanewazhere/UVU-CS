//Search - Binary Search - 02/9/2017
//Max Nelson
//Section 002
//Driver.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.
//class: Driver, My driver.

#include "Search.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#define mem(object,ptrToMember)  ((object).*(ptrToMember))
//type def
typedef bool(Search::*SearchMemberFuncs) (int target);

using namespace std;

void perform_said_searches(Search& S, string search_type);

int main()
{
	const int TINY = 100;
	const int BIG = 10000;
	const int MASSIVE = 1000000;

	cout << fixed << setprecision(2) << boolalpha;

	//perform a little guy search
	Search tiny = Search(TINY);
	tiny.set_seed(TINY);
	tiny.init_array();
	//perform 1 search of an array sized 100
	perform_said_searches(tiny, "one unsorted search of size \'100' in micro-seconds");
	//destroy
	tiny.~Search();

	//perform a pretty big search
	Search big = Search(BIG);
	big.set_seed(BIG);
	big.init_sorted_array();
	//perform 1 search of an array sized 10000
	perform_said_searches(big, "one sorted search of size \'10000' in micro-seconds");
	//destroy
	big.~Search();

	//perform a dang massive search
	Search massive = Search(MASSIVE);
	massive.set_seed(MASSIVE);
	massive.init_array();
	//perform 1 search of an array sized 1000000
	perform_said_searches(massive, "one unsorted search of size \'1000000' in micro-seconds");
	//destroy
	massive.~Search();

	system("PAUSE");
}




//performs the follwing searches
//a. sequential
//b. binary using recursion
//c. binary using iteration
void perform_said_searches(Search& S, string search_type)
{

	cout << endl << "Performing " << search_type << endl << "Loading pls wait.." << endl << endl;

	//3 searches //SEARCHES[] holds pointer references to the member functions in the search class for really easy cool use.
	const string SEARCH_TYPES[] = { "sequential_find", "recursive_binary_find", "iterative_binary_find" };
	const SearchMemberFuncs SEARCHES[] = { &Search::sequential_find, &Search::recursive_binary_find, &Search::iterative_binary_find };

	//perform each search on the given search object
	for (int i = 0; i < 3; i++)
	{
		string search_type = SEARCH_TYPES[i];
		//clock junk
		const int micro_secs = 1000000;
		const int large_loop_length = 10000;
		clock_t begin = clock();
		//extra long loop for timing purposes
		//perfrom like 1000000 searches on each one 
		for (int k = 0; k < large_loop_length; k++)
		{
			//uses array of pointers to member functions. see SEARCHES[] it contains calls to all three searches
			mem(S, SEARCHES[i]) (rand() % S.getSize());
			// looks for a random number - (rand % s.size) 
		}

		//end the clock
		clock_t finish = clock();
		finish = finish - begin;
		double time_taken = (finish / (double)CLOCKS_PER_SEC) / large_loop_length * micro_secs;
		cout << search_type << " took: " << time_taken << " micro seconds" << endl;
		
		//for testing
		//cout << S;
	}
	cout << search_type << " search complete." << endl << endl;
}