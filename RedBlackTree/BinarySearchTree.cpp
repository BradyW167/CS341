// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "BinarySearchTree.h"

// Default constructor
BinarySearchTree::BinarySearchTree() : root_(nullptr), height_(0) {}

// Copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree & tree) {
  std::cout << "Original tree root value: " << tree.root_->getValue() << std::endl;
  // Copy root and recursively copy rest of tree
  root_ = copyTree(tree.root_);

  // Copy height of tree
  height_ = tree.height_;
}

// Helper function to copy tree
TreeNode* BinarySearchTree::copyTree(TreeNode* node) {
  if(node == nullptr) {
    return nullptr;
  }
  // Create new node for this tree from input node's value
  TreeNode* newNode = new TreeNode(node->getValue());

  // Copy node to new tree and recurse from left tree
  newNode->setLeftChild(copyTree(node->getLeftChild()));

  // Copy node to new tree and recurse from left tree
  newNode->setRightChild(copyTree(node->getRightChild()));

  // Return the node for recursively setting its children
  return newNode;
}

// Destructor
BinarySearchTree::~BinarySearchTree() {
  // If root is not null, delete root and leave to recursion
  if(root_ != nullptr) {
    delete root_;
  }
}

// Calculate height of this tree
int BinarySearchTree::getHeight(TreeNode* node) {
  // Stores height of subtrees
  int leftHeight = 0, rightHeight = 0, height = 0;

  // Return 0 if input node is nullptr
  if(node == nullptr) {return 0;}
  else {
    leftHeight = getHeight(node->getLeftChild());
    rightHeight = getHeight(node->getRightChild());

    height = (leftHeight > rightHeight) ? leftHeight : rightHeight;

    return height + 1;
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
