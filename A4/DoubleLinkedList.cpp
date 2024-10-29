#include "LinkedList.h"

// Default constructor
LinkedList::LinkedList() : head_(nullptr), tail_(nullptr){}

// Destructor
LinkedList::~LinkedList() {}

// Returns true if list is empty, false if not
bool LinkedList::isEmpty(){return (head_ == nullptr) ? true : false;}

int LinkedList::getLength()
{
	// Return 0 if list is empty
	if(isEmpty()) {return 0;}

	// Stores number of nodes
	int count = 0;
	// Stores pointer to head node
	LinkedNode* n = head_;

	// While node n has a next node
	while(n->hasNextLinkedNode())
	{
		// Increment node counter
		count++;
		// Store next node in n
		n = n->getNextLinkedNode();
	}

	// Return number of nodes
	return count;
}

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
}
