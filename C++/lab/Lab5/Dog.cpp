#include <string>

#include "Animal.h"
#include "Dog.h"

using namespace std;

// Dog default constructor with boolean value 
Dog::Dog() : Animal()
{
    this -> toy = "";
}

// Dog constructor with boolean value 
Dog::Dog( string typeAnimal, string nickName, int animalAge, string dogToy ) : Animal( typeAnimal, nickName, animalAge )
{
    this -> toy = dogToy;
}

// Copy constructor
// Dog::Dog(const Dog &p){
//     toy = p.toy;
// }

// print Dog currently at the shelter
const string Dog::toString(){
    string s = "Animal: " + getType() + "\n" 
                + "Name: " + getName() + "\n"  
                + "Age: " + to_string(getAge()) + "\n"  
                + "Fee: $" + to_string(dailyFee) + "\n"  
                + "Favorit Toy: " + toy + "\n";
    return s;
}

// get daily fee
//void Dog::setDailyFee(50);
int Dog::getDailyFee(){ return dailyFee; };
string Dog::getToy(){ return toy; };