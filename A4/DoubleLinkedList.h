#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include "LinkedNode.h"

class DoubleLinkedList : public LinkedList
{
	public:
		// Default constructor
		DoubleLinkedList();

		// Copy constructor
		DoubleLinkedList();

		// Destructor
		~DoubleLinkedList();

		// Insert data element into a node at tail
		void insert(int element);
	private:
};

#endif
