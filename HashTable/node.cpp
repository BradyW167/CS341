#include "Node.h"

// Default constructor
Node::Node(HashEntry data) : data_(data) {}

// Destructor
Node::~Node() {}

// Returns key of this node's entry
HashEntry Node::getEntry() {return data_;}

// Sets the hash entry key-value pair
void Node::setEntry(HashEntry data) {data_ = data;}
