#include "RedBlackTree.h"

// Default constructor
RedBlackTree::RedBlackTree() : BinarySearchTree() {}

// Destructor
RedBlackTree::~RedBlackTree() {}

// Insert new tree node with input data
void RedBlackTree::insert(int data) {
  // Create new node with data as num
  TreeNode* newNode = new TreeNode(data);

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
      root->setLeftChild(insertHelper(root->getLeftChild(), node));
      root->getLeftChild()->setParent(root);
    // Node is greater than root
    }else if(node->getValue() > root->getValue()) {
      // Right subtree
      root->setRightChild(insertHelper(root->getRightChild(), node));
      root->getRightChild()->setParent(root);
    }else{
      // TODO
    }

    return root;
  }
}

/*
A Red-Black Tree must be a type of Binary Search Tree
• Every node has a color either RED or BLACK
• The root of the tree is always BLACK
• When a node is added to the tree it begins its life as a RED node
• There are no two adjacent RED nodes
• A RED node cannot have a RED parent or a RED child
• Every path from a node to any of its descendant (down to the nullptr) has the same number of
BLACK nodes
*/
