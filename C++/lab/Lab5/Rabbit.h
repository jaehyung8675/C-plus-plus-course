#ifndef RABBIT_H
#define RABBIT_H

#include <string>

using namespace std; 

// class Rabbit in base animal
class Rabbit : public Animal {

    public:
        // constructors Rabbit
        Rabbit();
        Rabbit( string typeAnimal, string nickName, int animalAge, int numberOfCarrots);

        // getter daily fee function
        int getDailyFee();
        int getNumberOfCarrots();

        // display a rabbit's nickname, age, numberOfCarrots
        const string toString();
        
    private:
        // declare numberOfCarrots and initialize dailyfee
        int numberOfCarrots;
        static const int dailyFee = 15;
};

#endif