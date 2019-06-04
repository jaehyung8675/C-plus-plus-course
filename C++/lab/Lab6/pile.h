#ifndef PILE_H
#define PILE_H

#include "card.h"

#include <stack>
#include <vector>

using namespace std;

#define MAXCARDS 52 // set maxium 52 cards 

class Pile{

public:

	Pile(); // constructor pile 
	
	void AddCardToPile(Card * card); // add card to pile
	
	Card * RemoveTopCard(); // take out one card from the pile
	
	int GetNumCards(); // get number cards

	void Shuffle(); // put random nunber and swap cards
	
	void PrintCards(); // display cards

private:

	void PrintStack( stack<Card*> ); // print stack of cards
	stack<Card *> cards; // stack of card pointers
	int numCards; // initialize number of cards
		
};

#endif