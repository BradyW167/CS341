#include "LinkedNode.h"

// Default constructor
LinkedNode::LinkedNode() : Node(-1), nextLinkedNode_(nullptr) {}

// Constructor with input data, previous node, and next node
LinkedNode::LinkedNode(int data, LinkedNode* nextLinkedNode, LinkedNode* prevLinkedNode) : Node(data), nextLinkedNode_(nextLinkedNode), prevLinkedNode_(prevLinkedNode) {}

// Copy constructor
LinkedNode::LinkedNode(const LinkedNode & node)
{
  // Copy data_ value to this node
  setValue(node.data_);
  prevLinkedNode_ = node.prevLinkedNode_;
  nextLinkedNode_ = node.nextLinkedNode_;
}

// Destructor
LinkedNode::~LinkedNode()
{
	if(hasNextLinkedNode())
	{
		delete nextLinkedNode_;
	}
}

// Return previous linked node to this node
LinkedNode* LinkedNode::getPrevLinkedNode()
{
  // Return previous node if there is one
	if(hasPrevLinkedNode()) {return prevLinkedNode_;}
  // Return nullptr if no previous node
	return nullptr;
}

// Return next linked node to this node
LinkedNode* LinkedNode::getNextLinkedNode()
{
  // Return next node if there is one
	if(hasNextLinkedNode()) {return nextLinkedNode_;}
  // Return nullptr if no next node
	return nullptr;
}

// Set previous linked node
void LinkedNode::setPrevLinkedNode(LinkedNode* node) {prevLinkedNode_ = node;}

// Set next linked node
void LinkedNode::setNextLinkedNode(LinkedNode* node) {nextLinkedNode_ = node;}

// Return true if this linked node has a next linked node
bool LinkedNode::hasPrevLinkedNode()
{
	if(prevLinkedNode_ == nullptr)
	{
		return false;
	}
	return true;
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
