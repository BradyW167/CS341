#include "node.h"

// Default constructor
Node::Node(int data) : data_(data) {}

// Destructor
Node::~Node()
{

}
// Returns the data_ value
int Node::getValue()
{
	return data_;
}
