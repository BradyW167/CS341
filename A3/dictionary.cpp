#include "dictionary.h"

// Default constructor
Dictionary::Dictionary(){}

// Copy constructor
Dictionary::Dictionary(const Dictionary & dict){

}

// Destructor
Dictionary::~Dictionary(){}

// Initialize bitarray for character array word with size number charcters
void Dictionary::initialize(char* word, int size){
	return;
}

// Return how many of the bit b are in the interval [start,end)
int Dictionary::rank_range(int start, int end, int bit){
	return 0;
}

// Returns the position of the kth bit in the interval [start,end)
int Dictionary::select_range(int start, int end, int k, int bit){
	return 0;
}

// Returns how many of bit b are in teh interval [0,end)
int Dictionary::rank(int end, int bit){
	return 0;
}

// Returns the position of the kth bit b in the interval [start,end)
int Dictionary::select(int k, int bit){
	return 0;
}

// Print the lookup table with an output stream
void Dictionary::printLookupTable(std::ostream & os){
	return;
}
