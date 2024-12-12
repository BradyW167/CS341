// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "HashTableCuckoo.h"

// Constructor
HashTableCuckoo::HashTableCuckoo(size_t size) : entry_(new HashEntry[size]), entry2_(new HashEntry[size]), size_(size), needRehash_(false) {}

// Destructor
HashTableCuckoo::~HashTableCuckoo() {
  delete[] entry_; // Delete first hash entry array

  delete[] entry2_; // Delete second hash entry array
}

// Inserts a new key-value pair into the hash table
void HashTableCuckoo::insert(int key, int value) {
  size_t hash1 = getHash(key); // Get first hash table index to insert entry at with hash function

  size_t hash2 = getHash2(key); // Get second hash table index to insert entry at with hash function

  HashEntry newEntry(key, value); // Create hash entry from input key-value pair

  insertHelper(newEntry, 1, 0); // Insert new entry into table 1

}

// Inserts entry into tableID table and tracks the number of cuckoo swaps in probeNum
void HashTableCuckoo::insertHelper(HashEntry entry, int tableID, int probeNum) {
  HashEntry temp; // Stores hash entry temporarily when cuckoo occurs

  // If the number of attempts at inserting is more than size of the table...
  if (probeNum == size_) {
    needRehash_ = true; // Rehash is needed because of cycle

    std::cout << "\nCycle present, rehash" << std::endl; // Pring cycle is present

    std::cout << "\nKey unpositioned: " << entry.getKey() << std::endl; // Print unpositioned key

    return;
  }

  // If inserting into first table...
  if (tableID == 1) {
    int hash1 = getHash(entry.getKey()); // Store index for insertion from first hash function

    // If entry at hash1 index is empty...
    if (entry_[hash1].getStatus() == HashEntry::EMPTY) {
      // std::cout << "\nInserting t1 entry, " << entry << " at index " << hash1 << std::endl;

      entry_[hash1] = entry; // Insert input entry at hash1 index in first table
    }
    // Else entry at hash1 index is occupied
    else {
      // std::cout << "\nInserting t1 entry, " << entry << " at index " << hash1 << std::endl;

      temp = entry_[hash1]; // Store entry to be moved in temp

      entry_[hash1] = entry; // Insert input entry at hash1 index in first table

      insertHelper(temp, 2, probeNum + 1); // Insert older entry into other table
    }
  }
  // If inserting into second table...
  else if (tableID == 2) {
    int hash2 = getHash2(entry.getKey()); // Store index for insertion from first hash function

    // If entry at hash1 index is empty...
    if (entry2_[hash2].getStatus() == HashEntry::EMPTY) {
      // std::cout << "\nInserting t2 entry, " << entry << " at index " << hash2 << std::endl;

      entry2_[hash2] = entry; // Insert input entry at hash2 index in first table
    }
    // Else entry at hash2 index is occupied
    else {
      // std::cout << "\nInserting t2 entry, " << entry << " at index " << hash2 << std::endl;

      temp = entry2_[hash2]; // Store entry to be moved in temp

      entry2_[hash2] = entry; // Insert input entry at hash2 index in first table

      insertHelper(temp, 1, probeNum + 1); // Insert older entry into other table
    }
  }
}

// Searches for a hash entry, based upon the key from the hash table
int HashTableCuckoo::search(int key) {
  // Loop through indices of hash entry array
  for (int i = 0; i < size_; i++) {
    // If input key matches key of entry at index i in first table
    if (key == entry_[i].getKey()) {
      return entry_[i].getValue(); // Return value of matching key
    }
    // If input key matches key of entry at index i in second table
    else if (key == entry2_[i].getKey()) {
      return entry2_[i].getValue(); // Return value of matching key
    }
  }

  // Matching key is not found in hash entry array
  // return invalid value
  return -1;
}

// Removes a hash entry, based upon the key from the hash table
void HashTableCuckoo::remove(int key) {
  // Tracks if entry with matching key is found
  bool isFound = false;
  // Store current hash entry
  HashEntry* currEntry = nullptr;

  // Loop through indices of hash entry array
  for (int i = 0; i < size_; i++) {
    // If input key matches key of entry at index i in first table
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
    // If input key matches key of entry at index i in second table
    else if (key == entry2_[i].getKey()) {
      currEntry = &entry2_[i]; // Get pointer to entry with matching key

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
void HashTableCuckoo::print() {
  int key = 0; // Stores key of a hash entry

	std::cout << "\n***********************************" << std::endl;

  // Loop through each index in first hash table
  for(int i = 0; i < size_ - 1; i++) {
    key = entry_[i].getKey();

    std::cout << "[" << i << "]: " << ((key == -1) ? "" : std::to_string(key)) << std::endl;
  }

  key = entry_[size_ - 1].getKey(); // Get last entry's key from first table

  std::cout << "[" << size_ - 1 << "]: " << ((key == -1) ? "" : std::to_string(key)); // Print final entry

	std::cout << "\n***********************************" << std::endl;

	std::cout << "\n***********************************" << std::endl;

  // Loop through each index in second hash table
  for(int i = 0; i < size_ - 1; i++) {
    key = entry2_[i].getKey();

    std::cout << "[" << i << "]: " << ((key == -1) ? "" : std::to_string(key)) << std::endl;
  }

  key = entry2_[size_ - 1].getKey(); // Get last entry's key from second table

  std::cout << "[" << size_ - 1 << "]: " << ((key == -1) ? "" : std::to_string(key)); // Print final entry

	std::cout << "\n***********************************" << std::endl;
}
