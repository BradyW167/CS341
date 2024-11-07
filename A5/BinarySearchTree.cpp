#include "BinarySearchTree.h"

// Default constructor
BinarySearchTree::BinarySearchTree() : root_(nullptr), height_(0) {}

// Copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree & tree) {
  // Original tree is empty, nothing to copy
  if(tree.root_ == nullptr) {return;}

  // Copy height of tree
  height_ = tree.height_;

  // Copy root node
  root_ = new TreeNode(tree.root_->getValue());

}

// Destructor
BinarySearchTree::~BinarySearchTree() {
  // If root is not null, delete root and leave to recursion
  if(root_ != nullptr) {
    delete root_;
  }
}

// Insert node with data as num
void BinarySearchTree::insert(int num) {
  // Create new node with data as num
  TreeNode* newNode = new TreeNode(num);

  // Call method to insert node
  // Set root node to the returned node
  root_ = insertNode(root_, newNode);
}

void BinarySearchTree::print(TreeNode* root) {
  if(root == nullptr) { 
  }else {
    print(root->getLeftChild());
    std::cout << root->getValue() << " ";
    print(root->getRightChild());
  }
}

TreeNode* BinarySearchTree::insertNode(TreeNode* root, TreeNode* node){
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
