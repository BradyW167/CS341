// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "NonStandardDeck.h"

// Default constructor
NonStandardDeck::NonStandardDeck(): Deck() {}

// Constructor for deck with input size
NonStandardDeck::NonStandardDeck(int s): Deck(s) {}

//Default destructor
NonStandardDeck::~NonStandardDeck() {delete[] deck_;}

void NonStandardDeck::initializeDeck(){
	// If not empty, reset the deck
	if(!isEmpty()) {removeCards(size_);}

	// Read input file
	std::ifstream inputfile("deck.txt");

	if(inputfile.is_open()){
		// String to store each line
		std::string line;

		// Get first line of file for deck size	
		std::getline(inputfile, line);
		// Prints the size of the deck
		// std::cout << "Deck Size: " << line << std::endl;

		// Set deck size
		size_ = std::stoi(line);

		while(std::getline(inputfile, line)){
			// Store numbers for card initialization
			int suit = 0, face = 0;

			// String to store text from lines
			std::string token = "";

			// Read individual lines with input stringstream
			std::istringstream ss(line);
			
			// Read suit and face values and convert them to ints
			std::getline(ss, token, ' ');
			suit = std::stoi(token);
			std::getline(ss, token);
			face = std::stoi(token);

			// Print suit and face for card
			// std::cout << "Face: " << std::to_string(face) << " Suit: " << std::to_string(suit) << std::endl;

			// Create and add card to deck
			Card c(suit, face);
			addCard(c);
		}
	}else{
		std::cout << "deck.txt file could not be opened" << std::endl;
	}
	
	// Close custom deck file reader
	inputfile.close();
}
