#include "node.h"

// Default constructor
Node::Node(int data) : data_(data) {}

// Destructor
Node::~Node() {}

// Returns the data_ value
int Node::getValue() {return data_;}

// Sets the data_ value
void Node::setValue(int data) {data_ = data;}
