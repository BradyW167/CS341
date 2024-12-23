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
		void insertLinkedNode(LinkedNode* node, int data = -1);

		// Insert new node after input node with input data
		void insertAfterLinkedNode(LinkedNode * node, int data = -1);

		// Insert new node before input node with input data
		void insertBeforeLinkedNode(LinkedNode * node, int data = -1);

		// Print the double linked list
		void printList() override;
};

#endif
