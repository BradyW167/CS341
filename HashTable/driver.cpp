#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "DoubleLinkedList.h"
#include "HashEntry.h"
#include "HashTableArray.h"

// Loops until a number between [min, max] is input
// Defaults to no maximum value
int getValidInput(std::string prompt, int min, int max = 0) {
  int num = 0; // Stores user input number (supposed)

  // Loop infinitely, break when input is valid
  while (true) {
    std::cout << "\n" << prompt;

    std::cin >> num;

    // If there is no maximum value...
    if (max == 0) {
      if (std::cin.fail() || num < min) {
      std::cout << "\nInvalid option, please enter a number greater than or equal to " << min << std::endl; // Print invalid

      std::cin.clear(); // Clear input stream error flags

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
      }
      // Else input is valid, return it
      else {return num;}
    }
    // Else there is a maximum value
    else {
      // If input option is invalid...
      if (std::cin.fail() || num < min || num > max) {
        std::cout << "\nInvalid option, please enter a number between " << min << " and " << max << std::endl; // Print invalid

        std::cin.clear(); // Clear input stream error flags

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
      }
      // Else input is valid, return it
      else {return num;}
    }
  }
}

void readFileToTable(std::string fileName, HashTable* table) {
  std::ifstream dataFile(fileName);

  if (!dataFile) {
      std::cerr << "Failed to open data file\n";
      exit(1);
  }

  std::string line = ""; // Stores a line of text from the input file

  // Loop through each line in file and store it in line
  while (std::getline(dataFile, line)) {
    std::stringstream ss(line); // Open stringstream with line input

    int key = 0, value = 0; // Split line into key and value strings

    ss >> key >> value; // Read number values from string stream into key and value

    table->insert(key, value); // Insert hash entry into hash table with key-value input
  }
}

int main(){
  std::string fileName = "duplicates.txt"; // Stores file name to read entry data from

  HashTable* table = nullptr; // Declare hash table as nullptr

  int option = 0; // Stores user input numbers for commands

  int tableOption = 0; // Stores user input numbers for hash table commands

  int size = 0; // Stores user input for table size

  int key = 0; // Stores user input key for hash entry search and removal

  // Loop forever
  // Break condition is when option == 5
  while (true) {

    std::cout << "Welcome to Hash-a-lot" <<
      "\n1) Linear Probing" <<
      "\n2) Quadratic Probing" <<
      "\n3) Separate Chaining" <<
      "\n4) Cuckoo Hashing" <<
      "\n5) Quit" << std::endl;

    option = getValidInput("Please enter your choice: ", 1, 5); // Loops until user inputs a number 1-5

    // If creating a hash table (options 1-4)
    if (option == 1 || option == 2 || option == 3 || option == 4) {
      // If hash table already exists...
      if (table != nullptr) {
        delete table; // Delete existing hash table
        table = nullptr; // Reset pointer
      }

      size = getValidInput("Please enter hash table size: ", 1); // Loops until user inputs a number >= 1

      // If creating a linear probing hash table...
      if (option == 1) {
        table = new HashTableArray(size, true); // Create hash table

        readFileToTable(fileName, table); // Read input file's data into hash table
      }
      // If creating a quadratic probing hash table...
      else if (option == 2) {
        table = new HashTableArray(size, false); // Create hash table

        readFileToTable(fileName, table); // Read input file's data into hash table
      }
      // If creating a seperate chaining hash table...
      else if (option == 3) {

      }
      // If creating a cuckoo hash table...
      else if (option == 4) {

      }

      table->print();

      // Loop forever
      // Break condition is when option == 4
      while (true) {
        std::cout << "\n1) Search for entry" <<
          "\n2) Remove entry" <<
          "\n3) Print hash table" <<
          "\n4) Return to main menu" << std::endl;

        tableOption = getValidInput("Please enter your choice: ", 1, 4); // Loops until user inputs a number 1-4

        // If searching for an entry...
        if(tableOption == 1) {
          key = getValidInput("Search, please enter a key: ", 0); // Loops until user inputs a number >= 0

          int value = table->search(key); // Store returned value from search

          // If key was found (a value >= 0 was returned)..
          if (value >= 0) {
            std::cout << "\nKey: " << key << "  Value: " << value << std::endl;
          }
          // Else key was not found
          else {
            std::cout << "\nInvalid key,  " << key << " not found in table" << std::endl;
          }
        }
        // If removing an entry...
        else if (tableOption == 2) {
          key = getValidInput("Remove, please enter a key: ", 0); // Loops until user inputs a number >= 0

          table->remove(key);
        }
        // If printing the table...
        else if (tableOption == 3) {
          table->print();
        }
        // If returning to main menu...
        else if (tableOption == 4) {
          break; // Break from outer loop
        }
      }
    }
    // If quitting the program...
    else if (option == 5) {
      delete table; // Delete table dynamic array from heap
      break; // Break from outer loop
    }
  }

	return 0;
}
