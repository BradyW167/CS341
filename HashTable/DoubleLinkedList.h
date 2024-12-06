#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include "LinkedNode.h"
#include "LinkedList.h"

class DoubleLinkedList : public LinkedList
{
	public:
		// Default constructor
		DoubleLinkedList();

		// Copy constructor
		DoubleLinkedList(const DoubleLinkedList * list);

		// Destructor
		~DoubleLinkedList();

		// Insert new node at input node with input data
		// Defaults to tail insertion
		void insertLinkedNode(LinkedNode* node, HashEntry data);

		// Insert new node after input node with input data
		void insertAfterLinkedNode(LinkedNode* node, HashEntry data);

		// Insert new node before input node with input data
		void insertBeforeLinkedNode(LinkedNode* node, HashEntry data);

    void remove(HashEntry data);

		// Print the double linked list
		virtual void printList() override;
};

#endif
