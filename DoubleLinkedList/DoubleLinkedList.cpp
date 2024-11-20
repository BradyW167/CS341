#include "DoubleLinkedList.h"

// Default constructor
DoubleLinkedList::DoubleLinkedList() : LinkedList() {}

// Copy constructor
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList* list)
{
	// Original list is empty, nothing to be copied
	if(list->head_ == nullptr) {return;}

	// Copy number of nodes (length of list)
	nodecount_ = list->nodecount_;

	// Copy head node
	head_ = new LinkedNode(list->head_->getValue());

	// Node pointer to traverse through original list
	LinkedNode* current_original = list->head_->getNextLinkedNode();
	// Node to create new list
	LinkedNode* current_copy = head_;

	// Loop until at nullptr (end of list)
	while(current_original != nullptr)
	{
		// Set next node in copy to the next node in the original list
	    	current_copy->setNextLinkedNode(new LinkedNode(current_original->getNextLinkedNode()->getValue()));
		// Advance both pointers
	    	current_copy = current_copy->getNextLinkedNode();
	    	current_original = current_original->getNextLinkedNode();
	}
	// Set tail pointer to last node in copied list
	tail_ = current_copy;
}

// Destructor
DoubleLinkedList::~DoubleLinkedList() {}

// Insert new node at input node with input data
void DoubleLinkedList::insertLinkedNode(LinkedNode* node, int data)
{
	// Insert at head if input node and head are null pointers
	if(node == nullptr && head_ == nullptr)
	{
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
        new_node->setNextLinkedNode(node->getNextLinkedNode());
        new_node->setPrevLinkedNode(node);
        
	// If there is a node after input node
        if(node->getNextLinkedNode() != nullptr)
            node->getNextLinkedNode()->setPrevLinkedNode(new_node);
        else
            tail_ = new_node;

        node->setNextLinkedNode(new_node);
	// Increment nodecount
	nodecount_++;
}

// Insert new node after input node with input data
void DoubleLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{
  insertLinkedNode(node, data);
}

// Insert new node before input node with input data
void DoubleLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
	// Return if input node is null
	if(node == nullptr) {return;}

	// If inserting at head...
	if(node == head_)
	{
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

void DoubleLinkedList::printList()
{
	// State that list is being printed
	std::cout << "\nPrinting List..." << std::endl;
	// If list is empty
	if(isEmpty()) {std::cout << "List is empty" << std::endl;}

	// Stores pointer to head node
	LinkedNode* n = head_;
	// Loop until on last node (has no next node)
	while(n->hasNextLinkedNode())
	{
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
