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
	private:
		// Stores this node's data
		int data_;
};

#endif
