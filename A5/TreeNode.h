#ifndef TREE_NODE
#define TREE_NODE

#include "node.h"

class TreeNode : public Node {
  public:
    // Constructor
    TreeNode(int data = -1);

    // Copy constructor
    TreeNode(const TreeNode & node);

    // Helper function to copy tree
    TreeNode* copyTree(Node* node);

    // Destructor
    ~TreeNode();

    // METHODS TO GET ALL NODE POINTERS
    inline TreeNode* getLeftChild() {return leftChild_;}
    inline TreeNode* getRightChild() {return rightChild_;}
    inline TreeNode* getParent() {return parent_;}

    // Get node color
    inline bool getColor() {return isRed_;}

    // METHODS TO SET ALL NODE POINTERS
    inline void setLeftChild(TreeNode* leftChild) {leftChild_ = leftChild;}
    inline void setRightChild(TreeNode* rightChild) {rightChild_ = rightChild;}
    inline void setParent(TreeNode* parent) {parent_ = parent;}

    // Set node color
    inline void setColor(bool isRed) {isRed_ = isRed;}

    // Switch node color
    inline void switchColor() {isRed_ = !isRed_;}

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
