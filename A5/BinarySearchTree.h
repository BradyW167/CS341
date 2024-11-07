#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include "TreeNode.h"

class BinarySearchTree {
  public:
    // Constructor
    BinarySearchTree();

    // Copy constructor
    BinarySearchTree(const BinarySearchTree & tree);

    // Destructor
    virtual ~BinarySearchTree();

    // Set the root node
    inline void setRoot(TreeNode* node) {root_ = node;}

    // Get the root node
    inline TreeNode* getRoot() {return root_;}

    // Get the height of the tree
    inline int getHeight() {return height_;}

    // Insert input data into new node and add to tree
    virtual void insert(int);

    // Print the tree
    void print(TreeNode* root);

  private:
    // Stores pointer to root node
    TreeNode* root_;

    // Insert input node based on input root
    TreeNode* insertNode(TreeNode* root, TreeNode* node);

    // Stores height of tree
    int height_;
};

#endif
