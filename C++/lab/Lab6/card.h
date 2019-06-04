#ifndef CARD_H
#define CARD_H

// initialize enum suit and value of card
enum SUIT { HEART, DIAMOND, SPADE, CLUB };
enum RANK { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

class Card{

public:

	Card(); // card constructor

	// getter and setter card
	void SetSuitAndRank(int suit, int rank);
	const char * GetRankString();
	int GetRank();
	const char * GetSuitString();
	int GetSuit();

private:
	// initialize card suit and rank 
	int suit;
	int rank;
};

#endif