#ifndef PILE_H
#define PILE_H

#include <string>
#include "Card.h"

class Pile {
    
    public:
        Pile(); // initialize array of cards to put each card value and suit 
        
        void fullDeck(); // craete 52 cards on the pile

        void AddCardToPile(Card * card); // add card to pile

        Card * RemoveTopCard(); // take out one card from the pile

        int GetNumCards(); // get number cards

        void Shuffle(); // put random nunber and swap cards

        bool isEmpty(); // function to check pile is empty or not
        
        // print out cards and each player cards
        void PrintCards(); 
        void PrintOneCard( Pile p );

    private:
   
        Card * cards[52]; // an array of card pointers
        int numCards;
};

#endif
