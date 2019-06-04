#include <iostream>
#include <stdlib.h> // srand, rand
#include "pile.h"

#include <stack>

using namespace std;

Pile::Pile(){ // constructor pile
	numCards = 0;
}

void Pile::AddCardToPile(Card * card){ // adds a card to the stack	
	cards.push( card ); // push card to cards's stack
	numCards = cards.size(); // assign the number of cards
}

Card * Pile::RemoveTopCard(){ // removes a card from the stack
	Card * cardToReturn = cards.top(); // assign the top card on temp card pointer
	cards.pop(); // take out card
	numCards = cards.size(); // assign the size of card
	return cardToReturn;
}

int Pile::GetNumCards(){ // get number of cards
	return numCards; 
}

void Pile::Shuffle(){
	// put card into temp vector
	vector<Card *> temp; 
	for(int i = 0; i < numCards; i++){
		temp.push_back( cards.top() );
		cards.pop();
	}
	// do random swaps
	int n = MAXCARDS * 2;
	for(int j = 0; j < n; j++){
		int c1 = rand() % numCards;
		int c2 = rand() % numCards;
		Card * t = temp[c1];
		temp[c1] = temp[c2];
		temp[c2] = t;
	}
	// push back card to swaped card
	for(int p = 0; p < numCards; p++){
		cards.push( temp[p] );
	}
}

void Pile::PrintCards(){ // display number cards
	cout << "There are " << numCards << " cards in the pile." << endl;
	PrintStack( cards );
}

void Pile::PrintStack( stack<Card*> cards ){ // print out each card
	for( int i = 0; i < numCards; i++ ){
		Card* card = cards.top();
		cout << "Card " << ( i + 1 ) << ", " << card -> GetRankString() << " of " << card -> GetSuitString() << "s" << endl;
		cards.pop();
	}
}