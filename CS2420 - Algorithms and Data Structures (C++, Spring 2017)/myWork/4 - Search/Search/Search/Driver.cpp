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
#define mem(object,ptrToMember)  ((object).*(ptrToMember))
//type def
typedef bool(Search::*SearchMemberFuncs) (int target);

using namespace std;

void perform_said_searches(Search& S, int testNum);

int main()
{
	const int TINY = 100;
	const int BIG = 10000;
	const int MASSIVE = 10000000;

	cout << fixed << setprecision(2) << boolalpha;

	//perform a little guy search
	Search tiny = Search(TINY);
	tiny.set_seed(TINY);
	tiny.init_array();
	//perform
	perform_said_searches(tiny, 0);
	//destroy
	tiny.~Search();

	//perform a pretty big search
	Search big = Search(BIG);
	big.set_seed(BIG);
	big.init_array();
	//perform
	perform_said_searches(big, 1);
	//destroy
	big.~Search();

	//perform a dang massive search
	Search massive = Search(MASSIVE);
	massive.set_seed(MASSIVE);
	massive.init_array();
	//perform
	perform_said_searches(massive, 2);
	//destroy
	massive.~Search();

	system("PAUSE");
}


//performs the follwing searches
//a. sequential
//b. binary using recursion
//c. binary using iteration
void perform_said_searches(Search& S, int testNum)
{
	cout << endl;
	//2 test cases
	const int TEST_CASES[] = { 1997, 2017, 997 };

	//3 searches //SEARCHES[] holds pointer references to the member functions in the search class for really easy cool use.
	const string SEARCH_SIZES[] = { "Tiny", "Big", "Massive" };
	const string SEARCH_TYPES[] = { "sequential_find", "recursive_binary_find", "iterative_binary_find" };
	const SearchMemberFuncs SEARCHES[] = { &Search::sequential_find, &Search::recursive_binary_find, &Search::iterative_binary_find };

	for (int i = 0; i < 3; i++)
	{
		string search_type = SEARCH_TYPES[i];
		//clock junk
		const int micro_secs = 1000000;
		const int large_loop_length = 100000;
		clock_t begin = clock();

		//extra long loop for timing purposes
		for (int k = 0; k < large_loop_length; k++)
		{
			//uses array of pointers to member functions. Pretty siicck.
			mem(S, SEARCHES[i]) (testNum);
		}
		//end the clock
		clock_t finish = clock();
		finish = finish - begin;
		double time_taken = (begin / (double)CLOCKS_PER_SEC) / large_loop_length * micro_secs;

		cout << SEARCH_SIZES[testNum] << " search using " << search_type << " took: " << time_taken << " micro seconds" << endl;
	}
	cout << endl;
}