// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "BinarySearchTree.h"
#include "RedBlackTree.h"

void readFileToTree(std::string fileName, BinarySearchTree* tree) {
  std::ifstream file(fileName);
  std::string line = "";

  // Check if file is open
  if(file.is_open()){
    // Get first line from file
    std::getline(file, line);

    // Initialize input string stream with first line
    std::istringstream iss(line);

    // Stores the current number
    int num = 0;

    // Loop until there are no more tokens
    // Create node and insert into tree
    while(iss >> num) {
      std::cout << "Inserting " << num << " into tree" << std::endl;
      tree->insert(num);
    }
    file.close();
  }
}

int main(){
  std::cout << "***** BINARY SEARCH TREE *****" << std::endl;

  BinarySearchTree* bst = new BinarySearchTree(); // Initialize binary search tree

  readFileToTree("data.txt", bst); // Read data file into the tree

  std::cout << "\nRoot value: " << bst->getRoot()->getValue() << std::endl; // Print root node value

  // Print tree starting at root node
  bst->print(bst->getRoot());
  std::cout << std::endl;

  std::cout << "\nTree Height: " << bst->getHeight(bst->getRoot()) << std::endl; // Print height of tree

  BinarySearchTree* bstCopy = new BinarySearchTree(*bst); // Create bst copy

  // Print copied tree starting at root node
  std::cout << "\nPrinting copied binary search tree..." << std::endl;
  bstCopy->print(bstCopy->getRoot());
  std::cout << std::endl;

  // Delete binary search trees
  delete bst;
  delete bstCopy;

  std::cout << "\n***** RED BLACK TREE *****" << std::endl;

  RedBlackTree* rbt = new RedBlackTree();

  readFileToTree("data.txt", rbt); // Read data file into the tree

  std::cout << "\nRoot value: " << rbt->getRoot()->getValue() << std::endl;

  // Print tree starting at root node
  std::cout << "\nPrinting tree..." << std::endl;
  rbt->print(rbt->getRoot());
  std::cout << std::endl;

  // Print red and black nodes
  std::cout << "\nPrinting red nodes inorder..." << std::endl;
  rbt->printRedNodes(rbt->getRoot());
  std::cout << std::endl;

  std::cout << "\nPrinting black nodes preorder..." << std::endl;
  rbt->printBlackNodes(rbt->getRoot());
  std::cout << std::endl;

  RedBlackTree* rbtCopy = new RedBlackTree(*rbt); // Create rbt copy

  /* Print copied tree starting at root node
  std::cout << "\nPrinting copied red black tree..." << std::endl;
  rbtCopy->print(rbtCopy->getRoot());
  std::cout << std::endl;

  // Print red and black nodes
  std::cout << "\nPrinting red nodes inorder..." << std::endl;
  rbtCopy->printRedNodes(rbtCopy->getRoot());
  std::cout << std::endl;

  std::cout << "\nPrinting black nodes preorder..." << std::endl;
  rbtCopy->printBlackNodes(rbtCopy->getRoot());
  std::cout << std::endl;
  */

  // Delete red black trees
  delete rbt;
  delete rbtCopy;

  return 0;
}
