#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Rabbit.h"

using namespace std;

void displayOption(){ // display options function

    cout << "Select an option:" << endl;
    cout << "0. Exit" << endl;
    cout << "1. View Animals" << endl;
    cout << "2. Drop Off Animal" << endl;
    cout << "3. Pick Up Animal" << endl;
    cout << "Select: ";
}

struct node
{ // node struct animal data type with two nodes
    Animal *animal;
    node *next;
    node *prev;
};

class linked_list
{
    public:
        // initialize cage number with head and tail pointer
        int cage = 0; 
        node *head;
        node *tail;
        
        linked_list()
        {   // assign head and tail pointer to nullptr
            head = nullptr;
            tail = nullptr;
        }
        // function for appending animal
        void append(Animal *animal){
            
            node *n = new node();
            n->animal = animal;

            if( this->head == nullptr)
            { // list empty
                n -> next = nullptr;
                n -> prev = nullptr;
                this -> head = n;
                this -> tail = n;
            }
            else
            {  
                this -> tail -> next = n; 
                n -> prev = this -> tail;
                n -> next = nullptr;
                this -> tail = n;
            }
        }
        // function for displaying animals
        void display()
        {
            node *temp = this -> head;
         
            while(temp)
            {   // while loop to print out each cage
                cout << "--- Cage " << cage+1 << " ---" << endl;
                cout << temp -> animal -> toString() << endl;
                temp = temp -> next;
                cage++;
            }
            cage = 0; // after that, assign cage number to 0
        }

        void remove( int cage )
        {
            // empty linkedlist
            if(this -> head == nullptr || cage <= 0){ 
                return;
            }
            
            node *current = this -> head;
            int i;
            // traverse up to the node at position cage from the beginning
            for( int i = 1; current != NULL && i < cage; i++){
                current = current -> next;
            }
            // if cage is greater than the number of nodes in the doubly linked list
            if (current == NULL){
                return;
            }
            // delete the node pointed to by current
            deleteNode(current);

            
            /*if ( this -> head == temp ){
                this -> head = temp -> next;
            }

            if( cage == 1 ){
                this -> head = temp -> next;
                delete temp;

            } else if ( cage > 1 ) {

                for(int i = 1; i < cage; i++){ // for loop for searching node

                    //temp -> prev = temp -> next;
                    temp = temp -> next;
                }

                temp -> prev -> next = temp -> next;
                cout << temp -> animal -> toString() << endl;

                delete temp;
            }
            
            this -> head = temp -> next;
            delete temp;
            */
        }

        // function for deletion animal
        void deleteNode(node* del){
            // base case
            if(this -> head == NULL || del == NULL){
                return;
            }
            // If node to be deleted is head node
            if(this -> head == del){
                this -> head = del -> next;
            }
            // Change next only if node to be deleted is NOT the last node
            if(del -> next != NULL){
                del -> next -> prev = del -> prev;
            }
            // Change prev only if node to be deleted is NOT the first node
            if(del -> prev != NULL){
                del -> prev -> next = del -> next;
            }
           
            delete del;  // delete node
        }
}; // end linked_list

int main( int argc, char * argv[] ){

    // initialize option, cage number, dopping option and drop animal
    int option;
    int cageNum;
    char dropOption;
    string dropAnimal;

    // for reading txt file to assign each value
    string typeAnimal;
    string nickName;
    string number;
    string randomString;

    // open txt file by command line arguments
    ifstream inFile;
    inFile.open( argv[1] );

    if(!inFile.is_open()){
        cout << "Could not open file." << endl;
        return -1;
    }

    // declare linked list animals
    linked_list *animals = new linked_list();

    // while loop to read each text by ',' and create each object
    while(!inFile.eof()){

        getline(inFile, typeAnimal, ',');
        getline(inFile, nickName, ',');
        getline(inFile, number, ',');
        getline(inFile, randomString);

        // initialize each animal and copy of constructor
        if( typeAnimal == "cat" ){
            // create cat obejct and add on animals list
            Cat *c = new Cat( typeAnimal, nickName, stoi(number), randomString.compare("true")?false:true );
            animals->append(c);
        }
        
        if( typeAnimal == "dog" ){
            // create dog obejct and add on animals list
            Dog *d = new Dog( typeAnimal, nickName, stoi(number), randomString );
            animals->append(d);
        }

        if( typeAnimal == "rabbit" ){
            // create rabbit obejct and add on animals list
            Rabbit *r = new Rabbit( typeAnimal, nickName, stoi(number), stoi(randomString) );
            animals->append(r);
        }
    }

    cout << "Welcome to SMU Animal Day Car!" << endl << endl; // initial display 

    // while loop for user options
    while ( true ){

        displayOption(); // display option
        cin >> option;
        cout << endl;
        
        if ( option == 1 ){ // option 1
            // for loop to display all of cages
                animals->display();
        }
        else if ( option == 2 ){ // option 2
           
            // user input animal info to drop off
            cout << "What animal are you dropping off? (c,d,r): ";
            cin >> dropOption;

                if( dropOption == 'c' ){
                    // user input cat info
                    cout << "Enter your cat's info in the following format:" << endl;
                    cout << "name,age,isOutdoor" << endl;
                    cout << "Ex: elroy,1,true\n";
                    
                    cin >> dropAnimal;
                    stringstream ss(dropAnimal);

                    typeAnimal = "cat";
                    getline(ss, nickName, ',');
                    getline(ss, number, ',');
                    getline(ss, randomString);

                    // initialize each animal and copy of constructor
                    Cat *c = new Cat( typeAnimal, nickName, stoi(number), randomString.compare("true")?false:true );
                    animals->append(c);

                } else if( dropOption == 'd' ){
                    // user input dog info
                    cout << "Enter your dog's info in the following format:" << endl;
                    cout << "name,age,toy" << endl;
                    cout << "Ex: charlie,1,bone\n";
                    
                    cin >> dropAnimal;
                    stringstream ss(dropAnimal);

                    typeAnimal = "dog";
                    getline(ss, nickName, ',');
                    getline(ss, number, ',');
                    getline(ss, randomString);

                    Dog *d = new Dog( typeAnimal, nickName, stoi(number), randomString );
                    animals->append(d);
                } else {
                    // user input rabbit info
                    cout << "Enter your rabbit's info in the following format:" << endl;
                    cout << "name,age,numberOfCarrots" << endl;
                    cout << "Ex: squeekers,3,5\n";
                    
                    cin >> dropAnimal;
                    stringstream ss(dropAnimal);

                    typeAnimal = "rabbit";
                    getline(ss, nickName, ',');
                    getline(ss, number, ',');
                    getline(ss, randomString);

                    Rabbit *r = new Rabbit( typeAnimal, nickName, stoi(number), stoi(randomString) );
                    animals->append(r);
                }

                cout << "\nThank you!" << endl << endl;

        } 
        else if ( option == 3 ){ // option 3
            // display to user for choose case number
            int cageNum;
            cout << "Which Animal would you like to pick up?" << endl;
            cout << "Enter Cage #: ";
            cin >> cageNum;
            animals->remove(cageNum);
            cout << "\nThank you!" << endl << endl;

        } else {
             break; // 0 or other number break out of while loop
        }
    }
        
    return 0;
} // end main

