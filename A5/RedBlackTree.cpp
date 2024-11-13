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

  // Get lvalue for newNode's parent
  TreeNode* parent = newNode->getParent();
  balanceColor(parent, newNode);
}

TreeNode* RedBlackTree::insertHelper(TreeNode* root, TreeNode* node) {
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

// Rotate tree to left, sets root to left child of it's right node
void RedBlackTree::rotateLeft(TreeNode* & root, TreeNode* & newNode) {
  // Store the node to the right of root, which is the new root
  // TreeNode* newNode = root->getRightChild();

  // Set original root's right node to the new root's left node
  root->setRightChild(newNode->getLeftChild());
  // Update parent node for original root's new right child node
  root->getRightChild()->setParent(root);

  // Logic for root's parent node
  if(root->getParent() == nullptr) {
    setRoot(newNode); // Set new root to root of the entire tree
  }else if (root == root->getParent()->getLeftChild()) {
    // Set left child of original root's parent to new root
    root->getParent()->setLeftChild(newNode);
  }else {
    // Set right child of original root's parent to new root
    root->getParent()->setRightChild(newNode);
  }

  // Set new root's parent node to original root's parent node
  newNode->setParent(root->getParent());
  // Set original root's parent node to new root node
  root->setParent(newNode);

  // Set new root's left child to original root
  newNode->setLeftChild(root);
}

// Rotate tree to right
void RedBlackTree::rotateRight(TreeNode* & root, TreeNode* & newNode) {
  // Store the node to the left of root, which is the new root
  // TreeNode* newNode = root->getLeftChild();

  // Set original root's left node to the new root's right node
  root->setLeftChild(newNode->getRightChild());
  // Update parent node for original root's new left child node
  root->getLeftChild()->setParent(root);

  // Logic for root's parent node
  if(root->getParent() == nullptr) {
    setRoot(newNode); // Set new root to root of the entire tree
  }else if (root == root->getParent()->getLeftChild()) {
    // Set left child of original root's parent to new root
    root->getParent()->setLeftChild(newNode);
  }else {
    // Set right child of original root's parent to new root
    root->getParent()->setRightChild(newNode);
  }

  // Set new root's parent node to original root's parent node
  newNode->setParent(root->getParent());
  // Set original root's parent node to new root node
  root->setParent(newNode);

  // Set new root's right child to original root
  newNode->setRightChild(root);
}

// Maintains color balance in tree after changes
void RedBlackTree::balanceColor(TreeNode* & root, TreeNode* & newNode) {
  // Set tree root to black if not
  if(getRoot()->isRed() == true) {
      std::cout << "Root is red" << std::endl;
      getRoot()->setBlack();
      getRoot()->isRed() ? std::cout << "Root is red" << std::endl : std::cout << "Root is black" << std::endl;
    }

  ///////// look at parent, grandparent, and uncle colors to push down blackness
  // If both nodes are red
  if(root->isRed() && newNode->isRed()) {
    // If root is left child...
    if(root = root->getParent()->getLeftChild()) {
      // If new node is left child...
      if(newNode = root->getLeftChild()) {
        TreeNode* parent = root->getParent(); // Get lvalue for root's parent
        rotateRight(parent, root); // Rotate root to its' parent
      }
      // If new node is right child...
      else if(newNode = root->getRightChild()) {
        rotateLeft(root, newNode); // Rotate newNode to its' root
        TreeNode* parent = newNode->getParent(); // Get lvalue for newNode's parent
        rotateRight(parent, newNode); // Rotate newNode to its' parent
      }
    }
    // If root is right child
    else if (root = root->getParent()->getRightChild()) {
      // If new node is left child...
      if(newNode = root->getLeftChild()) {
        rotateRight(root, newNode); // Rotate newNode to its' root
        TreeNode* parent = newNode->getParent(); // Get lvalue for newNode's parent
        rotateLeft(parent, newNode); // Rotate newNode to it's parent
      }
      // If new node is right child...
      else if(newNode = root->getRightChild()) {
        TreeNode* parent = root->getParent(); // Get lvalue for root's parent
        rotateLeft(parent, root); // Rotate root to its' parent
      }
    }
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
