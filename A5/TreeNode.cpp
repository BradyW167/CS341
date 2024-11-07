#include "TreeNode.h"

// Constructor
TreeNode::TreeNode(int data) : Node(data), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr), isRed(true) {}

// Copy constructor
TreeNode::TreeNode(const TreeNode & node) {
  // If left child exists, copy then recur
  if(leftChild_ != nullptr) {
    // Create new left child and copy it
    leftChild_ = new TreeNode(node.getLeftChild()->getValue());
  }
  // If right child exists, copy then recur
  if(rightChild_ != nullptr) {
    // Create new right child and copy it
    rightChild_ = new TreeNode(node.getRightChild()->getValue());
  }
  // If parent exists, copy
  if(node.parent_ != nullptr) {
    parent_ = 
  }
}

// Helper function to copy tree
TreeNode* copyTree(Node* node) {
  if(node == nullptr) {
    return nullptr;
  }
}

// Destructor
TreeNode::~TreeNode() {
  // If left child exists, delete then recur
  if(leftChild_ != nullptr) {
    delete leftChild_;
  }
  // If right child exists, delete then recur
  if(rightChild_ != nullptr) {
    delete rightChild_;
  }
}
