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
		DoubleLinkedList(const DoubleLinkedList * list);

		// Destructor
		~DoubleLinkedList();

		// Insert input node with input data
		void insertLinkedNode(LinkedNode* node, int data);

    // Insert 
    void insertAfterLinkedNode(LinkedNode * node, int data)

    void insertBeforeLinkedNode(LinkedNode * node, int data);

    virtual void printlist() override;
	private:
};

#endif
