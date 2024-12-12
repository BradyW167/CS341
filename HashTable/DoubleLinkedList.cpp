// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "DoubleLinkedList.h"

// Default constructor
DoubleLinkedList::DoubleLinkedList() : LinkedList() {}

// Destructor
DoubleLinkedList::~DoubleLinkedList() {}

// Insert new node at input node with input hash entry
void DoubleLinkedList::insertLinkedNode(LinkedNode* node, HashEntry data) {
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
void DoubleLinkedList::insertAfterLinkedNode(LinkedNode * node, HashEntry data)
{
  insertLinkedNode(node, data);
}

// Insert new node before input node with input data
void DoubleLinkedList::insertBeforeLinkedNode(LinkedNode * node, HashEntry data)
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

int DoubleLinkedList::find(int key) {
  // Stores current node, starting at head
  LinkedNode* curNode = LinkedList::getHead();

  // Loop until at nullptr (end of list)
  while (curNode != nullptr) {
    // If current node's entry matches input data...
    if (curNode->getEntry().getKey() == key) {
      return curNode->getEntry().getValue(); // Return value of node's entry with matching key
    }
    // Else get next node
    else {curNode = curNode->getNextLinkedNode();}
  }

  // Matching node is not found
  return -1;
}

void DoubleLinkedList::removeLinkedNode(int key) {
  // If list is empty, return
  if (LinkedList::isEmpty()) {return;}
  // Else search for linked node using input key
  else {
    // Tracks if matching hash entry key is found
    bool isFound = false;

    // If data is found in the head node...
    if (key == LinkedList::getHead()->getEntry().getKey()) {
      // If head node is only node
      if (LinkedList::getLength() == 1) {
        // Delete head
        delete (LinkedList::getHead());

        // Set pointers to nullptr
        LinkedList::setHead(nullptr);
        LinkedList::setTail(nullptr);
      }
      // Else there are more nodes...
      else {
        LinkedNode* oldHead = LinkedList::getHead(); // Get pointer to head node
        LinkedNode* newHead = LinkedList::getHead()->getNextLinkedNode(); // Get pointer to head node's next node

        LinkedList::setHead(newHead);

        // Break the pointers...
        oldHead->setNextLinkedNode(nullptr);
        newHead->setPrevLinkedNode(nullptr);

        delete oldHead; // Delete head
      }


      isFound = true; // Matching key was found
    }
    // If key is found in the tail node...
    else if(key == LinkedList::getTail()->getEntry().getKey()) {
      LinkedNode* oldTail = LinkedList::getTail(); // Get pointer to head node
      LinkedNode* newTail = LinkedList::getTail()->getPrevLinkedNode(); // Get pointer to head node's next node

      LinkedList::setTail(newTail);

      // Break the pointers...
      oldTail->setPrevLinkedNode(nullptr);
      newTail->setNextLinkedNode(nullptr);

      delete oldTail;

      isFound = true;
    }
    // Else search for data inside the DLL...
    else {
      LinkedNode* curNode = LinkedList::getHead(); // Stores current node, starting at head

      // Loop until at nullptr (end of list) or node with matching data is found
      while (curNode != nullptr && !isFound) {
        // If key is found in the current node...
        if (key == curNode->getEntry().getKey()) {
          LinkedNode* nextNode = curNode->getNextLinkedNode();
          LinkedNode* prevNode = curNode->getPrevLinkedNode();

          // Reset pointers to account for removed node
          nextNode->setPrevLinkedNode(prevNode);
          prevNode->setNextLinkedNode(nextNode);

          // Break the pointers
          curNode->setPrevLinkedNode(nullptr);
          curNode->setNextLinkedNode(nullptr);

          delete curNode;

          isFound = true;
        }
        // Else get next node
        else {curNode = curNode->getNextLinkedNode();}
      }
    }
    // If a matching node was found...
    if (isFound) {nodecount_--;} // Decrement node counter
  }
}

void DoubleLinkedList::printList() {
	// State that list is being printed
	std::cout << "\nPrinting List..." << std::endl;

	// If list is empty...
	if (LinkedList::isEmpty()) {
    std::cout << std::endl; // Print nextline character only
    return;
  }

	// Stores pointer to head node
	LinkedNode* n = head_;

	// Loop until on last node (has no next node)
	while (n->hasNextLinkedNode()) {
		// Print node n's entry
		std::cout << n->getEntry().getKey() << "<-->";

		// Store next node in n
		n = n->getNextLinkedNode();
	}
	// Print tail node's value
	std::cout << n->getEntry().getKey() << std::endl;
}

// Overload the << operator to print the DLL data to an output stream
std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& dll) {
	// If list is empty, return empty output stream
	if (dll.isEmpty()) {return os;}

	// Stores pointer to head node
	LinkedNode* n = dll.head_;

	// Loop until on last node (has no next node)
	while (n->hasNextLinkedNode()) {
		// Print node n's entry
		os << n->getEntry().getKey() << "<-->";

		// Store next node in n
		n = n->getNextLinkedNode();
	}
	// Print tail node's value
	os << n->getEntry().getKey();

  // Return output stream
  return os;
}
