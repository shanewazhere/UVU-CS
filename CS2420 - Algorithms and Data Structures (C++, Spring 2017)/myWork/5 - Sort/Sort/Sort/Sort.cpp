


//Sort - Sorting Algorithims. Sorting Project - 02/23/2017
//Max Nelson
//Section 002
//Sort.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: Sort, My implementation code for Sort.h

#include "Sort.h"

//constructor
//params: int size, int seed
Sort::Sort(size_t size, int seed)
{
	srand(seed);
	this->size = size;
	finalArray = nullptr;
}

//destructor
//frees memory 
Sort::~Sort()
{
	if (finalArray != nullptr)
	{
		delete[] finalArray;
	}
	finalArray = nullptr;
}


///////sorts

//precondition: none
//postcondition: insertionsorted array
void Sort::insertion() {
    insertionSort(finalArray, size);
}
//precondition: data array with n components
//postcondition: insertionsorted array
void Sort::insertionSort(int data[], size_t n)
{
    
    int value;
    size_t hole;
    
    for (size_t i = 0; i < n; ++i) {
        value = data[i];
        hole = i;
        for (hole = i; hole >= 1; hole--) {
            swap(data[hole], data[hole-1]);
        }
    }
}

//precondition: none
//postcondition: selectionsorted array
void Sort::selection() {
    selectionSort(finalArray, size);
}
//precondition: data array with n components
//postcondition: selectionsorts an array uses swap
void Sort::selectionSort(int data[], size_t n){
    size_t i;
    size_t j;
    size_t index_of_largest;
    int largest;
    
    if(n != 0)
    {
        for(i = n-1; i > 0; --i)
        {
            largest = data[0];
            index_of_largest = 0;
            for (j = 1; j <= i; ++j) {
                if (data[j] > largest) {
                    largest = data[j];
                    index_of_largest = j;
                }
                
            }
            swap(data[i], data[index_of_largest]);
        }
    }
}

//precondition: none
//postcondition: mergesorts array
void Sort::merge()
{
    mergeSort(finalArray, size);
}

//precondition: data array with n components
//postcondition: splits then merges uses mergehelp
void Sort::mergeSort(int data[], size_t n)
{

    size_t n1;
    size_t n2;

    if (n > 1)
    {
        n1 = n/2;
        n2 = n - n1;

        mergeSort(data,n1);
        mergeSort((data + n1),n2);
        mergeHelp(data, n1, n2);
    }
    return;
}

//precondition: two arrays to be sorted
//postcondition: sorted halves
void Sort::mergeHelp(int data[], size_t n1, size_t n2)
{

    int *temp;
    size_t copied = 0;
    size_t copied1 = 0;
    size_t copied2 = 0;
    size_t i;
    
    //allocate memory for the temp dynamic array
    temp = new int[n1 + n2];
    
    //merge elements copying from two halves of data to the temporary array
    
    
    while (copied1 < n1 && copied2 << n2) {
        if(data[copied1] < (data+n1)[copied2])
        {
            //copy the
            //first half
            temp[copied++] = data[copied1++];
        } else {
            //and the second half
            temp[copied++] = (data + n1)[copied2++];
        }
    }
    
    //copy the rest if one side finished first
    while (copied1 < n1) {
        temp[copied++] = data[copied1++];
    }
    while (copied2 < n2)
    {
        temp[copied++] = (data + n1)[copied2++];
    }
    
    //put temp array into the final array var
    for (i = 0; i < n1+n2; ++i) {
        data[i] = temp[i];
    }
    
}

//precondition: none
//postcondition: quick(ly)sorts an array
void Sort::quick() {
    quickSort(finalArray, 2, size);
}
//precondition: data array and left and right lengths
//postcondition: quicksorted array uses partition
void Sort::quickSort(int data[], size_t left, size_t right) {
    size_t pivot_index;
    size_t n1 = left;
    size_t n2 = right - 1;
    size_t s = right - left;
    
    if (s > 1)
    {
        //parition array and set pivot index
        partition(data, n1, n2, pivot_index);
        
        n1 = pivot_index;
        n2 = n2;
        
        //recursive calls will now sort the subarrays
        quickSort(data, n1, n2);
        quickSort((data + pivot_index + 1), n1, n2);
    }
    
}

//precondition: data array, start, end and pivot index
//postcondition: changed pivot index, uses swap
void Sort::partition(int data[], size_t start, size_t end, size_t &pivot_index) {
	size_t pivot = data[end];
    size_t pIndex = start;
    
    for (size_t i = start; i < end-1; i++) {
        if(data[i] <= pivot)
        {
            swap(data[i], data[pIndex]);
            pIndex++;
        }
    }
    swap(data[pIndex], data[end]);
    pivot_index = pIndex;
}


//precondition: reference to n. reference to n1
//postcondition: swaps two ints
void Sort::swap(int &n, int &n1) {
    int temp = n;
    n = n1;
    n1 = temp;
}



//precondition: array has not been initialized or array == nullptr
//postcondition: inits an array with tons of data
void Sort::init_array()
{
    int high = getSize();
    int low = 1;
    
    finalArray = new int[high];
    
    for (int i = 0; i < high; i++) {
        if (i == 0) {
            finalArray[0] = rand() % 3;
        }
        finalArray[i] = (rand() % high - low);
    }

}



//precondition: nada
//postcondition: sets the random seed 
void Sort::set_seed(int seed)
{
	srand(seed);
}

//precondition: nope
//postcondition returns the size of the array
size_t Sort::getSize()
{
	return size;
}

