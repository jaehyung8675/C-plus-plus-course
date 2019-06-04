#ifndef TABLETOP_H
#define TABLETOP_H

#include "card.h"
#include "pile.h"
#include "player.h"
#include <stack>

using namespace std;

class TableTop{

	public:
		
		TableTop(); // constructor TableTop
		~TableTop(); // deconstructor TableTop

		bool DoBattle(); // bool to do battle
		
	private:
		// initialize two players, current pile, and deck of cards array
		Player playerA; 
		Player playerB;
		Pile currentlyInPlay;
		Card * deck[MAXCARDS];	
};

#endif