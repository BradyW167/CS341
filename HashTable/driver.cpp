#include <fstream>
#include <iostream>
#include <string>

#include "DoubleLinkedList.h"
#include "HashEntry.h"

int main(){
	DoubleLinkedList* dll = new DoubleLinkedList(); // Create list to store data

  std::ifstream dataFile("dictionary.txt");

  if (!dataFile) {
      std::cerr << "Failed to open data file\n";
      return 1;
  }

  std::string line = ""; // Stores a line of text from the input file

  // Loop through each line in file and store it in line
  while (std::getline(dataFile, line)) {
    size_t commaPos = line.find(','); // Get position of ','

    // Split line into key and value strings
    std::string stringKey = line.substr(1, commaPos);
    std::string stringValue = line.substr(commaPos + 1, line.size() - 1);

    // Convert strings to integers
    int key = std::stoi(stringKey);
    int value = std::stoi(stringValue);

    dll->insert(HashEntry(key, value));
  }

	dll->printList();

	delete dll;

	return 0;
}
