#include <string>
#include "Animal.h"

using namespace std; 

Animal::Animal( ){ // Default Constructor
    type = "";
    name = "";
    age = 0;
}

// Animal::Animal( const Animal &p1 ){ //Copy constructor
//     type = p1.type;
//     name = p1.name;
//     age = p1.age;
// }

Animal::Animal( string typeAnimal, string nickName, int animalAge ){ // constructor Animal
    type = typeAnimal;
    name = nickName;
    age = animalAge;
}

// display a animal currently at the shelter
const string Animal::toString(){

    string s = "Animal: " + type + "\n" 
                + "Name: " + name + "\n"  
                + "Age: " + to_string(age) + "\n";
    return s;
}

// getter and setter funtions
void Animal::setType( string typeAnimal ){ type = typeAnimal; }
string Animal::getType(){ return type; }

void Animal::setName( string nickName ){ name = nickName; }
string Animal::getName(){ return name; }

void Animal::setAge( int animalAge ){ age = animalAge; }
int Animal::getAge(){ return age; }

void Animal::setDailyFee( int fee ){ dailyFee = fee; }
int Animal::getDailyFee(){ return dailyFee; }