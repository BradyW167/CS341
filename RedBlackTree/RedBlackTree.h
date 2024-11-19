// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include <iostream>

#include "BinarySearchTree.h"
#include "TreeNode.h"

class RedBlackTree : public BinarySearchTree {
  public:
    // Default constructor
    RedBlackTree();

    // Destructor
    ~RedBlackTree() override;

    // Copy constructor
    RedBlackTree(const RedBlackTree & tree);

    // Copy helper function
    TreeNode* copyTree(TreeNode* root, TreeNode* node);

    // Insert new tree node with input data
    virtual void insert(int) override;

    // Prints red nodes inorder
    void printRedNodes(TreeNode * root);

    // Prints black nodes preorder
    void printBlackNodes(TreeNode * root);

  private:
    // Helper function for recursive insert calls
    TreeNode* insertHelper(TreeNode* root, TreeNode* node);

    // Rotate tree to left, sets root to left child
    void rotateLeft(TreeNode* & root, TreeNode* & newNode);

    // Rotate tree to right, sets root to right child
    void rotateRight(TreeNode* & root, TreeNode* & newNode);

    // Maintains color balance in tree after changes
    void balanceColor(TreeNode* & root, TreeNode* & newNode);

};
