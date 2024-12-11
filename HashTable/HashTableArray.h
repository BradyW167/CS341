#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include <iostream>
#include <string>

#include "HashEntry.h"
#include "HashTable.h"

class HashTableArray : public HashTable {
	public:
		// Constructor
		HashTableArray(size_t size);

		// Destructor
		~HashTableArray();

		// Inserts a new key-value pair into the hash table
		void insert(int key, int value) override;

    // Insert helper function
    void insertHelper(HashEntry entry, int index);

    // Insert helper function
    void insertQuadraticHelper(HashEntry entry, int index);

		// Searches for a Hash Entry, based upon the key from the Hash Table
		int search(int key) override;

		// Removes a Hash Entry, based upon the key from the Hash Table
		void remove(int key) override;

		// Prints the contents of the Hash Table
		void print() override;

    // Set probing type
    inline void setLinear(bool isLinearProbing) {isLinearProbing_ = isLinearProbing;}

    // Get probing type
    inline bool isLinear() {return isLinearProbing_;}

    // Return true if table is full
    inline bool isFull() {return (entryCount_ == size_);}

  private:
    HashEntry* entry_; // Stores pointer to an array of hash entries

    size_t entryCount_; // Stores number of hash entries in hash table

    size_t size_; // Stores size of the hash table

    bool isLinearProbing_; // Stores boolean true for linear probing, false for quadratic probing
};

#endif
