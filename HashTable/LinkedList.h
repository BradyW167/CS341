// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

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
		LinkedList(const LinkedList* & list);

		// Destructor
		virtual ~LinkedList();

		// Returns true if list is empty, false if not
		bool isEmpty() const;

		// Returns the length of the list
		int getLength();

		// Insert hash entry data into a node at tail
		void insert(HashEntry data);

    // Remove node with data from input hash entry
    virtual void remove(HashEntry data);

		// Return pointer to head node
		inline LinkedNode* getHead() {return head_;}

    // Set head of list to input linked node
    inline void setHead(LinkedNode* head) {head_ = head;}

		// Return pointer to tail node
		LinkedNode* getTail() {return tail_;}
		
    // Set tail of list to input linked node
    inline void setTail(LinkedNode* tail) {tail_ = tail;}

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
