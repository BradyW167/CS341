#include "LinkedList.h"

// Default constructor
LinkedList::LinkedList() : head_(nullptr), tail_(nullptr), nodecount_(0) {}

// Destructor
LinkedList::~LinkedList()
{
	// Delete head if head is not null
	// Recursion takes care of the rest
	if(head_ != nullptr) {delete head_;}
}

// Returns true if list is empty, false if not
bool LinkedList::isEmpty() {return (head_ == nullptr) ? true : false;}

// Returns nodecount (number of nodes)
int LinkedList::getLength() {return nodecount_;}

// Insert data element into node at tail
void LinkedList::insert(int element)
{
	// Print out element to be inserted
	std::cout << "Inserting " << element << "..." << std::endl;

	// If list is empty
	if(isEmpty())
	{
		// Store data element in first node as head_
		head_ = new LinkedNode(element);
		// Since this is first node, it is both the head and the tail
		tail_ = head_;
		return;
	}

	// Stores pointer to head node
	LinkedNode* n = head_;
	// Loop until on last node (has no next node)
	while(n->hasNextLinkedNode())
	{
		// Stores next node in n
		n = n->getNextLinkedNode();
	}

	// Set n's next node to store data element
	n->setNextLinkedNode(new LinkedNode(element));
	// Node n is now the last node or the tail
	tail_ = n;
}

// Delete a node
void LinkedList::deleteNode(int num)
{
	if(head_->getValue() == num)
	{
		if(head_->hasNextLinkedNode())
		{
			LinkedNode* newhead = head_->getNextLinkedNode();
			head_->getNextLinkedNode()->setPrevLinkedNode(nullptr);
			head_->setNextLinkedNode(nullptr);
			delete head_;
			head_ = newhead;
		}
	}
}

void LinkedList::printList()
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
		std::cout << n->getValue() << "->";
		// Store next node in n
		n = n->getNextLinkedNode();
	}
	// Print tail node's value
	std::cout << n->getValue() << std::endl;
}
