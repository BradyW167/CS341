// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling
#include "dictionary.h"

// Default constructor
Dictionary::Dictionary(int size): data_(size), lookupTable_(new int[DICTIONARY_SIZE]){
	buildLookupTable();
}

// Constructor with word input
Dictionary::Dictionary(std::string text, int size): Dictionary(size){
	// Create char* to store string inside of with length + 1 for the null terminator
	char* arr = new char[size + 1];
	// Copy string to the character array
	strcpy(arr, text.c_str());
	// Assign values to bitarray members
	initialize(arr, text.length());
	// Delete temporary array after assignment is complete
	delete[] arr;
}

// Copy constructor
Dictionary::Dictionary(const Dictionary & dict){
	for(int i = 0; i < DICTIONARY_SIZE; i++){
		// Assign dict table values to this table
		lookupTable_[i] = dict.lookupTable_[i];
	}
}

// Destructor
Dictionary::~Dictionary(){
	// std::cout << "Dictionary Class Destructor Called" << std::endl;
	delete[] lookupTable_;
}

// Initialize bitarray for character array word with size number charcters
void Dictionary::initialize(char* arr, int size){
	// Stores the underlying bitarray data_ character array
	char* data_arr = getData().getCharData();
	// Loop through each character in word
	for(int i = 0; i < size; i++){
		// Assign value to index i in data
		data_arr[i] = arr[i];
	}
}

// Returns a reference to the bitarray data
BitArray & Dictionary::getData(){
	return data_;
}
// Return how many of the bit b are in the interval [start,end)
int Dictionary::rank_range(int start, int end, int bit){
	// Return -1 if start value invalid
	if(start < 0 || start > data_.length() - 1){ 
		std::cout << "\nRank range start value of '" << start << "' is invalid" << std::endl;
		return -1;
	}
	// Return -1 if end value invalid
	if(end <= 0 || end > data_.length()){ 
		std::cout << "\nRank range end value of '" << end << "' is invalid" << std::endl;
		return -1;
	}
	// Return -1 if bit value is not 0 or 1
	if(bit != 0 && bit != 1){ 
		std::cout << "\nRank range bit value of '" << bit << "' is invalid" << std::endl;
		return -1;
	}
	// Stores the number of bits found equal to bit
	int bitcount = 0;
	// Stores the index of the current bit
	int bitindex = start;
	// Loop until bitindex is at the start of a byte
	while(bitindex % BIT_IN_BYTE != 0){
		// Increment bitcount if bit at bitindex is b
		if(data_.get(bitindex) == bit) {bitcount++;}
		// Increment bitindex to move to next bit
		bitindex++;
		// Return bitcount if on end bit, which is excluded
		if(bitindex == end) {return bitcount;}
	}
	// Loop through each byte in dictionary bitarray
	for(int i = bitindex / BIT_IN_BYTE; i < data_.bytes(); i++){
		// Stores first bit in byte i
		bitindex = i * BIT_IN_BYTE;

		// At last byte in range if (end - current bit index) < BIT_IN_BYTE
		if(end - bitindex < BIT_IN_BYTE) {
			// Loop through indices from start to end
			for(int i = bitindex; i < end; i++){
				// Increment bitcount if bits are equal
				if(data_.get(i) == bit) {bitcount++;}
			}
			// Last byte counted, break from outer loop
			break;
		}
		// Stores character at index i in data_ array
		char c = data_.get8(bitindex);
		// Increment bitcount by the number of b bits in character c
		bitcount += bit ? lookupTable_[c] : (BIT_IN_BYTE - lookupTable_[c]);
	}
	return bitcount;
}

// Returns the position of the kth bit in the interval [start,end)
int Dictionary::select_range(int start, int end, int k, int bit){
	// Return -1 if start value invalid
	if(start < 0 || start > data_.length() - 1){ 
		std::cout << "\nSelect range start value of '" << start << "' is invalid" << std::endl;
		return -1;
	}
	// Return -1 if end value invalid
	if(end <= 0 || end > data_.length()){ 
		std::cout << "\nSelect range end value of '" << end << "' is invalid" << std::endl;
		return -1;
	}
	// Return -1 if k value invalid
	if(k <= 0 || k > data_.length()){ 
		std::cout << "\nSelect range K value of '" << k << "' is invalid" << std::endl;
		return -1;
	}
	// Return -1 if bit value is not 0 or 1
	if(bit != 0 && bit != 1){ 
		std::cout << "\nSelect range bit value of '" << bit << "' is invalid" << std::endl;
		return -1;
	}
	// Stores the number of bits found equal to bit
	int bitcount = 0;
	// Stores the index of the current bit
	int bitindex = start;
	// If first bit is not the first in a byte
	while(bitindex % BIT_IN_BYTE != 0){
		// If this is bit b
		if(data_.get(bitindex) == bit){
			// Increment bitcount if this is not the kth bit
			bitcount++;
			// Return bitindex if this is the kth bit b
			if(bitcount == k) {return bitindex;}
		}
		// Increment bitindex to move to next bit
		bitindex++;
		// Return if on end bit, which is excluded, kth bit not found
		if(bitindex == end) {return -1;}
	}
	// Loop through each byte in dictionary bitarray
	for(int i = bitindex % BIT_IN_BYTE; i < data_.bytes(); i++){
		// Stores character at index i in data_ array
		char c = data_.get8(i * BIT_IN_BYTE);
		// Increment bitcount by the number of b bits in character c
		bitcount += bit ? lookupTable_[c] : (BIT_IN_BYTE - lookupTable_[c]);
		std::cout << "At Bit " << i << " with bitcount " << bitcount << std::endl;
		// Greater or equal to k number of b bits have been found
		if(bitcount >= k){
			// Find index of the kth bit in last byte
			for(int j = BIT_IN_BYTE - 1; j >= 0; j--){
				// Store index of current bit in last byte
				int bitindex = j + i * BIT_IN_BYTE;
				// Return bitindex if this is the kth bit b
				if(bitcount == k && data_.get(bitindex) == bit){
					return bitindex;
				}else if(data_.get(bitindex) == bit){
					// If this is bit b, but not the kth bit b, decrement bitcount
					bitcount--;
				}
			}
		}
	}
	// Return -1 if kth bit b not found
	// std::cout << "\n" << k << "th bit " << bit << " not found" << std::endl;
	return -1;
}

// Returns how many of bit b are in the interval [0,end)
int Dictionary::rank(int end, int bit){
	// Return -1 if end value invalid
	if(end <= 0 || end > data_.length()){ 
		std::cout << "\nRank end value of '" << end << "' is invalid" << std::endl;
		return -1;
	}
	//Return -1 if bit value is not 0 or 1
	if(bit != 0 && bit != 1){ 
		std::cout << "\nSelect bit value of '" << bit << "' is invalid" << std::endl;
		return -1;
	}
	// Stores the number of bits found equal to bit
	int bitcount = 0;
	// Stores the index of the current bit
	int bitindex = 0;
	// Loop through each byte in dictionary bitarray
	for(int i = 0; i < data_.bytes(); i++){
		// Stores first bit in byte i
		bitindex = i * BIT_IN_BYTE;

		// At last byte in range if (end - current bit index) < BIT_IN_BYTE
		if(end - bitindex < BIT_IN_BYTE) {
			// Loop through indices from start to end
			for(int i = bitindex; i < end; i++){
				// Increment bitcount if bits are equal
				if(data_.get(i) == bit) {bitcount++;}
			}
			// Last byte counted, break from outer loop
			break;
		}
		// Stores character at index i in data_ array
		char c = data_.get8(bitindex);
		// Increment bitcount by the number of b bits in character c
		bitcount += bit ? lookupTable_[c] : (BIT_IN_BYTE - lookupTable_[c]);
	}
	return bitcount;
}

// Returns the position of the kth bit b
int Dictionary::select(int k, int bit){
	// Return -1 if k value invalid
	if(k <= 0 || k > data_.length()){ 
		std::cout << "\nSelect K value of '" << k << "' is invalid" << std::endl;
		return -1;
	}
	// Return -1 if bit value is not 0 or 1
	if(bit != 0 && bit != 1){ 
		std::cout << "\nSelect bit value of '" << bit << "' is invalid" << std::endl;
		return -1;
	}

	// Stores the number of bits found equal to bit
	int bitcount = 0;
	// Loop through each byte in dictionary bitarray
	for(int i = 0; i < data_.bytes(); i++){
		// Stores character at index i in data_ array
		char c = data_.get8(i * BIT_IN_BYTE);
		// Increment bitcount by the number of b bits in character c
		bitcount += bit ? lookupTable_[c] : (BIT_IN_BYTE - lookupTable_[c]);
		// std::cout << "At Bit " << i << " with bitcount " << bitcount << std::endl;
		// Greater or equal to k number of b bits have been found
		if(bitcount >= k){
			// Find index of the kth bit in last byte
			for(int j = BIT_IN_BYTE - 1; j >= 0; j--){
				// Store index of current bit in last byte
				int bitindex = j + i * BIT_IN_BYTE;
				// Return bitindex if this is the kth bit b
				if(bitcount == k && data_.get(bitindex) == bit){
					return bitindex;
				}else if(data_.get(bitindex) == bit){
					// If this is bit b, but not the kth bit b, decrement bitcount
					bitcount--;
				}
			}
		}
	}
	// Return -1 if kth bit b not found
	std::cout << "\n" << k << "th bit " << bit << " not found" << std::endl;
	return -1;
}

// Print the lookup table with an output stream
void Dictionary::printLookupTable(std::ostream & os){
	for(int i = 0; i < DICTIONARY_SIZE; i++){
		os << "(" << i << "," << lookupTable_[i] << ")" << std::endl;
		if(i == DICTIONARY_SIZE - 1){
			os << "(" << i << "," << lookupTable_[i] << ")";
		}
	}
}

// Constructs the lookup table array
void Dictionary::buildLookupTable(){
	for(int i = 0; i < DICTIONARY_SIZE; i++){
		// Stores the number of 1s in a character
		int onecount = 0;
		// Stores the index i as a character for bitwise operators
		char c = i;
		// Loop through the bits in a byte
		for(int j = 0; j < BIT_IN_BYTE; j++){
			// Increment onecount if bit j in char
			if(c & (1 << j)) {onecount++;}
		}
		// Assign the cardinality of char c to it's position in table
		lookupTable_[i] = onecount;
	}
}
