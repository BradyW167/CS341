// Constructor
TreeNode::TreeNode(int data) : Node(data), leftChild_(nullptr), rightChild_(nullptr), parent(nullptr) {}

// Copy constructor
TreeNode::TreeNode(const TreeNode & node) {

}

// Destructor
TreeNode::~TreeNode() {
  // Delete left child then recursion
  if(leftChild_ != nullptr) {
    delete leftChild_;
  }
  // Delete right child then recursion
  if(rightChild_ != nullptr) {
    delete rightChild_;
  }
}
