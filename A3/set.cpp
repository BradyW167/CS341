#include "set.h"

// Default constructor for bitarray of size
Set::Set(int size) : BitArray(size) {}

// Constructor with word input
Set::Set(std::string word, int size) : BitArray(word, size){
	// Convert input string to character array and initialize bitarray
	// initialize(word.c_str(), size);
}

// Destructor
Set::~Set(){}

/* Initialize bitarray for character array word with size number charcters
void Set::initialize(const char* word, int size){
	// Loop through each character in word
	for(int i = 0; i < size; i++){
		// Get character at index i
		char c = word[i];
		// Get integer value of character (97-122, a = 97, z = 122)
		int charvalue = c;
		// Assign value to index i in data
		data_[i] = charvalue;
	}
}*/

// Returns the number of 1's in the bitarray
int Set::getCardinality() const{
	int onecount = 0;
	for(int i = 0; i < LENGTH; i++){
		if(get(i)) {onecount++;}
	}
	return onecount;
}

// Returns a reference to the bitarray data
Bitarray & Set::getData(){
	return data_;
}

// Finds the union of this set and set B
bool Set::setUnion(Set & B){
	// Check if the two sets are same length
	if(LENGTH == B.length()){
		std::cout << "Set Union (A U B):" << std::endl;
		// Create new set to store the union
		Set U(BYTES);

		// Loop through each bit
		for(int i = 0; i < LENGTH; i++){
			// Or the bits in each set together
			if(get(i) | B.get(i)){
				// Set bit at index i to 1 in set U
				U.set(i);
			}else{
				// Set bit at index i to 0 in set U
				U.set(i, 0);
			}
		}
		U.print();
		// Delete set U
		// delete U;
		// Return true for successful union
		return true;
	}
	std::cout << "Sets aren't same length, cannot find union" << std::endl;
	// Return false if sets aren't same length
	return false;
}

// Finds the intersection of this set and set B
bool Set::setIntersection(Set & B){
	return false;
}
