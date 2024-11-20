// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "deck.h"

// Default constructor
Deck::Deck(): Deck(DEFAULT_SIZE) {}

// Create deck of input size
Deck::Deck(int size): deck_(new Card[size]), numCards_(0), size_(size) {}

//Default destructor
Deck::~Deck(){}

bool Deck::isEmpty(){
	// Deck is not empty if there are more than 0 cards
	return numCards_ > 0 ? false : true;
}

int Deck::getNumCards(){
	return numCards_;
}

void Deck::displayCard(int i){
	Card dcard = deck_[i-1];
	std::cout << "Card " << std::to_string(i) << ": " << dcard.print() << std::endl;
}

void Deck::printDeck(){
	// std::cout << "Printing deck" << std::endl;
	for(int i = 0; i < numCards_; i++){
		displayCard(i+1);
	}
}

// Adds card to deck if possible
bool Deck::addCard(Card newc){
	// Check if there is room for a new card
	if(numCards_ < size_){
		// Set new top card to be input card
		deck_[numCards_] = newc;
		// Increment card counter
		numCards_++;
		return true;
	}
	std::cout << "Cannot add card " << newc.print() << " at index " << numCards_ << " to deck of size " << std::to_string(size_) << std::endl;
	return false;
}

void Deck::removeCard(int i){
	// "Remove" card by resetting its' values to default
	deck_[i].initialize(0,0);
	// Decrement card counter
	numCards_--;
}

void Deck::removeCards(int numdelete){
	// No work to be done if deck empty
	if(isEmpty()) {return;}

	// Use another variable to track number of cards since
	// numCards_ will change as cards are removed
	int ncards = numCards_;

	// If number of cards to be deleted is greater than the 
	// number of cards in this deck, delete the number
	// of cards in the deck
	if(numdelete > ncards) {numdelete = ncards;}

	// Loops through index of deck beginning at the top
	for(int i = ncards - 1; i >= ncards - numdelete; i--){
		removeCard(i);
	}
}

Card Deck::dealCard(){
	// Stores card at top of this deck
	Card topCard = deck_[numCards_ - 1];
	// Removes dealt card
	removeCard(numCards_ - 1);
	// Returns the card dealt
	return topCard;
}

Card Deck::getCard(int cardindex){
	return deck_[cardindex];
}

void Deck::transferCards(Deck& receivedeck){
	// Return if no cards to transfer
	if(numCards_ == 0) return;

	// Use another variable to track number of cards since
	// numCards_ will change as cards are removed
	int ncards = numCards_;

	// Loop through this entire deck
	for(int i = 0; i < ncards; i++){
		// Take card from bottom of this deck
		Card transfercard = deck_[i];
		// Remove card from this deck
		removeCard(i);
		// Add card to the receiving deck
		receivedeck.addCard(transfercard);
	}
}

/* 
 * Shuffle method originally from
 * https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
 */
void Deck::shuffle(){
	// Repeats random sort three times
	for(int k = 0; k < 3; k++){
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		srand(seed);
		for (int i = numCards_ - 1; i > 0; i--) { 
			// Pick a random index from 0 to i 
			int j = rand() % (i + 1);

			// Swap current card i with random card j
			std::swap(deck_[i], deck_[j]);
		}
	}
}


