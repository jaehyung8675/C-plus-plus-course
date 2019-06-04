#include <iostream>

#include "Player.h"
#include "Card.h"

using namespace std;

// constructor Plyer
Player::Player(){

}

// function getter and setter toPlay Pile
void Player::setToPlayPile( Pile p ){
    toPlay = p;
};
        
Pile& Player::getToPlayPile(){
    return toPlay;
};

void Player::setPlayedPile( Pile p ){
    played = p;
}
Pile& Player::getPlayedPile(){
    return played;
}

void Player::setInPlayPile( Pile p ){
    inPlay = p;
}
Pile& Player::getInPlayPile(){
    return inPlay;
}