#include <iostream>

#include "Card.h"

using namespace std;

Card::Card( suit cardSuit, value cardValue ){
    // constructor card with two parameters
    this -> cardSuit = cardSuit;
    this -> cardValue = cardValue;
}

// getter and setter function definition
void Card::setSuit( suit cardSuit ) { this -> cardSuit = cardSuit; }
suit Card::getSuit() const { return cardSuit; }

void Card::setValue ( value cardValue ) { this -> cardValue = cardValue; }
value Card::getValue() const { return cardValue; }


void Card::PrintOneCards(){

    switch( getValue() ){
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

    switch( getSuit() ){
        case 0 : cout << "spades"; break;
        case 1 : cout << "clubs"; break;
        case 2 : cout << "diamonds"; break;
        case 3 : cout << "hearts"; break;
    }

}


