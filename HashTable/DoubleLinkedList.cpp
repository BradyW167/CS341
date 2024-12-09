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

void DoubleLinkedList::remove(HashEntry data) {
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
      LinkedNode* oldHead = LinkedList::getHead(); // Get pointer to head node
      LinkedNode* newHead = LinkedList::getHead()->getNextLinkedNode(); // Get pointer to head node's next node

      LinkedList::setHead(newHead);

      // Break the pointers...
      oldHead->setNextLinkedNode(nullptr);
      newHead->setPrevLinkedNode(nullptr);

      delete oldHead;

      isFound = true;
    }
    // If data is found in the tail node...
    else if(data == LinkedList::getTail()->getEntry()) {
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
        // If current node's entry matches input data...
        if (curNode->getEntry() == data) {
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

void DoubleLinkedList::printList() {
	// State that list is being printed
	std::cout << "\nPrinting List..." << std::endl;

	// If list is empty
	if (isEmpty()) {std::cout << "List is empty" << std::endl;}

	// Stores pointer to head node
	LinkedNode* n = head_;

	// Loop until on last node (has no next node)
	while (n->hasNextLinkedNode()) {
		// Print node n's entry
		std::cout << n->getEntry() << "<-->";
		// Store next node in n
		n = n->getNextLinkedNode();
	}
	// Print tail node's value
	std::cout << n->getEntry() << std::endl;
  // Print length of list
  std::cout << "Length: " << nodecount_ << std::endl;
}
