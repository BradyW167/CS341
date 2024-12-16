#include "DoubleLinkedList.h"

// Default constructor
DoubleLinkedList::DoubleLinkedList() : LinkedList() {}


// Destructor
DoubleLinkedList::~DoubleLinkedList() {}

// Insert new node at input node with input data
void DoubleLinkedList::insertLinkedNode(LinkedNode* node, int data) {
	// Insert at head if input node and head are null pointers
	if (node == nullptr && head_ == nullptr) {
		// Create the new node
		LinkedNode* new_node = new LinkedNode(data);
		// Store data in first node as head_
		head_ = new_node;
		// Since this is first node, it is both the head and the tail
		tail_ = new_node;
    // Increment nodecount
    nodecount_++;
		return;
	}

  // Create the new node
  LinkedNode* new_node = new LinkedNode(data);

  // Insert the new node after the input node
  new_node->setPrevLinkedNode(node);

  // If there is a node after input node
  if (node->getNextLinkedNode() != nullptr) {
    new_node->setNextLinkedNode(node->getNextLinkedNode());
    node->getNextLinkedNode()->setPrevLinkedNode(new_node);
  }
  // Else new node is the tail
  else {tail_ = new_node;}

  node->setNextLinkedNode(new_node);

	// Increment nodecount
	nodecount_++;
}

// Insert new node after input node with input data
void DoubleLinkedList::insertAfterLinkedNode(LinkedNode * node, int data) {
  insertLinkedNode(node, data);
}

// Insert new node before input node with input data
void DoubleLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data) {
	// Return if input node is null
	if (node == nullptr) {return;}

	// If inserting at head...
	if (node == head_) {
		// Create new node with data
    LinkedNode* new_node = new LinkedNode(data);

		// Set new node's next linked node to head_
    new_node->setNextLinkedNode(head_);
		
		// Set head's previous linked node to the new node
    head_->setPrevLinkedNode(new_node);

    // Set new node to head
		head_ = new_node;

		// If at tail, set tail to new node
    if(tail_ == nullptr) {tail_ = new_node;}
	}

	// Insert node
	insertLinkedNode(node->getPrevLinkedNode(), data);
}

void DoubleLinkedList::printList() {
	// State that list is being printed
	std::cout << "\nPrinting List..." << std::endl;
	// If list is empty
	if (isEmpty()) {std::cout << "List is empty" << std::endl;}

	// Stores pointer to head node
	LinkedNode* n = head_;
	// Loop until on last node (has no next node)
	while (n->hasNextLinkedNode()) {
		// Print node n's value
		std::cout << n->getValue() << "<-->";
		// Store next node in n
		n = n->getNextLinkedNode();
	}

	// Print tail node's value
	std::cout << n->getValue() << std::endl;

  // Print length of list
  std::cout << "Length: " << nodecount_ << std::endl;
}
