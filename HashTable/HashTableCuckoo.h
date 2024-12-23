// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

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
    void insertHelper(HashEntry entry, int tableID, int probeNum);

		// Searches for a Hash Entry, based upon the key from the Hash Table
    // Returns value of matching key if found
		int search(int key) override;

		// Removes a Hash Entry, based upon the key from the Hash Table
		void remove(int key) override;

		// Prints the contents of the Hash Table
		void print() override;

    // Return true if rehash is needed, false if not
    inline bool getNeedRehash() override {return needRehash_;}

    // Hash function for first table with input key
    inline size_t getHash(int key) {return key % size_;}

    // Hash function for second table with input key
    inline size_t getHash2(int key) {return (key / size_) % size_;}


  private:
    HashEntry* entry_; // Stores pointer to first dynamic array of hash entries

    HashEntry* entry2_; // Stores pointer to second dynamic array of hash entries

    bool needRehash_; // True if rehash is needed, false if not

    size_t size_; // Stores size of the hash table

};

#endif
