#ifndef CAT_H
#define CAT_H

#include <string>

using namespace std; 

// class Cat in base animal
class Cat : public Animal {

    public:
        // constructors Cat
        Cat();
        Cat( string typeAnimal, string nickName, int animalAge, bool isOutdoor);

        // getter and settter daily fee functions
        int getDailyFee();
        bool getIsOutdoor();
        //string getIsOutdoor();
        
        // display a cat's nickname, age, isoutdoor
        const string toString();
        
    private:
        // declare isoutdoor and initialize dailyfee
        //string isOutdoor;
        bool isOutdoor;
        static const int dailyFee = 25;
};

#endif