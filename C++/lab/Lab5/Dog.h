#ifndef Dog_H
#define Dog_H

#include <string>

using namespace std; 

// class Dog in base animal
class Dog : public Animal {

    public:
        // constructors Dog
        Dog();
        Dog( string typeAnimal, string nickName, int animalAge, string dogToy);

        // getter daily fee function
        int getDailyFee();
        string getToy();

        // display a dog's nickname, age, toy
        const string toString();
        
    private:
        // declare toy and initialize dailyfee
        string toy;
        static const int dailyFee = 50;
};

#endif