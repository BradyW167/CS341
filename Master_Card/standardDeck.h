// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#define DECK_SIZE 52

#include "card.h"
#include "deck.h"

#include <iostream>
#include <string>
#include <utility> // std::swap for shuffle
#include <chrono> // time functions for random seed
#include <random> // rand functions for shuffle
#include <algorithm> // Max function for merging decks

class StandardDeck : public Deck {
	public:
		// Default constructor.
		StandardDeck();
		
		// Default destructor.
		~StandardDeck();

		// Merges input deck with current deck
		// Boolean indicates whether or not to shuffle
		bool mergeDecks(StandardDeck &, bool = false);
		
		// Initializes standard deck
		void initializeDeck() override;
};

#endif
