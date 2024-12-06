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
		virtual ~LinkedList();

		// Returns true if list is empty, false if not
		bool isEmpty();

		// Returns the length of the list
		int getLength();

		// Insert data element into a node at tail
		void insert(int element = -1);

		// Return pointer to head node
		LinkedNode* getHead() {return head_;}

		// Return pointer to tail node
		LinkedNode* getTail() {return tail_;}
		
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
