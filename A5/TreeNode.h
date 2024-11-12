#ifndef TREE_NODE
#define TREE_NODE

#include "node.h"

class TreeNode : public Node {
  public:
    // Constructor
    TreeNode(int data = -1);

    // Destructor
    ~TreeNode();

    // METHODS TO GET ALL NODE POINTERS
    inline TreeNode* getLeftChild() {return leftChild_;}
    inline TreeNode* getRightChild() {return rightChild_;}
    inline TreeNode* getParent() {return parent_;}


    // METHODS TO SET ALL NODE POINTERS
    inline void setLeftChild(TreeNode* leftChild) {leftChild_ = leftChild;}
    inline void setRightChild(TreeNode* rightChild) {rightChild_ = rightChild;}
    inline void setParent(TreeNode* parent) {parent_ = parent;}

    // Get node color
    inline bool isRed() {return isRed_;}

    // Set node color to red
    inline void setRed(bool isRed = true) {isRed_ = isRed;}

    // Set node color to black
    inline void setBlack() {isRed_ = false;}

  private:
    // Store pointer to left child node
    TreeNode* leftChild_;

    // Stores pointer to right child node
    TreeNode* rightChild_;

    // Stores pointer to parent node
    TreeNode* parent_;

    // Boolean true for red, false for black
    bool isRed_;
};

#endif
