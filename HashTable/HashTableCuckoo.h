#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H

#include <iostream>
#include <string>

#include "HashEntry.h"
#include "HashTable.h"

class HashTableCuckoo : public HashTable {
	public:
		// Constructor with input size
		HashTableCuckoo(size_t size);

		// Destructor
		~HashTableCuckoo();

		// Inserts a new key-value pair into the hash table
		void insert(int key, int value) override;

    // Insert helper function
    void insertHelper(HashEntry entry, int tableID, int probeNum)

		// Searches for a Hash Entry, based upon the key from the Hash Table
    // Returns value of matching key if found
		int search(int key) override;

		// Removes a Hash Entry, based upon the key from the Hash Table
		void remove(int key) override;

		// Prints the contents of the Hash Table
		void print() override;

    // Return true if load factor is >= 1/2 in either table, false if not
    inline bool isFull() {return (entryCount_ >= size_ / 2 || entryCount2_ >= size_ / 2);}

    // Hash function for first table with input key
    inline size_t getHash(int key) {return key % size_;}

    // Hash function for second table with input key
    inline size_t getHash2(int key) {return (key / size_) % size_;}

  private:
    HashEntry* entry_; // Stores pointer to first dynamic array of hash entries

    HashEntry* entry2_; // Stores pointer to second dynamic array of hash entries

    size_t entryCount_; // Stores number of hash entries in first hash table

    size_t entryCount2_; // Stores number of hash entries in second hash table

    size_t size_; // Stores size of the hash table
};

#endif
