// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "standardDeck.h"

// Default constructor
StandardDeck::StandardDeck(): Deck(DECK_SIZE) {}

//Default destructor
StandardDeck::~StandardDeck() {delete[] deck_;}

bool StandardDeck::mergeDecks(StandardDeck & mergeDeck, bool toShuffle){
	std::cout << "Merging decks" << std::endl;
	// Check if deck is full
	if(numCards_ != DECK_SIZE){
		// Stores number of cards available to merge into this deck
		int numOpen = DECK_SIZE - numCards_;
		// Stores the index of the last card in the mergedDeck card array
		int mergeIndex = mergeDeck.numCards_ - 1;

		// Decides lower index based on which is smaller, the number
		// of open cards in this deck or the number of cards being
		// added from the mergeDeck
		int lowerIndex = std::max(mergeIndex - numOpen, mergeIndex - mergeDeck.numCards_);

		// Loop decrements mergeIndex from top of mergeDeck card array
		// until there are no open spots left in this card array
		for(int i = mergeIndex; i > lowerIndex; i--){
			// Get card from top of mergeDeck to transfer
			Card toadd = mergeDeck.deck_[i];
			
			// Prints the face and suit of the card being added
			// std::cout << "Merging card: " << toadd.print() << std::endl;

			// Adds card
			addCard(toadd);
			// Removes card from mergeDeck after merging into this deck
			mergeDeck.removeCard(mergeIndex);
		}
		// Shuffle deck if toShuffle is true
		if(toShuffle){shuffle();}

		// Return true on successful merge
		//std::cout << "Merge successful" << std::endl;
		return true;
	}
	//std::cout << "This deck is full, failed merge" << std::endl;
	// Return false on failed merge
	return false;
}

void StandardDeck::initializeDeck(){
	// If not empty, reset the deck
	if(!isEmpty()) {removeCards(DECK_SIZE);}

	// Loops through the four suits
	for(int i = 1; i < 5; i++){
		// Loops through the 13 face values
		for(int j = 1; j < 14; j++){
			// Create card of each suit and face as in a standard deck
			Card c(i,j);
			// Add card to deck
			addCard(c);
		}
	}
}
