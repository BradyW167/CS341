#ifndef LINKED_NODE_H
#define LINKED_NODE_H

#include "Node.h"

class LinkedNode : public Node
{
	public:
		// Constructor with input data and next node
		LinkedNode(HashEntry data, LinkedNode* nextLinkedNode = nullptr, LinkedNode* prevLinkedNode = nullptr);

		// Copy constructor
		LinkedNode(const LinkedNode & node);

		// Destructor
		~LinkedNode();

		// Returns a pointer to the next linked node
		LinkedNode* getPrevLinkedNode();

		// Returns a pointer to the next linked node
		LinkedNode* getNextLinkedNode();

		// Sets the next linked node to node
		void setPrevLinkedNode(LinkedNode* node);

		// Sets the next linked node to node
		void setNextLinkedNode(LinkedNode* node);

		// Returns true if this node has a previous node
		bool hasPrevLinkedNode();

		// Returns true if this node has a next node
		bool hasNextLinkedNode();

	private:
		LinkedNode* prevLinkedNode_;
		LinkedNode* nextLinkedNode_;
};

#endif