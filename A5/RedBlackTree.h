#include "TreeNode.h"
#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree {
  public:
    // Default constructor
    RedBlackTree();

    // Destructor
    ~RedBlackTree() override

    // Insert new tree node with input data
    virtual void insert(int) override;

  private:
    TreeNode* insertHelper(TreeNode* root, TreeNode* node);
}
