// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "card.h"
#include "standardDeck.h"
#include "NonStandardDeck.h"

#include <string>
#include <iostream>

// Helper function to deal out the battleground to players
void dealBattleground(Deck* & battleground, Deck* & player1, Deck* & player2){
	// Boolean to switch between dealing to each player
	bool dealswitch = true;
	// Loop until battleground has no cards left
	while(battleground->getNumCards() > 0){
		// Take card from top of battleground deck
		Card dealtcard = battleground->dealCard();
		// Deal to player one if dealswitch true, player two if false
		dealswitch ? player1->addCard(dealtcard) : player2->addCard(dealtcard);
		// Invert dealswitch to swap next deal
		dealswitch = !dealswitch;
	}

}

// Help function returns true if there is a tie
bool tiecheck(bool winnerswitch, Deck* & player1, Deck* & player2, std::string matchface){
	// Tracks the winner's and loser's deck
	// Default to player1 winning
	Deck* windeck = player1;
	Deck* losedeck = player2;

	// Swap winner and loser decks if winnerswitch is false, meaning player two won
	if(!winnerswitch){
		windeck = player2;
		losedeck = player1;
	}
	// Tie case 1
	// Compare match's face value to that of losing player's top card, 
	// if the face of the match is equal to either of the two cards then there is a tie
	if(losedeck->getCard(losedeck->getNumCards() - 1).getFace() == matchface){
		// Print tie
		// std::cout << "Tie case 1 occurred" << std::endl;

		// Tie occurred return true
		return true;
	}
	// Tie case 2
	// Winning player has three cards of the same face value in the 1st 2nd and 4th position
	// and the losing player has the fourth of the same face value in their 2nd position
	// 
	// We know the winning player has a matching face in 1st and 2nd position already
	// because those two matchface value cards are on top of the battle they won
	if(windeck->getCard(windeck->getNumCards() - 4).getFace() == matchface 
		&& losedeck->getCard(losedeck->getNumCards() - 2).getFace() == matchface){
		// Print tie
		// std::cout << "Tie case 2 occurred" << std::endl;

		// Tie occurred return true
		return true;

	}

	// Return false if no ties are found
	return false;
}

int main(){
	// Print games deck type
	std::cout << "***** NONSTANDARD DECK 50 GAMES ****" << std::endl;

	// Create player and battleground decks for nonstandard game
	Deck* p1 = new NonStandardDeck();
	Deck* p2 = new NonStandardDeck();
	Deck* bg = new NonStandardDeck();

	// Track player total scores and games won
	int p1sum = 0, p2sum = 0, p1wincount = 0, p2wincount = 0;

	// Number of games to be played
	int numgames = 50;

	// Loop game numgames number of times
	for(int i = 0; i < numgames; i++){
		//std::cout << "Game " << std::to_string(i+1) << "\n" << std::endl;
		// True for player one, false for player two
		bool playerswitch = true;
		
		// Bool to keep ties from infinitely looping
		bool tie = false;

		// Fills and shuffles battleground deck
		bg->initializeDeck();
		bg->shuffle();

		// Empty player decks
		p1->removeCards(p1->getNumCards());
		p2->removeCards(p2->getNumCards());

		// Deals out cards from battleground to each player
		dealBattleground(bg, p1, p2);

		// Print pre-game player decks
		// std::cout << "Player one and two pre-game decks\n" << std::endl;
		// p1->printDeck();
		// p2->printDeck();

		// Play until someone is out of cards
		while(!p1->isEmpty() && !p2->isEmpty() && !tie){
			//std::cout << "Beginning game" << std::endl;
			// Tracks the previously played card in the battleground deck
			Card lastcard(0,0);

			// Tracks the most recently played card in the battleground deck
			Card playcard(0,0);
			
			// Play a new first card based on whose turn it is
			playerswitch ? playcard = p1->dealCard() : playcard = p2->dealCard();

			// Add card to battleground
			bg->addCard(playcard);

			// Tracks if a match was made
			bool matchfound = false;
			
			// Play until a match or a player runs out of cards in their deck
			while(!matchfound && !p1->isEmpty() && !p2->isEmpty()){
				// Set last played card to the current top battleground card
				lastcard = playcard;

				// Alternates player boolean
				playerswitch = !playerswitch;

				// Play a new card based on whose turn it is
				playerswitch ? playcard = p1->dealCard() : playcard = p2->dealCard();

				// Add new playcard to battleground
				bg->addCard(playcard);

				// Print most recently played card and last card's suit and face values
				// std::cout << "playcard: " << playcard->print() << " lastcard: " << lastcard->print() << std::endl;

				// Check for a matching face value between the two
				// last played cards
				if(playcard.getFace() == lastcard.getFace()) {matchfound = true;}
			}

			// Run if there was a match
			if(matchfound) {
				// Prints bg deck for debugging
				// std::cout << "Transferring following bg deck" << std::endl;
				// bg->printDeck();
				
				// Transfer battleground to winning player's deck
				playerswitch ? bg->transferCards(*p1) : bg->transferCards(*p2);

				// Print player decks
				// p1->printDeck();
				// p2->printDeck();

				// Stores face of the matching cards
				std::string matchface = playcard.getFace();

				// Returns true if tie occurred
				tie = tiecheck(playerswitch, p1, p2, matchface);

				
			}

			// Check if game is over after checking for ties and wars
			if(p1->isEmpty() || p2->isEmpty()){
				// Alternate switch when game is over because
				// whoever played last is the player that
				// ran out of cards
				playerswitch = !playerswitch;

			}
		}
	
		/*Prints all decks after each game with labels
		std::cout << "Player 1 Deck:" << std::endl;
		p1->printDeck();
		std::cout << "Player 2 Deck:" << std::endl;
		p2->printDeck();
		std::cout << "Battleground Deck:" << std::endl;
		bg->printDeck();
		playerswitch ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;
		*/

		// In a tie, player with more cards gets the win
		if(tie){
			if(p1->getNumCards() > p2->getNumCards()){
				p1sum += p1->getNumCards();
				p1wincount++;
			}else{
				p2sum += p2->getNumCards();
				p2wincount++;	
			}
		}else{
			// Playerswitch decides who the winner is, true for player one, false for player two
			if(playerswitch){
				// Print info about win
				// std::cout << "Player 1 won with " << std::to_string(p1->getNumCards()) << " cards" << std::endl;

				// Increase sums for score and win count
				p1sum += p1->getNumCards();
				p1wincount++;
			}else{
				// Print info about win
				//std::cout << "Player 2 won with " << std::to_string(p2->getNumCards()) << " cards" << std::endl;

				// Increase sums for score and win count
				p2sum += p2->getNumCards();
				p2wincount++;
			}
		}
	}

	// Print game win counts
	if(p1wincount > p2wincount)
		std::cout << "Player 1 was the champion, winning " << std::to_string(p1wincount) << " games\n" << std::endl;
	else
		std::cout << "Player 2 was the champion, winning " << std::to_string(p2wincount) << " games\n" << std::endl;

	// Print average scores
	std::cout << "Player 1 had an average score of " << std::to_string(p1sum / p1wincount) << " cards" << std::endl;
	std::cout << "Player 2 had an average score of " << std::to_string(p2sum / p2wincount) << " cards" << std::endl;

	delete p1;
	delete p2;
	delete bg;

	/*************** StandardDeck Games **************/

	// Print games type
	std::cout << "***** STANDARD DECK 50 GAMES ****" << std::endl;

	// Create player and battleground decks for nonstandard game
	p1 = new StandardDeck();
	p2 = new StandardDeck();
	bg = new StandardDeck();

	// Track player total scores and games won
	p1sum = p2sum = p1wincount = p2wincount = 0;

	// Number of games to be played
	numgames = 50;

	// Loop game numgames number of times
	for(int i = 0; i < numgames; i++){
		//std::cout << "Game " << std::to_string(i+1) << "\n" << std::endl;
		// True for player one, false for player two
		bool playerswitch = true;
		
		// Bool to keep ties from infinitely looping
		bool tie = false;

		// Fills and shuffles battleground deck
		bg->initializeDeck();
		bg->shuffle();

		// Empty player decks
		p1->removeCards(p1->getNumCards());
		p2->removeCards(p2->getNumCards());

		// Deals out cards from battleground to each player
		dealBattleground(bg, p1, p2);

		// Print pre-game player decks
		// std::cout << "Player one and two pre-game decks\n" << std::endl;
		// p1->printDeck();
		// p2->printDeck();

		// Play until someone is out of cards
		while(!p1->isEmpty() && !p2->isEmpty() && !tie){
			//std::cout << "Beginning game" << std::endl;
			// Tracks the previously played card in the battleground deck
			Card lastcard(0,0);

			// Tracks the most recently played card in the battleground deck
			Card playcard(0,0);
			
			// Play a new first card based on whose turn it is
			playerswitch ? playcard = p1->dealCard() : playcard = p2->dealCard();

			// Add card to battleground
			bg->addCard(playcard);

			// Tracks if a match was made
			bool matchfound = false;
			
			// Play until a match or a player runs out of cards in their deck
			while(!matchfound && !p1->isEmpty() && !p2->isEmpty()){
				// Set last played card to the current top battleground card
				lastcard = playcard;

				// Alternates player boolean
				playerswitch = !playerswitch;

				// Play a new card based on whose turn it is
				playerswitch ? playcard = p1->dealCard() : playcard = p2->dealCard();

				// Add new playcard to battleground
				bg->addCard(playcard);

				// Print most recently played card and last card's suit and face values
				// std::cout << "playcard: " << playcard->print() << " lastcard: " << lastcard->print() << std::endl;

				// Check for a matching face value between the two
				// last played cards
				if(playcard.getFace() == lastcard.getFace()) {matchfound = true;}
			}

			// Run if there was a match
			if(matchfound) {
				// Prints bg deck for debugging
				// std::cout << "Transferring following bg deck" << std::endl;
				// bg->printDeck();
				
				// Transfer battleground to winning player's deck
				playerswitch ? bg->transferCards(*p1) : bg->transferCards(*p2);

				// Print player decks
				// p1->printDeck();
				// p2->printDeck();

				// Stores face of the matching cards
				std::string matchface = playcard.getFace();

				// Returns true if tie occurred
				tie = tiecheck(playerswitch, p1, p2, matchface);

				
			}

			// Check if game is over after checking for ties and wars
			if(p1->isEmpty() || p2->isEmpty()){
				// Alternate switch when game is over because
				// whoever played last is the player that
				// ran out of cards
				playerswitch = !playerswitch;

			}
		}
	
		/*Prints all decks after each game with labels
		std::cout << "Player 1 Deck:" << std::endl;
		p1->printDeck();
		std::cout << "Player 2 Deck:" << std::endl;
		p2->printDeck();
		std::cout << "Battleground Deck:" << std::endl;
		bg->printDeck();
		playerswitch ? std::cout << "True" << std::endl : std::cout << "False" << std::endl;
		*/

		// In a tie, player with more cards gets the win
		if(tie){
			if(p1->getNumCards() > p2->getNumCards()){
				p1sum += p1->getNumCards();
				p1wincount++;
			}else{
				p2sum += p2->getNumCards();
				p2wincount++;	
			}
		}else{
			// Playerswitch decides who the winner is, true for player one, false for player two
			if(playerswitch){
				// Print info about win
				// std::cout << "Player 1 won with " << std::to_string(p1->getNumCards()) << " cards" << std::endl;

				// Increase sums for score and win count
				p1sum += p1->getNumCards();
				p1wincount++;
			}else{
				// Print info about win
				//std::cout << "Player 2 won with " << std::to_string(p2->getNumCards()) << " cards" << std::endl;

				// Increase sums for score and win count
				p2sum += p2->getNumCards();
				p2wincount++;
			}
		}
	}

	// Print game win counts
	if(p1wincount > p2wincount)
		std::cout << "Player 1 was the champion, winning " << std::to_string(p1wincount) << " games\n" << std::endl;
	else
		std::cout << "Player 2 was the champion, winning " << std::to_string(p2wincount) << " games\n" << std::endl;

	// Print average scores
	std::cout << "Player 1 had an average score of " << std::to_string(p1sum / p1wincount) << " cards" << std::endl;
	std::cout << "Player 2 had an average score of " << std::to_string(p2sum / p2wincount) << " cards" << std::endl;

	// Deconstruct decks to free memory
	delete p1;
	delete p2;
	delete bg;

	return 0;
}
