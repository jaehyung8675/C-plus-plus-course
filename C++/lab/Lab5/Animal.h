#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std; 

class Animal {

    public:
        // constructors Animal
        Animal( );
        // Animal( const Animal &p1 );
        Animal( string typeAnimal, string nickName, int animalAge );

        // getter and settter functions
        void setType( string typeAnimal );
        string getType();

        void setName( string nickName );
        string getName();

        void setAge( int animalAge );
        int getAge();

        void setDailyFee( int fee );
        int getDailyFee();

        // display a animal currently at the shelter
        virtual const string toString();
        int dailyFee;
    private:
        // declare type, name, age, and dailyfee
        string name;
        string type;
        int age;
        
};

#endif