// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "TreeNode.h"

// Constructor
TreeNode::TreeNode(int data) : Node(data), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr), isRed_(true) {}

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
