// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include <iostream>
#include <string>

#include "HashEntry.h"
#include "HashTable.h"

class HashTableArray : public HashTable {
	public:
		// Constructor with input size and probing type
    // Default to linear probing, set false for quadratic
		HashTableArray(size_t size, bool isLinearProbing = true);

		// Destructor
		~HashTableArray();

		// Inserts a new key-value pair into the hash table
		void insert(int key, int value) override;

		// Searches for a Hash Entry, based upon the key from the Hash Table
    // Returns value of matching key if found
		int search(int key) override;

		// Removes a Hash Entry, based upon the key from the Hash Table
		void remove(int key) override;

		// Prints the contents of the Hash Table
		void print() override;

    // Return true if rehash is needed, false if not
    inline bool getNeedRehash() override {return needRehash_;}

    // Set probing type
    inline void setLinear(bool isLinearProbing) {isLinearProbing_ = isLinearProbing;}

    // Get probing type
    inline bool isLinear() {return isLinearProbing_;}

    // Return true if table is full, false if not
    inline bool isFull() {return (entryCount_ == size_);}

  private:
    HashEntry* entry_; // Stores pointer to an array of hash entries

    bool needRehash_; // True if rehash is needed, false if not

    size_t entryCount_; // Stores number of hash entries in hash table

    size_t size_; // Stores size of the hash table

    bool isLinearProbing_; // Stores boolean true for linear probing, false for quadratic probing
};

#endif
