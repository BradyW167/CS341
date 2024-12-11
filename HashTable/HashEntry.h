// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#ifndef HASH_ENTRY_H
#define HASH_ENTRY_H

#include <iostream>

class HashEntry
{
	public:
    // Define the Status enum and its possible values
    enum Status {EMPTY, OCCUPIED, REMOVED};

    // Default Constructor
    HashEntry();

    // Constructor with input key-value pair
		HashEntry(int key, int value);

    // Destructor
		~HashEntry();

		// Returns the key of this entry
		int getKey();

    // Sets the key of this entry
    void setKey(int data);

    // Returns the value of this entry
    int getValue();

    // Sets the value of this entry
    void setValue(int key);

    // Returns the status of this entry
    Status getStatus();

    // Sets the status of this entry
    void setStatus(Status status);

    // Overload operator<< to print hash entry data
    friend std::ostream& operator<<(std::ostream&, const HashEntry&);

    // Overload operator== to compare hash entries
    bool operator==(const HashEntry& entry) const;

	private:
		int key_; // Stores this node's key

    int value_; // Stores this node's value

    Status status_;
};

#endif
