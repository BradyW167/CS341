#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "LinkedNode.h"

class LinkedList
{
	public:
		// Default constructor
		LinkedList();

    // Copy constructor
    LinkedList(const LinkedList & list);

		// Destructor
		~LinkedList();

		// Returns true if list is empty, false if not
		bool isEmpty();

		// Returns the length of the list
		int getLength();

		// Insert data element into a node at tail
		void insert(int element = -1);

		// Delete a node
		void deleteNode(int num);

		// Prints the list out in order from head to tail
		virtual void printList();
	protected:
		// Stores pointer to the head node of the list
		LinkedNode* head_;
		// Stores pointer to the tail node of the list
		LinkedNode* tail_;
		// Stores number of nodes
		int nodecount_;
};

#endif
