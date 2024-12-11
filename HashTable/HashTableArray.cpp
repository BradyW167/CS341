#include "HashTableArray.h"

// Constructor
HashTableArray::HashTableArray(size_t size) : entry_(new HashEntry[size]), entryCount_(0), size_(size), isLinearProbing_(true) {}

// Destructor
HashTableArray::~HashTableArray() {
  delete[] entry_; // Delete hash entry array
}

// Inserts a new key-value pair into the hash table
void HashTableArray::insert(int key, int value) {
  size_t index = key % size_; // Get table index to insert entry at with hash function

  std::cout << "\nInserting key-value pair (" << key << ", " << value << ") at " << index << std::endl; // Print insertion

  HashEntry newEntry(key, value); // Create hash entry from input key-value pair

  isLinearProbing_ ? insertHelper(newEntry, index) : insertQuadraticHelper(newEntry, index);
}

// Insert helper function
void insertHelper(HashEntry entry, int index) {
  // If table not full and entry at index is occupied...
  if (!isFull() && entry_[index].getStatus() == HashEntry::OCCUPIED) {
    insertHelper(entry, index++);
  }
  // Else
  else {
  entryCount_++;
  entry_[index] = newEntry; // Insert new entry into entry array
  }
}

// Searches for a hash entry, based upon the key from the hash table
int HashTableArray::search(int key) {
  // Loop through indices of hash entry array
  for (int i = 0; i < size_; i++) {
    // If input key matches key of entry at index i
    if (key == entry_[i].getKey()) {
      return i; // Return index of matching key
    }
  }

  // Matching key is not found in hash entry array
  // return invalid index
  return -1;
}

// Removes a hash entry, based upon the key from the hash table
void HashTableArray::remove(int key) {
  // Tracks if entry with matching key is found
  bool isFound = false;

  // Loop through indices of hash entry array
  for (int i = 0; i < size_; i++) {
    // If input key matches key of entry at index i
    if (key == entry_[i].getKey()) {
      entry_[i].setStatus(HashEntry::REMOVED);
      isFound = true;
      break; // Break from for loop
    }
  }
  // If matching key was found...
  if (isFound) {std::cout << "Key " << key << " was removed" << std::endl;}
  // Else matching key was not found
  else {std::cout << "Invalid key, key " << key << " not found in table" << std::endl;}
}

// Prints the contents of the hash table
void HashTableArray::print() {
  int key = 0; // Stores key of a hash entry

	std::cout << "\n********************" << std::endl;

  // Loop through each index in hash table
  for(int i = 0; i < size_ - 1; i++) {
    key = entry_[i].getKey();

    std::cout << "[" << i << "]: " << ((key == -1) ? "" : std::to_string(key)) << std::endl;
  }

  std::cout << "[" << size_ - 1 << "]: " << entry_[size_ - 1].getKey(); // Print final entry

	std::cout << "\n********************" << std::endl;
}
