// Try to recolor before rotating
// Look at parent, grandparent, and uncle nodes for recoloring

/* 1: Root is null (first node in tree), set node to black and return
 * 2: Tree root is red, color it black
 * 3: Node, parent, and uncle are red, bring blackness down from grandparent, balanceColor(great grandparent, grandparent)
 * 4: Node and parent are red, node is left child parent is left child, leftRotate(parent, node) and rightRotate(newparent, newnode) and recolor new parent to black and new right sibling to red
 * 5: Node and parent are red, node is right child parent is left child, rightRotate(grandparent, parent) and recolor new parent to black and new right sibling to red
 * 6: Node and parent are red, node is left child parent is right child, rightRotate(parent, node) and leftRotate(newparent, newnode) and recolor new parent to black and new left sibling to red
 * 7: Node and parent are red, node is right child parent is right child, leftRotate(grandparent, parent) and recolor new parent to black and new left sibling to red
*/

// Steps 3-7
if(root->isRed() && node->isRed()) {
  // Root is left child
  if(root == root->getParent->getLeftChild()) {
      // Uncle is red
      if(root->getParent->getRightChild->isRed()) {
          // Push Blackness down and balanceColor(great grand, grand)
      // Node is left child
      }else if(node == root->getLeftChild()){
        rightRotate(grandpa, parent);
      // Node is right child
      }else if(node == root->getRightChild()) {

      }
  // Root is right child
  }else if(root == root->getParent->getRightChild()) {

  }
}

// Step 1
if(root == nullptr) {
  newNode->setBlack;
}

// Step 2
if(getRoot()->isRed()) {getRoot()->setRed();}

if(root->isRed() && newNode->isRed()) {
    std::cout << "Two red nodes detected" << std::endl;

    // If root is left child...
    if(root == root->getParent()->getLeftChild()) {
      std::cout << "Root is left child" << std::endl;

      // If new node is left child...
      if(newNode = root->getLeftChild()) {
        TreeNode* parent = root->getParent(); // Get lvalue for root's parent
        rotateRight(parent, root); // Rotate root to its' parent
      }
      // If new node is right child...
      else if(newNode == root->getRightChild()) {
        rotateLeft(root, newNode); // Rotate newNode to its' root
        TreeNode* parent = newNode->getParent(); // Get lvalue for newNode's parent
        rotateRight(parent, newNode); // Rotate newNode to its' parent
      }
    }
  // If root is right child
  }else if (root->getParent() != nullptr && root == root->getParent()->getRightChild()) {
    std::cout << "Root is right child" << std::endl;

    // If new node is left child...
    if(newNode == root->getLeftChild()) {
      rotateRight(root, newNode); // Rotate newNode to its' root
      TreeNode* parent = newNode->getParent(); // Get lvalue for newNode's parent
      rotateLeft(parent, newNode); // Rotate newNode to it's parent
    }
    // If new node is right child...
    else if(newNode == root->getRightChild()) {
      TreeNode* parent = root->getParent(); // Get lvalue for root's parent
      rotateLeft(parent, root); // Rotate root to its' parent
    }
  }

