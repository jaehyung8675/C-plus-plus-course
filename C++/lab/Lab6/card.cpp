#include "card.h"

Card::Card(){ 
	// constructor card with two parameters
	this->suit = -1;
	this->rank = -1;
}

// setter function definition
void Card::SetSuitAndRank(int suit, int rank){
	this->suit = suit;
	this->rank = rank;
}

// getter RankString functions definition
const char * Card::GetRankString(){
	switch(this->rank){
		case TWO:
			return "two";
		case THREE:
			return "three";
		case FOUR:
			return "four";
		case FIVE:
			return "five";
		case SIX:
			return "six";
		case SEVEN:
			return "seven";
		case EIGHT:
			return "eight";
		case NINE:
			return "nine";
		case TEN:
			return "ten";
		case JACK:
			return "jack";
		case QUEEN:
			return "queen";
		case KING:
			return "king";
		case ACE:
			return "ace";
		default:
			return "error";
	}
}

int Card::GetRank(){ return rank; }

// getter SuitString functions definition
const char * Card::GetSuitString(){
	switch(this->suit){
		case HEART:
			return "heart";
		case DIAMOND:
			return "diamond";
		case SPADE:
			return "spade";
		case CLUB:
			return "club";
		default:
			return "error";
	}
}

int Card::GetSuit(){ return suit; }