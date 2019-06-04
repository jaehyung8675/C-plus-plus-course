#include <iostream>
#include <string>

#include "Card.h"
#include "Pile.h"
#include "Player.h"

using namespace std;

int main(){

    int round = 1;

    // display comment on the screen
    cout << "Welcome to the Game of War!" << endl << endl;

    // create a pile and fill it up cards
    Pile myPile; 
    myPile.fullDeck();
 
    // display comment with shuffle cards
    cout << "Shuffling initial deck..." << endl;
    cout << endl;
    myPile.Shuffle();

    // initialize two players
    Player playerA;
    Player playerB;

    // display comment to initial toPile
    cout << "Initial 'to play' piles:" << endl;
    cout << endl;

    // seperate cards to each player's toPile from the deck
    for(int i = 0; i < 26; i++){
        
        Card * c = myPile.RemoveTopCard(); // taking out card from the deck
        playerA.getToPlayPile().AddCardToPile( c ); // add card to player's pile
        // cout << "playerA has number of cards: " << playerA.getToPlayPile().GetNumCards() << endl;
        
        c = myPile.RemoveTopCard();
        playerB.getToPlayPile().AddCardToPile( c );
        // cout << "playerB has number of cards: " << playerB.getToPlayPile().GetNumCards() << endl;
    }

    cout << myPile.GetNumCards() << endl;
    if (myPile.isEmpty()){
        cout << "GGGGood" << endl;
    } else
    {
       cout << "BBBBBBbad" << endl;
    }
    

    // display comment Player A cards
    cout << "Player A:" << endl;
    cout << "There are " << playerA.getToPlayPile().GetNumCards() << "cards in the pile." << endl;
    
    playerA.getToPlayPile().PrintCards();
    cout << endl;

    // display comment Player B cards
    cout << "Player B:" << endl;
    cout << "There are " << playerB.getToPlayPile().GetNumCards() << "cards in the pile." << endl;
    playerB.getToPlayPile().PrintCards();
    cout << endl;


    // start round
    // while loop, until one of players runs out of their toPlay and Played Pile
    while( ( !playerA.getToPlayPile().isEmpty() || !playerA.getPlayedPile().isEmpty()) &&
      ( !playerB.getToPlayPile().isEmpty() || !playerB.getPlayedPile().isEmpty() )) {


        // display each player card
        cout << "======== Round " << round << " ========" << endl;
here:
        
        Card * oneCard = playerA.getToPlayPile().RemoveTopCard();
        cout << "Player A plays ";
        oneCard -> PrintOneCards();
        cout << endl;
        playerA.getInPlayPile().AddCardToPile( oneCard );

        Card * twoCard = playerB.getToPlayPile().RemoveTopCard();
        cout << "Player B plays ";
        twoCard -> PrintOneCards();
        cout << endl;
        playerB.getInPlayPile().AddCardToPile( twoCard );
        cout << endl;
        
        // if statement, who player win or tie comment
        if( oneCard -> getValue() > twoCard -> getValue() ){
            cout << "Player A wins the 'currently in play' pile." << endl;
            
            for(int i = 0; i < playerA.getInPlayPile().GetNumCards(); i++){
                
                Card * tempA = playerB.getInPlayPile().RemoveTopCard();
                    playerA.getPlayedPile().AddCardToPile( tempA );
                tempA = playerA.getInPlayPile().RemoveTopCard();
                    playerA.getPlayedPile().AddCardToPile( tempA );
            }

                if ( playerA.getToPlayPile().GetNumCards() == 0 ){

                    cout << "Player A ran out of cards in their 'to play' pile.  Getting cards from the 'played' pile." << endl;

                    int size = playerA.getPlayedPile().GetNumCards();

                    for(int i = 0; i < size; i++){
                        Card * moveA = playerA.getPlayedPile().RemoveTopCard();
                        playerA.getToPlayPile().AddCardToPile( moveA );
                    }
                    
                    cout << "Shuffling player A cards..." << endl;
                    playerA.getToPlayPile().Shuffle();
                    cout << endl;
                }

                if ( playerB.getToPlayPile().GetNumCards() == 0 ){
                        
                    cout << "Player B ran out of cards in their 'to play' pile.  Getting cards from the 'played' pile." << endl;

                    int size = playerB.getPlayedPile().GetNumCards();

                    for(int i = 0; i < size; i++){
                        Card * moveB = playerB.getPlayedPile().RemoveTopCard();
                        playerB.getToPlayPile().AddCardToPile( moveB );
                    }
               

                    cout << "Shuffling player A cards..." << endl;
                    playerB.getToPlayPile().Shuffle();
                    cout << endl;
                }
            
            // display each player toPile and played Pile
            cout << "Player A has " << playerA.getToPlayPile().GetNumCards() << " in their 'to play' pile and "
            << playerA.getPlayedPile().GetNumCards() << " in their 'played' pile." << endl;
            
            cout << "Player B has " << playerB.getToPlayPile().GetNumCards() << " in their 'to play' pile and "
            << playerB.getPlayedPile().GetNumCards() << " in their 'played' pile." << endl;
            cout << endl;

        } else if ( oneCard -> getValue() < twoCard -> getValue() ){

            cout << "Player B wins the 'currently in play' pile." << endl;
            
            for(int i = 0; i < playerB.getInPlayPile().GetNumCards(); i++){

                Card * tempB = playerA.getInPlayPile().RemoveTopCard();
                    playerB.getPlayedPile().AddCardToPile( tempB );
                tempB = playerB.getInPlayPile().RemoveTopCard();
                    playerB.getPlayedPile().AddCardToPile( tempB );
            }

                           if ( playerA.getToPlayPile().GetNumCards() == 0 ){

                    cout << "Player A ran out of cards in their 'to play' pile.  Getting cards from the 'played' pile." << endl;

                    int size = playerA.getPlayedPile().GetNumCards();

                    for(int i = 0; i < size; i++){
                        Card * moveA = playerA.getPlayedPile().RemoveTopCard();
                        playerA.getToPlayPile().AddCardToPile( moveA );
                    }
                    
                    cout << "Shuffling player A cards..." << endl;
                    playerA.getToPlayPile().Shuffle();
                    cout << endl;
                }

                if ( playerB.getToPlayPile().GetNumCards() == 0 ){
                        
                    cout << "Player B ran out of cards in their 'to play' pile.  Getting cards from the 'played' pile." << endl;

                    int size = playerB.getPlayedPile().GetNumCards();

                    for(int i = 0; i < size; i++){
                        Card * moveB = playerB.getPlayedPile().RemoveTopCard();
                        playerB.getToPlayPile().AddCardToPile( moveB );
                    }
               

                    cout << "Shuffling player A cards..." << endl;
                    playerB.getToPlayPile().Shuffle();
                    cout << endl;
                }

            // display each player toPile and played Pile
            cout << "Player A has " << playerA.getToPlayPile().GetNumCards() << " in their 'to play' pile and "
            << playerA.getPlayedPile().GetNumCards() << " in their 'played' pile." << endl;
            
            cout << "Player B has " << playerB.getToPlayPile().GetNumCards() << " in their 'to play' pile and "
            << playerB.getPlayedPile().GetNumCards() << " in their 'played' pile." << endl;
            cout << endl;

        } else {

            cout << "There is a tie... Doing another battle." << endl;
            
            // display each player toPile and played Pile
            cout << "Player A has " << playerA.getToPlayPile().GetNumCards() << " in their 'to play' pile and "
            << playerA.getPlayedPile().GetNumCards() << " in their 'played' pile." << endl;
            
            cout << "Player B has " << playerB.getToPlayPile().GetNumCards() << " in their 'to play' pile and "
            << playerB.getPlayedPile().GetNumCards() << " in their 'played' pile." << endl;
            cout << endl;

                          if ( playerA.getToPlayPile().GetNumCards() == 0 ){

                    cout << "Player A ran out of cards in their 'to play' pile.  Getting cards from the 'played' pile." << endl;

                    int size = playerA.getPlayedPile().GetNumCards();

                    for(int i = 0; i < size; i++){
                        Card * moveA = playerA.getPlayedPile().RemoveTopCard();
                        playerA.getToPlayPile().AddCardToPile( moveA );
                    }
                    
                    cout << "Shuffling player A cards..." << endl;
                    playerA.getToPlayPile().Shuffle();
                    cout << endl;
                }

                if ( playerB.getToPlayPile().GetNumCards() == 0 ){
                        
                    cout << "Player B ran out of cards in their 'to play' pile.  Getting cards from the 'played' pile." << endl;

                    int size = playerB.getPlayedPile().GetNumCards();

                    for(int i = 0; i < size; i++){
                        Card * moveB = playerB.getPlayedPile().RemoveTopCard();
                        playerB.getToPlayPile().AddCardToPile( moveB );
                    }
               

                    cout << "Shuffling player A cards..." << endl;
                    playerB.getToPlayPile().Shuffle();
                    cout << endl;
                }        

            goto here;
        }

        // if statement, one player ran out of cards and break out of loop
        if( (playerA.getToPlayPile().GetNumCards() == 0) && (playerA.getPlayedPile().GetNumCards() == 0 ) ){
            cout << "Player A ran out of cards. Player A has lost." << endl;
            break;
        }

        if( (playerB.getToPlayPile().GetNumCards() == 0) && (playerB.getPlayedPile().GetNumCards() == 0) ){
            cout << "Player B ran out of cards. Player B has lost." << endl;
            break;
        }

        round++;

    } // end while loop
        
    return 0;
} // end main

