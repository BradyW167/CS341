#ifndef NODE_H
#define NODE_H

#include "HashEntry.h"

class Node
{
	public:
		// Constructor with input HashEntry object
		Node(HashEntry data);

		// Destructor
		virtual ~Node();

		// Returns hash entry data
		virtual HashEntry getEntry() const;

    // Sets hash entry data
    void setEntry(HashEntry data);

	private:
		// Stores this node's data
    // a key-value pair inside a hash entry
		HashEntry data_;

  protected:
    // Prevent valueless node from being created
    // Default constructor
    Node () {}
};

#endif
