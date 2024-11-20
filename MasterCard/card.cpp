// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// bwerling

#include "card.h"
#include <string>
#include <iostream>

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card(){
	initialize(0,0); // Default initialize cards as no suit jokers
}

Card::Card(int suit, int face){
	if(validate(suit, face)){
		// Initialize valid card
		//std::cout << "Valid Suit: " << std::to_string(suit) << " Suit: " << std::to_string(face) << std::endl;
		initialize(suit, face);
	}else{
		std::cout << "Initializing invalid card with suit index (" << std::to_string(suit) << ") and face index (" << std::to_string(face) << ")" << std::endl;
		initialize(suit, face);
	}
}

Card::~Card(){}

std::string Card::getSuit(){
	return SUIT[suitVal_];
}

std::string Card::getFace(){
	return FACE[faceVal_];
}

void Card::setSuit(int suit){
	suitVal_ = suit;
}

void Card::setFace(int face){
	faceVal_ = face;
}


// Print full name of card as string (e.g., "Ace of Spades")
std::string Card::print(){
	if(validate(suitVal_, faceVal_)){
		return FACE[faceVal_] +  " of " + SUIT[suitVal_];
	}else{
		return "INVALID CARD";
	}
}

bool Card::validate(int s, int f){
	bool valid = true;
	if(s < 0 || s > 4){
		std::cout << "Suit index value (" << std::to_string(s) << ") invalid" << std::endl;
		valid = false;
	}
	// Check for invalid face value and print if so
	if(f < 0 || f > 13){
		std::cout << "Face index value (" << std::to_string(f) << ") invalid" << std::endl;
		valid = false;
	}
	return valid;
}

void Card::initialize(int sInit, int fInit){
	setSuit(sInit);
	setFace(fInit);
}
