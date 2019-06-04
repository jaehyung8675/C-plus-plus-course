#ifndef CARD_H
#define CARD_H

using namespace std;

// initialize enum suit and value of card
enum suit { clubs, diamonds, hearts, spades };
enum value { ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king };

class Card {

    public:
        Card( suit cardSuit, value cardValue ); // constructor with two enums suit and value

        // getter and setter card
        void setSuit( suit cardSuit );
        suit getSuit() const;

        void setValue( value cardValue );
        value getValue() const;

        void PrintOneCards();

    private:
        // initialize card suit and value 
        suit cardSuit; 
        value cardValue;
};

#endif