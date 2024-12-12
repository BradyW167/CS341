// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include <iostream>
#include <string>

#include "DoubleLinkedList.h"
#include "HashEntry.h"
#include "HashTable.h"

class HashTableChaining : public HashTable {
	public:
		// Constructor with input size and probing type
    // Default to linear probing, set false for quadratic
		HashTableChaining(size_t size);

		// Destructor
		~HashTableChaining();

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

    // Return true if table is full, false if not
    inline bool isFull() {return (entryCount_ == size_);}

  private:
    DoubleLinkedList* entry_; // Stores pointer to an array of DLLs

    bool needRehash_; // True if rehash is needed, false if not

    size_t entryCount_; // Stores number of hash entries in hash table

    size_t size_; // Stores size of the hash table
};

#endif
