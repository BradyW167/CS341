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
  // Create bst and rbt
  //BinarySearchTree* bst = new BinarySearchTree();
  RedBlackTree* rbt = new RedBlackTree();
  
  //readFileToTree("data.txt", bst);
  readFileToTree("data.txt", rbt);
  
  /*
  std::cout << "***** BST TESTING *****" << std::endl;
  // Print root node value
  std::cout << "Root value: " << bst->getRoot()->getValue() << std::endl;

  // Print tree starting at root node
  bst->print(bst->getRoot());
  std::cout << std::endl;

  // Create bst copy
  BinarySearchTree* bstCopy = bst;

  // Print copied tree starting at root node
  bstCopy->print(bstCopy->getRoot());
  std::cout << std::endl;

  std::cout << "Tree Height: " << bst->getHeight(bst->getRoot()) << std::endl;

  // Delete trees
  delete bst;
  delete bstCopy;
  */

  std::cout << "\n***** RBT TESTING *****" << std::endl;

  std::cout << "Root value: " << rbt->getRoot()->getValue() << std::endl;

  // Print tree starting at root node
  rbt->print(rbt->getRoot());

  // Print red and black nodes
  rbt->printRedNodes(rbt->getRoot());
  rbt->printBlackNodes(rbt->getRoot());

  // Delete tree
  delete rbt;

  return 0;
}
