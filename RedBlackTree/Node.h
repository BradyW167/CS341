// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		// Default constructor
		Node(int data = -1);

		// Destructor
		~Node();

		// Returns the data_ value
		int getValue();

    // Sets the data_ value
    void setValue(int data);
	protected:
		// Stores this node's data
		int data_;
};

#endif
