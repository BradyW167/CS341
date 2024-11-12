#include "TreeNode.h"
#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree {
  public:
    // Default constructor
    RedBlackTree();

    // Destructor
    ~RedBlackTree() override;

    // Insert new tree node with input data
    virtual void insert(int) override;

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
