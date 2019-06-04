#include <string>

#include "Animal.h"
#include "Rabbit.h"

using namespace std;

// Rabbit default constructor with boolean value 
Rabbit::Rabbit() : Animal()
{
    this -> numberOfCarrots = 0;
}

// Rabbit constructor with boolean value 
Rabbit::Rabbit( string typeAnimal, string nickName, int animalAge, int numberOfCarrots ) : Animal( typeAnimal, nickName, animalAge )
{
    this -> numberOfCarrots = numberOfCarrots;
}

// Copy constructor
// Rabbit::Rabbit(const Rabbit &p){
//     numberOfCarrots = p.numberOfCarrots;
// }

// print Rabbit currently at the shelter
const string Rabbit::toString(){
    string s = "Animal: " + getType()  + "\n" 
                + "Name: " + getName() + "\n"  
                + "Age: " + to_string(getAge()) + "\n"  
                + "Fee: $" + to_string(dailyFee) + "\n" 
                + "Number of Carrots / Day: " + to_string(numberOfCarrots) + "\n";
    return s;
}

// get daily fee
//void Rabbit::setDailyFee(15);
int Rabbit::getDailyFee(){ return dailyFee; };
int Rabbit::getNumberOfCarrots(){ return numberOfCarrots; };