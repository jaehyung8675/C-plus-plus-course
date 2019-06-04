#ifndef PLAYER_H
#define PLAYER_H

#include "pile.h"
#include <stack>

using namespace std;

class Player{

	public:

		Player(); // constructor Player
		~Player(); // deconstructor Player

		Pile * GetToPlayPile(); // get pile to play from player
		Pile * GetPlayedPile(); // get played pile from player

	private:
		//initialize two Piles
		Pile * toPlay;
		Pile * played;
	
};

#endif