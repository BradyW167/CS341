// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#ifndef NON_STANDARD_DECK_H
#define NON_STANDARD_DECK_H

#include "card.h"
#include "deck.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class NonStandardDeck : public Deck {
	public:
		// Default constructor.
		NonStandardDeck();

		// Constructor for deck with input size
		NonStandardDeck(int size);
		
		// Default destructor.
		~NonStandardDeck();

		// Initializes deck
		void initializeDeck() override;
};

#endif
