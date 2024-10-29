#include "bitarray.h"

// Default constructor
BitArray::BitArray(int size): LENGTH(size * BIT_IN_BYTE), BYTES(size), data_(new char[size]) {}

// Constructor with word input
BitArray::BitArray(std::string word, int size): BitArray(size){
	// Convert input string to character array and initialize bitarray
	initialize(word.c_str(), size);
}

// Copy constructor
BitArray::BitArray(const BitArray & array){
	for(int i = 0; i < array.length(); i++){
		data_[i] = array.data_[i];
	}
}

// Destructor
BitArray::~BitArray(){
	delete[] data_;
}

// Set all bits of all characters to 0
void BitArray::clear(){
	std::cout << "Clearing bitarray" << std::endl;
	for(int i = 0; i < BYTES; i++){
		data_[i] = 0;
	}
}

// Initialize bit array with character array word of size number of characters
void BitArray::initialize(char* word, int size){
	// Loop through each character in word
	for(int i = 0; i < size; i++){
		// Get character at index i
		char c = word[i];
		// Get integer value of character (97-122, a = 97, z = 122)
		int charvalue = c;
		// Assign value to index i in data
		data_[i] = charvalue;
		/*
		// Loops through most significant bit
		for(int j = BIT_IN_BYTE - 1; j >= 0; j--){
			// Checks if bit at position i is set and assigns its' value in bits array
			data_[i * BIT_IN_BYTE + j] = (c >> j) & 1;
		}*/
	}
}

// Prints this bitarray
void BitArray::print(){
	std::cout << "|";
	for (int i = 0; i < BYTES; i++){
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	std::cout << std::endl;	
}

// Return true if bit at position is set
bool BitArray::get(int position) const{
	// Stores the index of the character containing index position
	int charindex = position / BIT_IN_BYTE;
	// Stores the index of position relative to only the byte it's in
	int bitindex = position % BIT_IN_BYTE;

	// Stores character that includes given position
	char c = data_[charindex];
	// Return true if the bit at bitindex is set
	return (c & (1 << bitindex)) ? true : false;
}

// Set a bit to bit at index position, returns true if successful
bool BitArray::set(int position, int bit){
	// Stores the index of the character containing index position
	int charindex = position / BIT_IN_BYTE;
	// Stores the index of position relative to only the byte it's in
	int bitindex = position % BIT_IN_BYTE;

	// Print set info for debugging
	std::cout << "Setting position " << bitindex << " to " << bit << std::endl;
	// Setting bit to 1
	if(bit == 1){
		// 1 OR 1 = 1
		// 0 OR 1 = 1
		data_[charindex] |= (1 << bitindex);
		return true; // Set to 1, return true
	// Setting bit to 0
	}else{
		// Character & with 1s in every position besides the bit to be set
		data_[charindex] &= (~(1 << bitindex));
		return false; // Set to 0, return false
	}
}

// Flips bit at position, returns true if successful
bool BitArray::flip(int position){
	// Return false if out of bounds
	if(position > LENGTH) {return false;}

	// Stores the index of the character containing index position
	int charindex = position / BIT_IN_BYTE;
	// Stores the index of position relative to only the byte it's in
	int bitindex = position - charindex * BIT_IN_BYTE;

	// XOR flips value of the bit
	data_[charindex] ^= (1 << bitindex);
	return true; // Successful flip
}

// Flips each value in the bitarray
void BitArray::complement(){
	std::cout << "Flipping bitarray" << std::endl;
	// Loop through every character (byte)
	for(int i = 0; i < BYTES; i++){
		// Set each byte to its complement
		data_[i] = ~data_[i];
	}
}

// Returns the character in the byte at position
char BitArray::get8(int position) const{
	// Stores the index of the character containg index position
	int charindex = position / BIT_IN_BYTE;
	// Return character at charindex
	return data_[charindex];
}

// Sets the character in given byte with index for the array
void BitArray::set8(char c, int index){

}
