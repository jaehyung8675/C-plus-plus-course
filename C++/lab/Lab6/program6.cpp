#include <iostream>
#include "tabletop.h"
#include <stack>

using namespace std;

int main(){
	
	TableTop tableTop; // create new tabletop
	
	bool someoneRanOutOfCards = false; // set false on someone ran out of cards
	int round = 1; // initialize round

	// while loop to keep doing battle until someone ran out of cards is true
	while(!someoneRanOutOfCards){
		cout << "======== Round " << round++ << " ========" << endl;
		someoneRanOutOfCards = tableTop.DoBattle();
	}
	
	return 0;
}