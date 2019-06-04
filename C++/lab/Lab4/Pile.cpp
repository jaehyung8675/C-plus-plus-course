#include <iostream>

#include <stdlib.h> // srand, rand
#include <time.h> // time

#include "Card.h"
#include "Pile.h"

using namespace std;

Pile::Pile(){

    numCards = 0;

    // check each card on the cards
    // for(int i = 0; i < 52; i++){
    //     cout << (*cards[i]).getSuit() << " " << cards[i] -> getValue() << endl;
    // }
}

// function to create cards on one pile
void Pile::fullDeck(){

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            cards[numCards] = new Card((suit)i, (value)j);
            numCards++;
        }
    }
}

// function
void Pile::Shuffle(){

    srand (time(NULL)); // initialize random seed
    
    for(int i = 0; i < numCards; i++){
        
        int randomNumber = i + (rand() % (numCards - i)); // generate random number between 1 and 52
        swap(cards[i], cards[randomNumber]);
    }
}

// function to add to the pile
void Pile::AddCardToPile(Card * card){ 
    // adds a card to the end of the array
    cards[numCards] = card;
    numCards++;
}

// function to take out card from the pile
Card * Pile::RemoveTopCard(){
    // removes a card from the end of the array
    Card * cardToReturn = cards[numCards - 1];
    numCards--;
    return cardToReturn;
}

// getnumber function
int Pile::GetNumCards(){
    return numCards;
}

// function to check pile is empty or not
bool Pile::isEmpty(){

    if( numCards == 0 ){
        return true;
    } else {
        return false;
    }
}

// print out all of cards in the pile
void Pile::PrintCards(){

    for(int i = 0; i < numCards; i++){

    cout << "Card " << i+1 << ", ";

        switch( cards[i] -> getValue() ){
            case 0 : cout << "Ace"; break;
            case 1 : cout << "Two"; break;
            case 2 : cout << "Three"; break;
            case 3 : cout << "Four"; break;
            case 4 : cout << "Five"; break;
            case 5 : cout << "Six"; break;
            case 6 : cout << "Seven"; break;
            case 7 : cout << "Eight"; break;
            case 8 : cout << "Nine"; break;
            case 9 : cout << "Ten"; break;
            case 10 : cout << "Jack"; break;
            case 11 : cout << "Queen"; break;
            case 12 : cout << "King"; break;
        }
        cout << " of ";

        switch( cards[i] -> getSuit() ){
            case 0 : cout << "spades" << endl; break;
            case 1 : cout << "clubs" << endl; break;
            case 2 : cout << "diamonds" << endl; break;
            case 3 : cout << "hearts" << endl; break;
        }
    }
}
