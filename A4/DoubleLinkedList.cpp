#include "DoubleLinkedList.h"

// Default constructor
DoubleLinkedList::DoubleLinkedList() : head_(nullptr), tail_(nullptr){}

// Copy constructor
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList* list)
{
  // Original list is empty, nothing to be copied
  if(list.head_ == nullptr) {return;}

  // Copy number of nodes (length of list)
  nodecount_ = list.nodecount_;

  // Copy head node
  head_ = new LinkedNode(list.head_->getValue());

  // Node pointer to traverse through original list
  LinkedNode* current_original = list.head_->getNextLinkedNode();
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
DoubleLinkedList::~DoubleLinkedList()
{
	// Delete head if head is not null
	// Recursion takes care of the rest
	if(head_ != nullptr) {delete head_;}
}

// Insert input node with input data
void insertLinkedNode(LinkedNode* node, int data)
{
  return;
}

// Insert input node with input data 
void insertAfterLinkedNode(LinkedNode * node, int data)
{
  return;
}

void insertBeforeLinkedNode(LinkedNode * node, int data)
{
  return;
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
}
