// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "RedBlackTree.h"

// Default constructor
RedBlackTree::RedBlackTree() : BinarySearchTree() {}

// Destructor
RedBlackTree::~RedBlackTree() {}

// Copy constructor
RedBlackTree::RedBlackTree(const RedBlackTree & tree) {
  // Copy root and recursively copy rest of tree
  root_ = copyTree(nullptr, tree.root_);

  // Copy height of tree
  height_ = tree.height_;
}

// Helper function to copy tree
TreeNode* RedBlackTree::copyTree(TreeNode* root, TreeNode* node) {
  // Return nullptr if this node is nullptr
  if(node == nullptr) {return nullptr;}

  // Create new node for this tree from input node's value
  TreeNode* newNode = new TreeNode(node->getValue());

  // Copy color of node
  // Nodes are red by default, change when not red
  if(!node->isRed()) {newNode->setBlack();}

  // Copy parent pointer for this node
  newNode->setParent(root);

  // Copy node to new tree and recurse from left tree
  newNode->setLeftChild(copyTree(node, node->getLeftChild()));

  // Copy node to new tree and recurse from left tree
  newNode->setRightChild(copyTree(node, node->getRightChild()));

  // Return the node for recursively setting its children
  return newNode;
}


// Insert new tree node with input data
void RedBlackTree::insert(int data) {
  // Create new node with data as num
  TreeNode* newNode = new TreeNode(data);

  // Call method to insert node
  // Set root node to the returned node
  root_ = insertHelper(root_, newNode);

  // Get lvalue for newNode's parent
  TreeNode* parent = newNode->getParent();

  // Check the tree for color imbalances
  balanceColor(parent, newNode);
}

void RedBlackTree::printRedNodes(TreeNode* root) {
  // Print if this node is not nullptr
  if(root != nullptr) {
    printRedNodes(root->getLeftChild()); // Print left subtree first for inorder
    if(root->isRed()) {std::cout << root->getValue() << " ";} // Print red root values
    printRedNodes(root->getRightChild()); // Print right subtree last for inorder
  }
}

void RedBlackTree::printBlackNodes(TreeNode* root) {
  // Print nothing when nullptr
  if(root == nullptr) {
  }else {
    if(!root->isRed()) {std::cout << root->getValue() << " ";} // Print red root values
    printBlackNodes(root->getLeftChild()); // Print left subtree first for inorder
    printBlackNodes(root->getRightChild()); // Print right subtree last for inorder
  }
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
    // Get lvalue for new node's right child and grandparent node
  TreeNode* newNodeLeftChild = newNode->getLeftChild();
  TreeNode* grand = root->getParent();

  // Check for nullptr
  if(newNodeLeftChild != nullptr) {
    // Set original root's right node to the new root's left node
    root->setRightChild(newNodeLeftChild);
    // Update parent node for original root's new right child node
    newNodeLeftChild->setParent(root);
  }else {
    root->setRightChild(nullptr);
  }

  // Logic for root's parent node
  if(grand == nullptr) {
    setRoot(newNode); // Set new root to root of the entire tree
  }else if (root == grand->getLeftChild()) {
    // Set left child of original root's parent to new root
    grand->setLeftChild(newNode);
  }else {
    // Set right child of original root's parent to new root
    grand->setRightChild(newNode);
  }

  // Set new root's parent node to original root's parent node
  newNode->setParent(grand);
  // Set original root's parent node to new root node
  root->setParent(newNode);

  // Set new root's left child to original root
  newNode->setLeftChild(root);
}

// Rotate tree to right
void RedBlackTree::rotateRight(TreeNode* & root, TreeNode* & newNode) {
  // Get lvalue for new node's right child and grandparent node
  TreeNode* newNodeRightChild = newNode->getRightChild();
  TreeNode* grand = root->getParent();

  // Check for nullptr
  if(newNodeRightChild != nullptr) {
    // Set original root's left node to the new root's right node
    root->setLeftChild(newNodeRightChild);
    // Update parent node for original root's new left child node
    newNodeRightChild->setParent(root);
  }else {
    root->setLeftChild(nullptr);
  }

  // Logic for root's parent node
  if(grand == nullptr) {
    setRoot(newNode); // Set new root to root of the entire tree
  }else if (root == grand->getLeftChild()) {
    // Set left child of original root's parent to new root
    grand->setLeftChild(newNode);
  }else {
    // Set right child of original root's parent to new root
    grand->setRightChild(newNode);
  }

  // Set new root's parent node to original root's parent node
  newNode->setParent(grand);
  // Set original root's parent node to new root node
  root->setParent(newNode);

  // Set new root's right child to original root
  newNode->setRightChild(root);
}

// Maintains color balance in tree after changes
void RedBlackTree::balanceColor(TreeNode* & root, TreeNode* & newNode) {

  // Root is nullptr, this is the root of the tree
  if(root == nullptr) {
    std::cout << "Setting root to black" << std::endl;
    newNode->setBlack();
  }

  // New node and its parent are both red
  else if(root->isRed() && newNode->isRed()) {
    std::cout << "Two red nodes detected" << std::endl;

    TreeNode* grand = root->getParent(); // Get lvalue for grandparent node

    // If root is left child...
    if(root == grand->getLeftChild()) {
      std::cout << "Root is left child" << std::endl;

      TreeNode* uncle = grand->getRightChild(); // Get lvalue for uncle node

      // If uncle is red...
      if(uncle != nullptr && uncle->isRed()) {
        std::cout << "Uncle is red, pushing blackness down" << std::endl;

        // Push blackness down from grandparent node to parent and uncle nodes
        grand->setRed();
        root->setBlack();
        uncle->setBlack();

        TreeNode* greatGrand = grand->getParent(); // Get lvalue for great grandparent node

        balanceColor(greatGrand, grand); // Recursive call above color fixed nodes
      }

      // If new node is left child...
      else if(newNode = root->getLeftChild()) {
        rotateRight(grand, root); // Rotate parent to grandparent node

        // Fix coloring on rotated nodes
        root->setBlack();
        grand->setRed();
      }

      // If new node is right child...
      else if(newNode == root->getRightChild()) {
        rotateLeft(root, newNode); // Rotate newNode to parent
        rotateRight(grand, newNode); // Rotate newNode to grandparent

        // Fix coloring on rotated nodes
        newNode->setBlack();
        grand->setRed();
      }
    }

    // If root is right child...
    else if (root == grand->getRightChild()) {
      std::cout << "Root is right child" << std::endl;

      TreeNode* uncle = grand->getLeftChild(); // Get lvalue for uncle node

      // If uncle is red...
      if(uncle != nullptr && uncle->isRed()) {
        std::cout << "Uncle is red, pushing blackness down" << std::endl;

        // Push blackness down from grandparent node to parent and uncle nodes
        grand->setRed();
        root->setBlack();
        uncle->setBlack();

        TreeNode* greatGrand = grand->getParent(); // Get lvalue for great grandparent node

        balanceColor(greatGrand, grand); // Recursive call above color fixed nodes
      }

      // If new node is left child...
      else if(newNode == root->getLeftChild()) {
        std::cout << "New node is left child" << std::endl;
        rotateRight(root, newNode); // Rotate newNode to parent
        rotateLeft(grand, newNode); // Rotate newNode to grandparent

        // Fix coloring on rotated nodes
        newNode->setBlack();
        grand->setRed();
      }

      // If new node is right child...
      else if(newNode == root->getRightChild()) {
        std::cout << "New node is right child" << std::endl;
        rotateLeft(grand, root); // Rotate parent to grandparent node

        // Fix coloring on rotated nodes
        root->setBlack();
        grand->setRed();
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
