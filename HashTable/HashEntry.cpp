// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "HashEntry.h"

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
