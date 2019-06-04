#include "player.h"
#include <stack>

using namespace std;

Player::Player(){ // constructor Plyer with two piles
	toPlay = new Pile;
	played = new Pile;
}

Player::~Player(){ // deconstructor Plyer with two piles
	delete toPlay;
	delete played;
}

// function get toPlay and played Piles

Pile * Player::GetToPlayPile(){
	return toPlay;
}

Pile * Player::GetPlayedPile(){
	return played;
}
