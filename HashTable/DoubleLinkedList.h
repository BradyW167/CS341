#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

#include "LinkedList.h"
#include "LinkedNode.h"

class DoubleLinkedList : public LinkedList
{
	public:
		// Default constructor
		DoubleLinkedList();

		// Destructor
		~DoubleLinkedList();

		// Insert new node at input node with input data
		// Defaults to tail insertion
		void insertLinkedNode(LinkedNode* node, HashEntry data);

		// Insert new node after input node with input data
		void insertAfterLinkedNode(LinkedNode* node, HashEntry data);

		// Insert new node before input node with input data
		void insertBeforeLinkedNode(LinkedNode* node, HashEntry data);

    // Return the value of the entry stored in this node
    int find(int key);

    // Remove node with data from input hash entry
    void removeLinkedNode(HashEntry data);

		// Print the double linked list
		void printList() override;
};

#endif
