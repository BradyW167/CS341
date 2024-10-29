// Honor Pledge:
//
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling
#include "set.h"

// Default constructor for bitarray of size
Set::Set(int size): data_(size) {}

// Constructor with word input
Set::Set(std::string text, int size) : data_(size){
	// Create char* to store string inside of with length + 1 for the null terminator
	char* arr = new char[size + 1];
	// Copy string to the character array
	strcpy(arr, text.c_str());
	// Assign values to bitarray members
	initialize(arr, size);
	// Delete temporary array after assignment is complete
	delete[] arr;
}

// Destructor
Set::~Set(){
	// std::cout << "Set Class Destructor Called" << std::endl;
}

// Initialize bit array with character array word of size number of characters
void Set::initialize(char* arr, int size){
	// Loop through each character in word
	for(int i = 0; i < size; i++){
		// Assign value to index i in data
		getData().getCharData()[i] = arr[i];
	}
}

// Returns the number of 1's in the bitarray
int Set::getCardinality() const{
	int onecount = 0;
	for(int i = 0; i < data_.length(); i++){
		if(data_.get(i)) {onecount++;}
	}
	return onecount;
}

// Returns a reference to the bitarray data
BitArray & Set::getData(){
	return data_;
}

// Finds the union of this set and set B
bool Set::setUnion(Set & B){
	int this_length = data_.length();
	// Check if the two sets are same length
	if(this_length == B.data_.length()){
		std::cout << "\nSet Union (A U B):" << std::endl;
		// Create new set to store the union
		Set U(data_.bytes());

		// Loop through each bit
		for(int i = 0; i < this_length; i++){
			// Or the bits in each set together
			if(data_.get(i) | B.data_.get(i)){
				// Set bit at index i to 1 in set U
				U.getData().set(i);
			}else{
				// Set bit at index i to 0 in set U
				U.getData().set(i, 0);
			}
		}
		U.data_.print();
		// Return true for successful union
		return true;
	}
	std::cout << "Sets aren't same length, cannot find union" << std::endl;
	// Return false if sets aren't same length
	return false;
}

// Finds the intersection of this set and set B
bool Set::setIntersection(Set & B){
	int this_length = data_.length();
	// Check if the two sets are same length
	if(this_length == B.data_.length()){
		std::cout << "\nSet Intersection (A X B):" << std::endl;
		// Create new set to store the union
		Set I(data_.bytes());

		// Loop through each bit
		for(int i = 0; i < this_length; i++){
			// And the bits in each set together
			if(data_.get(i) & B.data_.get(i)){
				// Set bit at index i to 1 in set U
				I.getData().set(i);
			}else{
				// Set bit at index i to 0 in set U
				I.getData().set(i, 0);
			}
		}
		I.data_.print();
		// Delete set I
		// delete I;
		// Return true for successful intersection
		return true;
	}
	std::cout << "Sets aren't same length, cannot find intersection" << std::endl;
	// Return false if sets aren't same length
	return false;
}
