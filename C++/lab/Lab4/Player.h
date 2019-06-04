#ifndef PLAYER_H
#define PLAYER_H

#include "Pile.h"
#include "Card.h"

using namespace std;

// class Player
class Player {

    public:
        Player(); // constructor Player

        // getter and setter toPlay
        void setToPlayPile( Pile p );
        Pile& getToPlayPile();

        void setPlayedPile( Pile p );
        Pile& getPlayedPile();

        void setInPlayPile( Pile p );
        Pile& getInPlayPile();

    private:
        //initialize three Piles for game
        Pile toPlay;
        Pile played;
        Pile inPlay;
}; // end class

#endif
