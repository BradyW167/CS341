#include "HashTableArray.h"

// Constructor
HashTableArray::HashTableArray(size_t size, bool isLinearProbing) : entry_(new HashEntry[size]), entryCount_(0), size_(size), isLinearProbing_(isLinearProbing) {}

// Destructor
HashTableArray::~HashTableArray() {
  delete[] entry_; // Delete hash entry array
}

// Inserts a new key-value pair into the hash table
void HashTableArray::insert(int key, int value) {
  size_t index = key % size_; // Get table index to insert entry at with hash function

  HashEntry newEntry(key, value); // Create hash entry from input key-value pair

  // If hash table is full...
  if (isFull()) {
    std::cout << "\nHash table is full, entry (" << key << "," << value << ") not inserted" << std::endl;
    return; // Return after failed insertion
  }

  int probeNum = 0; // Stores iteration of probing for rehashing

  // If probing type is linear...
  if(isLinearProbing_) {
    // Loop 
    while (probeNum < size_) {
      int rehashIndex = (index + probeNum) % size_; // Rehash index for insertion

      // If hash entry at rehashed index is empty...
      if (entry_[rehashIndex].getStatus() == HashEntry::EMPTY) {
        // std::cout << "\nInserting entry, " << newEntry << " at index " << rehashIndex << std::endl;

        entryCount_++; // Increment entry count

        entry_[rehashIndex] = newEntry; // Insert new entry into table at rehashed index

        return; // Return after successful insertion
      }
      probeNum++; // Increment probe number
    }
  }
  // Else probing type is quadratic
  else {
    while (probeNum < size_) {
      int rehashIndex = (index + (probeNum * probeNum)) % size_; // Rehash index for insertion

      // If hash entry at rehashed index is empty...
      if (entry_[rehashIndex].getStatus() == HashEntry::EMPTY) {
        // std::cout << "\nInserting entry, " << newEntry << " at index " << rehashIndex << std::endl;

        entryCount_++; // Increment entry count

        entry_[rehashIndex] = newEntry; // Insert new entry into table at rehashed index

        return; // Return after successful insertion
      }
      probeNum++; // Increment probe number
    }
  }
}

// Searches for a hash entry, based upon the key from the hash table
int HashTableArray::search(int key) {
  // Loop through indices of hash entry array
  for (int i = 0; i < size_; i++) {
    // If input key matches key of entry at index i
    if (key == entry_[i].getKey()) {
      return entry_[i].getValue(); // Return value of matching key
    }
  }

  // Matching key is not found in hash entry array
  // return invalid value
  return -1;
}

// Removes a hash entry, based upon the key from the hash table
void HashTableArray::remove(int key) {
  // Tracks if entry with matching key is found
  bool isFound = false;
  // Store current hash entry
  HashEntry* currEntry = nullptr;

  // Loop through indices of hash entry array
  for (int i = 0; i < size_; i++) {
    // If input key matches key of entry at index i
    if (key == entry_[i].getKey()) {
      currEntry = &entry_[i]; // Get pointer to entry with matching key

      // Reset all values on matching entry to default
      // Pseudo-removes the entry
      currEntry->setStatus(HashEntry::REMOVED);
      currEntry->setKey(-1);
      currEntry->setValue(-1);

      isFound = true; // Entry was found

      break; // Break from for loop
    }
  }
  // If matching key was found...
  if (isFound) {std::cout << "\nKey " << key << " was removed" << std::endl;}

  // Else matching key was not found
  else {std::cout << "\nInvalid key, " << key << " not found in table" << std::endl;}
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

  key = entry_[size_ - 1].getKey(); // Get last entry's key

  std::cout << "[" << size_ - 1 << "]: " << ((key == -1) ? "" : std::to_string(key)); // Print final entry

	std::cout << "\n********************" << std::endl;
}
