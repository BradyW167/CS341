// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "HashEntry.h"

// Default Constructor
HashEntry::HashEntry() : key_(-1), value_(-1) {}

// Constructor with input key-value pair
HashEntry::HashEntry(int key, int value) : key_(key), value_(value) {}

// Destructor
HashEntry::~HashEntry() {}

// Returns the data_ value
int HashEntry::getKey() {return key_;}

// Sets the data_ value
void HashEntry::setKey(int key) {key_ = key;}

// Returns the data_ value
int HashEntry::getValue() {return value_;}

// Sets the data_ value
void HashEntry::setValue(int value) {value_ = value;}

// Overload the << operator to print hash entry data
std::ostream& operator<<(std::ostream& os, const HashEntry& entry) {
    os << "(" << entry.key_ << " : " << entry.value_ << ")";
    return os;
}

// Overload the == operator to compare hash entries
bool HashEntry::operator==(const HashEntry& entry) const {
    return (key_ == entry.key_ && value_ == entry.value_); // Compare keys and values of each entry
}
