#include "BinarySearchTree.h"

// Default constructor
BinarySearchTree::BinarySearchTree() : root_(nullptr), height_(0) {}

// Copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree & tree) {

}

// Destructor
BinarySearchTree::~BinarySearchTree() {
  // If root is not null, delete root and leave to recursion
  if(root_ != nullptr) {
    delete root_;
  }
}

// Insert node with data as num
BinarySearchTree::insert(int num) {
  // Create new node with data as num
  TreeNode* newNode = new TreeNode(num);
  // Call method to insert node and 
  root_ = insertNode(root_, newNode);

  // balanceColor(root);
}

BinarySearchTree::print(TreeNode* root) {
  if(root = nullptr) {
    std::cout << "Empty tree" << std::endl;
  }else {
    print(root->getLeftChild());
    std::cout << root->getValue() << " ";
    print(root->getRightChild());
  }
}

TreeNode* BinarySearchTree::insertNode(TreeNode* root, TreeNode* node){
  if(root == nullptr) {return node;}
  else {
    if(node->getValue() < root->getValue()) {
      // Left subtree
      root->setLeftChild(insertNode(root->getLeftChild(), node));
      root->getLeftChild()->setParent(root);
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
