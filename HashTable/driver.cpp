#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "DoubleLinkedList.h"
#include "HashEntry.h"
#include "HashTableArray.h"

int main(){
  HashTableArray* table = new HashTableArray(6);

  std::ifstream dataFile("duplicates.txt");

  if (!dataFile) {
      std::cerr << "Failed to open data file\n";
      return 1;
  }

  std::string line = ""; // Stores a line of text from the input file

  // Loop through each line in file and store it in line
  while (std::getline(dataFile, line)) {
    std::stringstream ss(line); // Open stringstream with line input

    int key = 0, value = 0; // Split line into key and value strings

    ss >> key >> value; // Read number values from string stream into key and value

    table->insert(key, value); // Insert hash entry into hash table with key-value input
  }

	table->print();

	delete table;

	return 0;
}
