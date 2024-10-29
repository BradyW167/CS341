#include "LinkedNode.h"

// Default constructor
LinkedNode::LinkedNode() : Node(-1), nextLinkedNode_(nullptr) {}

// Constructor with input data and next node
LinkedNode::LinkedNode(int data, LinkedNode* nextLinkedNode) : Node(data), nextLinkedNode_(nextLinkedNode) {}

// Copy constructor
LinkedNode::LinkedNode(const LinkedNode & node)
{
	// Account for all links to every node copied
}

// Destructor
LinkedNode::~LinkedNode()
{
	if(hasNextLinkedNode())
	{
		delete nextLinkedNode_;
	}
}

// Return next linked node to this node
LinkedNode* LinkedNode::getNextLinkedNode()
{
	if(hasNextLinkedNode())
	{
		return nextLinkedNode_;
	}
	return nullptr;
}

// Set next linked node
void LinkedNode::setNextLinkedNode(LinkedNode* node)
{
	nextLinkedNode_ = node;
}

// Return true if this linked node has a next linked node
bool LinkedNode::hasNextLinkedNode()
{
	if(nextLinkedNode_ == nullptr)
	{
		return false;
	}
	return true;
}
