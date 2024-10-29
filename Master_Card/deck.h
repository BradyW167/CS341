// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#ifndef DECK_H
#define DECK_H

#define DEFAULT_SIZE 52

#include "card.h"
#include <iostream>
#include <string>
#include <utility> // std::swap for shuffle
#include <chrono> // time functions for random seed
#include <random> // rand functions for shuffle

class Deck
{
	public:
		// Default constructor.
		Deck();

		// Constructor for deck with input size
		Deck(int size);
		
		// Default destructor.
		virtual ~Deck();

		// Initializes deck
		// Must be implemented in derived class
		virtual void initializeDeck() = 0;
		
	     	// Returns True/False if Deck is empty
		bool isEmpty();	
	     
		// Returns the number of cards left in the deck
		int getNumCards();

	     	// Displays the i'th card in the Deck
		void displayCard(int);

	     	// Prints the contents of the Deck 
		void printDeck();

		// Adds card c to deck and returns true if successful
		bool addCard(Card c);

		// Removes a card from the deck at given index
		void removeCard(int);
		
		// Removes int number of cards from top of deck
		// Removes all cards by default
		void removeCards(int);
		
		// Return the top card from the deck and deletes it
		Card dealCard();

		// Return card at given index
		Card getCard(int);

		// Transfers all cards from this deck to another
		// from the parameter
		void transferCards(Deck&);

		// Randomizes deck with three sorts
		void shuffle();


	protected: 
		Card* deck_; // Pointer to array of cards
		int numCards_;	// Stores current number of cards in deck
		int size_; // Stores size of deck array
};

#endif
