#ifndef TREE_NODE
#define TREE_NODE

#include "node.h"

TreeNode : public Node {
  public:
    // Constructor
    TreeNode(data = -1); 

    // Copy constructor
    TreeNode(const TreeNode & node);

    // Destructor
    ~TreeNode();

    // METHODS TO GET ALL NODE POINTERS
    inline TreeNode* getLeftChild() {return leftChild_;}
    inline TreeNode* getRightChild() {return rightChild_;}
    inline TreeNode* getParent() {return parent_;}

    // METHODS TO SET ALL NODE POINTERS
    inline void setLeftChild(TreeNode* node) {leftChild_ = node;}
    inline void setRightChild(TreeNode* node) {rightChild_ = node;}
    inline void setParent(TreeNode* node) {parent_ = node;}

  private:
    // Store pointer to left child node
    TreeNode* leftChild_;

    // Stores pointer to right child node
    TreeNode* leftChild_;

    //Stores pointer to parent node
    TreeNode* parent_;
};

#endif
