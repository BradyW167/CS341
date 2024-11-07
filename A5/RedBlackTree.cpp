#include "RedBlackTree.h"

// Default constructor
RedBlackTree::RedBlackTree : BinarySearchTree() {}

// Destructor
RedBlackTree::~RedBlackTree {}

// Insert new tree node with input data
void RedBlackTree::insert(int data) {
  // Create new node with data as num
  TreeNode* newNode = new TreeNode(num);

  // Call method to insert node
  // Set root node to the returned node
  root_ = insertHelper(root_, newNode);

  // balanceColor(root);
}

TreeNode* RedBlackTree::insertHelper(TreeNode* root, TreeNode* node){
  // Return node if root is nullptr
  if(root == nullptr) {
    return node;
  }else {
    // Node is less than root
    if(node->getValue() < root->getValue()) {
      // Left subtree
      root->setLeftChild(insertNode(root->getLeftChild(), node));
      root->getLeftChild()->setParent(root);
    // Node is greater than root
    }else if(node->getValue() > root->getValue()) {
      // Right subtree
      root->setRightChild(insertNode(root->getRightChild(), node));
      root->getRightChild()->setParent(root);
    }else{
      // TODO
    }

    return root;
  }
}
