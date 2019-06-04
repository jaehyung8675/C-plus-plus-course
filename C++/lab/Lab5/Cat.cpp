#include <string>

#include "Animal.h"
#include "Cat.h"

using namespace std;

// Cat default constructor with string value 
Cat::Cat() : Animal()
{
    this -> isOutdoor = true;
}

// Cat constructor with string value 
Cat::Cat( string typeAnimal, string nickName, int animalAge, bool isOutdoor ) : Animal( typeAnimal, nickName, animalAge )
{
    this -> isOutdoor = isOutdoor;
}

// Copy constructor
// Cat::Cat(const Cat &p){
//     isOutdoor = p.isOutdoor;
// }

// print cat currently at the shelter
const string Cat::toString(){
    string s;
    if( isOutdoor == false ){
          s = "Animal: " + getType()  + "\n" 
                + "Name: " + getName() + "\n"  
                + "Age: " + to_string(getAge()) + "\n"  
                + "Fee: " + to_string(dailyFee) + "\n" 
                + "Indoor/Outdoor: " + "Indoor" + "\n";
    } else {
           s = "Animal: " + getType()  + "\n" 
                + "Name: " + getName() + "\n"  
                + "Age: " + to_string(getAge()) + "\n"  
                + "Fee: $" + to_string(dailyFee) + "\n" 
                + "Indoor/Outdoor: " + "Outdoor" + "\n";
    }
  
    return s;
}

// get daily fee
int Cat::getDailyFee(){
    return dailyFee;
};

// get string IsOutdoor
bool Cat::getIsOutdoor(){ return isOutdoor; };
// string Cat::getIsOutdoor(){ return isOutdoor; };