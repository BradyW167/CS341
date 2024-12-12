// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "LinkedList.h"

// Default constructor
LinkedList::LinkedList () : head_(nullptr), tail_(nullptr), nodecount_(0) {}

// Copy constructor
LinkedList::LinkedList(const LinkedList* & list) {
	// Original list is empty, nothing to be copied
	if (list->head_ == nullptr) {return;}

	// Copy number of nodes (length of list)
	nodecount_ = list->nodecount_;

	// Copy head node
	head_ = new LinkedNode(list->head_->getEntry());

	// Node pointer to traverse through original list
	LinkedNode* current_original = list->head_->getNextLinkedNode();
	// Node to create new list
	LinkedNode* current_copy = head_;

	// Loop until at nullptr (end of list)
	while (current_original != nullptr) {
		// Set next node in copy to the next node in the original list
    current_copy->setNextLinkedNode(new LinkedNode(current_original->getNextLinkedNode()->getEntry()));
		// Advance both pointers
    current_copy = current_copy->getNextLinkedNode();
    current_original = current_original->getNextLinkedNode();
	}
	// Set tail pointer to last node in copied list
	tail_ = current_copy;
}

// Destructor
LinkedList::~LinkedList() {
	// Delete head if head is not null
	// Recursion takes care of the rest
	if(head_ != nullptr) {delete head_;}
}

// Returns true if list is empty, false if not
bool LinkedList::isEmpty() const {return (head_ == nullptr) ? true : false;}

// Returns nodecount (number of nodes)
int LinkedList::getLength() {return nodecount_;}

// Insert data element into node at tail
void LinkedList::insert(HashEntry data) {
	// Print out element to be inserted
	// std::cout << "Inserting node with entry " << data << "..." << std::endl;

	// If list is empty
	if(isEmpty()) {
		// Store hash entry data in first node as head_
		head_ = new LinkedNode(data);
		// Since this is first node, it is both the head and the tail
		tail_ = head_;
    		// Set nodecount to 1
    		nodecount_ = 1;
		return;
	}

	// Stores pointer to head node
	LinkedNode* n = head_;
	
	// Loop until on last node (has no next node)
	while(n->hasNextLinkedNode()) {
		// Stores next node in n
		n = n->getNextLinkedNode();
	}

	// Set n's next node to store hash entry data
	n->setNextLinkedNode(new LinkedNode(data));
	// Node n is now the last node or the tail
	tail_ = n->getNextLinkedNode();
  	// Increment nodecount_
  	nodecount_++;
}

void LinkedList::remove(HashEntry data) {
  // If list is empty, print and return
  if (isEmpty()) {
    std::cout << "List is empty" << std::endl;
    return;
  }
  // Else search for linked node using hash entry data
  else {
    // Tracks if matching hash entry key is found
    bool isFound = false;

    // If data is found in the head node...
    if (data == LinkedList::getHead()->getEntry()) {
      LinkedNode* oldHead = getHead(); // Get pointer to head node
      LinkedNode* newHead = getHead()->getNextLinkedNode(); // Get pointer to head node's next node

      setHead(newHead);

      // Break the pointer...
      oldHead->setNextLinkedNode(nullptr);

      delete oldHead;

      isFound = true;
    }
    // If data is found in the tail node...
    else if (data == getTail()->getEntry()) {
      LinkedNode* oldTail = LinkedList::getTail(); // Get pointer to head node
      LinkedNode* newTail = LinkedList::getTail()->getPrevLinkedNode(); // Get pointer to head node's next node

      LinkedList::setTail(newTail);

      // Break the pointer
      newTail->setNextLinkedNode(nullptr);

      delete oldTail;

      isFound = true;
    }
    // Else search for data inside the DLL...
    else {
      LinkedNode* curNode = getHead(); // Stores current node, starting at head

      // Loop until at nullptr (end of list) or node with matching data is found
      while (curNode != nullptr && !isFound) {
        // If current node's entry matches input data...
        if (curNode->getEntry() == data) {
          LinkedNode* nextNode = curNode->getNextLinkedNode();
          LinkedNode* prevNode = curNode->getPrevLinkedNode();

          // Reset pointer to account for removed node
          prevNode->setNextLinkedNode(nextNode);

          // Break the pointer
          curNode->setNextLinkedNode(nullptr);

          delete curNode;

          isFound = true;
        }
        // Else get next node
        else {curNode = curNode->getNextLinkedNode();}
      }
    }
    // If a matching node was found...
    if (isFound) {
      nodecount_--; // Decrement node counter
      std::cout << "\nDeleted node " << data << std::endl;
    }
    // Else node was not found
    else {
      std::cout << "\n Node with entry " << data <<" not found" << std::endl;
    }
  }
}

void LinkedList::printList() {
	// State that list is being printed
	std::cout << "\nPrinting List..." << std::endl;
	// If list is empty
	if(isEmpty()) {std::cout << "List is empty" << std::endl;}

	// Stores pointer to head node
	LinkedNode* n = head_;
	// Loop until on last node (has no next node)
	while (n->hasNextLinkedNode()) {
		// Print node n's value
		std::cout << n->getEntry() << "->";
		// Store next node in n
		n = n->getNextLinkedNode();
	}
	// Print tail node's value
	std::cout << n->getEntry() << std::endl;
  // Print length of list
  std::cout << "Length: " << nodecount_ << std::endl;
}
