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
  }
}

int main(){
  // Create bst and rbt
  BinarySearchTree* bst = new BinarySearchTree();
  RedBlackTree* rbt = new RedBlackTree();
  
  readFileToTree("data.txt", bst);
  readFileToTree("data.txt", rbt);

  // Print root node value
  std::cout << "Root value: " << bst->getRoot()->getValue() << std::endl;

  // Print tree starting at root node
  bst->print(bst->getRoot());

  // Create bst copy
  BinarySearchTree* bstCopy = bst;

  // Print copied tree starting at root node
  bstCopy->print(bstCopy->getRoot());

  return 0;
}
