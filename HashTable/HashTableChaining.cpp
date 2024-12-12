// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "HashTableChaining.h"

// Constructor
HashTableChaining::HashTableChaining(size_t size) : entry_(new DoubleLinkedList[size]), needRehash_(false), size_(size) {}

// Destructor
HashTableChaining::~HashTableChaining() {
  delete[] entry_; // Delete hash entry array
}

// Inserts a new key-value pair into the hash table
void HashTableChaining::insert(int key, int value) {
  size_t dllIndex = key % size_; // Get table index to insert entry at with hash function

  HashEntry newEntry(key, value); // Create hash entry from input key-value pair

  // std::cout << "\nInserting entry, " << newEntry << " at index " << index << std::endl;

  entryCount_++; // Increment entry count

  // Insert linked node at tail of DLL
  // at index dllIndex in hash table
  entry_[dllIndex].insertLinkedNode(entry_[dllIndex].getTail(), newEntry);
}

// Searches for a hash entry, based upon the key from the hash table
int HashTableChaining::search(int key) {
  int foundValue = 0; // Stores value of DLL search

  // Loop through indices of hash table
  for (int i = 0; i < size_; i++) {
    foundValue = entry_[i].find(key); // Search for input key in DLL

    // If a matching key was found, return its value
    if (foundValue >= 0) {return foundValue;}
  }

  return -1; // Return -1 for no found match
}

// Removes a hash entry, based upon the key from the hash table
void HashTableChaining::remove(int key) {
  bool isFound = false; // Tracks if entry with matching key is found

  int foundValue = 0; // Stores value of DLL search

  // Loop through indices of hash table
  for (int i = 0; i < size_; i++) {
    foundValue = entry_[i].find(key); // Search for input key in DLL

    // If a matching key was found (-1 returned for no match)...
    if (foundValue >= 0) {
      // std::cout << "\nMatching key found in DLL at index " << i << std::endl;

      isFound = true; // Key has been found

      entry_[i].removeLinkedNode(key); // Remove node with matching key from DDL
    }
  }

  // If matching key was found...
  if (isFound) {std::cout << "\nKey " << key << " was removed" << std::endl;}
  // Else matching key was not found
  else {std::cout << "\nInvalid key, " << key << " not found in table" << std::endl;}
}

// Prints the contents of the hash table
void HashTableChaining::print() {
	std::cout << "\n***********************************" << std::endl;

  // Loop through each index in hash table
  for(int i = 0; i < size_ - 1; i++) {
    // Print the index its DLL from hash table
    std::cout << "[" << i << "]: " << entry_[i] << std::endl;
  }

  std::cout << "[" << size_ - 1 << "]: " << entry_[size_ - 1]; // Print final DLL

	std::cout << "\n***********************************" << std::endl;
}
