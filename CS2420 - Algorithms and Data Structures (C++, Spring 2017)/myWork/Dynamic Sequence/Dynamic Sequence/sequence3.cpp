
//Max Nelson
//Section 002
//Disclaimer in sequence3.h file as requested in assignment doc

#include "sequence3.h"

// TYPEDEFS and MEMBER CONSTANTS
typedef double value_type;
static const int DEFAULT_CAPACITY = 5;


//   sequence(int initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The sequence has been initialized as an empty sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
main_savitch_4::sequence::sequence(int initial_capacity)
{
	used = 0;
	current_index = 0;
	capacity = initial_capacity;
	data = new value_type[capacity];
}

//   sequence(const sequence& source)
//     Postcondition: the sequence has made a deep copy of the source sequence.

main_savitch_4::sequence::sequence(const sequence& source)
{

	used = source.used;
	current_index = source.used;
	capacity = source.capacity;
	data = new value_type[capacity];

	for (int i = 0; i < used; i++)
	{
		data[i] = source.data[i];
	}

}

//  DESTRUCTOR:
//	 ~sequence()
//		Poscondition: all dynamically allocated memory has been destroyed.
main_savitch_4::sequence::~sequence()
{
	if(data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}

}


//   void resize(int new_capacity)
//     Postcondition: The sequence's current capacity is changed to the 
//     new_capacity (but not less that the number of items already on the
//     list). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
void main_savitch_4::sequence::resize(int new_capacity)
{

	value_type *larger_array;

	if (new_capacity == capacity)
		return;

	if (new_capacity < used)
		new_capacity = used;

	larger_array = new value_type[new_capacity];
	for (int i = 0; i < used; i++)
	{
		larger_array[i] = data[i];

	}
	delete[] data;
	data = larger_array;
	capacity = new_capacity;
}

//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
void main_savitch_4::sequence::start()
{	

	current_index = 0;

}

//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
void main_savitch_4::sequence::advance()
{
	if (is_item())
		current_index++;

}

//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry 
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
void main_savitch_4::sequence::insert(const value_type& entry)
{
	if (used == 0)
	{
		//empty
		data[0] = entry;

	}
	else
	{
		if (used >= capacity-1)
		{
			resize(capacity + DEFAULT_CAPACITY);
		}

		int temp_used = used + 1;

		while (temp_used > current_index)
		{
			data[temp_used] = data[temp_used - 1];
			temp_used--;
		}

		data[current_index] = entry;
	}
	used++;
}

//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
void main_savitch_4::sequence::attach(const value_type& entry)
{
	if (used == 0)
	{
		//empty
		data[0] = entry;

	}
	else
	{
		if (used >= capacity-1)
		{
			resize(capacity + DEFAULT_CAPACITY);
		}
		current_index++;

		int temp_used = used + 1;

		while (temp_used > current_index)
		{
			data[temp_used] = data[temp_used - 1];
			temp_used--;
		}

		data[current_index] = entry;
	}
	used++;
}

//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//	   else there is no current item.
void main_savitch_4::sequence::remove_current()
{
	if (is_item())
	{
		int remove_index = current_index;
		int replace_index = current_index + 1;

		for (int i = remove_index; i < capacity; i++)
		{
			data[i] = data[replace_index];
			replace_index++;
		}

		current_index++;
		//data[remove_index] = data[current_index];
		used--;
	}
}

//	OPERATOR:
//	  void operator =(const sequence& source);
//	  Postondition: a deep copy of the source sequence replaces the current sequence.
//                  Unused dynamic memory is deallocated.
void main_savitch_4::sequence::operator =(const sequence& source)
{
	used = source.used;
	current_index = source.used;
	capacity = source.capacity;
	data = new value_type[capacity];

	for (int i = 0; i < used; i++)
	{
		data[i] = source.data[i];
	}
}


//   int size( ) const
//     Postcondition: The return value is the number of items in the sequence.
int main_savitch_4::sequence::size() const
{
	return used;
}

//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
bool main_savitch_4::sequence::is_item() const
{
	if (used >= 0 && used > current_index)
	{
		return true;
	}
	else {
		return false;
	}
}


//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
value_type main_savitch_4::sequence::current() const
{
	if(is_item())
		return data[current_index];
}