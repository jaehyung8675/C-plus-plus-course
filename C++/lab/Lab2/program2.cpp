#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "search_functions.h"
// include iostrem, fstream, string, vecteor, and "search_functions.h"

using namespace std;

int main() {

    ifstream inFile;
    inFile.open("phoneBook.txt"); // import text file 

    // declare vector string and string name, phonenumber, and query
    vector<string> names;
    vector<string> phoneNumbers;
    string name;
    string number;
    string query;

    // initialize option and foundindex as 0
    int option = 0;
    int foundIndex = 0;

    // assign each name and number to vetors from text file
    while(!inFile.eof()){
        getline(inFile, name, ',');
        names.push_back(name);
        getline(inFile, number);
        phoneNumbers.push_back(number);
    }
    
    // display optionss
    cout << "Welcome to SMU\'s Phone Book" 
    << endl << endl;
    cout << "---------------------------" << endl;
    cout << "(1) - Find By Name (Recursive) " << endl;
    cout << "(2) - Find By Name (Iterative) " << endl;
    cout << "(3) - Find By Phone Number (Recursive) " << endl;
    cout << "(4) - Find By Phone Number (Iterative) " << endl;
    cout << "(5) - Quit " << endl << endl;

    do {
        // user input option
        cout << "Please Select an option: ";
        cin >> option;

        // each if statement check the option and get name or number from user
        // later call a function to search name or number
        // store a return int value to foundIndex, which is an index of name or number or -1
        if(option == 1){
            cin.ignore();
            // display text for user and get query
            cout << "Enter a name: ";
            getline(cin, query);
            // call searchIterative function and get value
            foundIndex = searchRecursive(names, query, 0, names.size() -1); // call searchRecursive function to match name
        
            // display the result of no found(-1) or found index information(foundIndex)
            if(foundIndex == -1){
                    cout << "\n" << "No Result Found" << endl << endl;
            } else {
                cout << "\n" << foundIndex+1 << ". " << names[foundIndex] << " - " << phoneNumbers[foundIndex] << endl << endl;
            }
        }
        
        if(option == 2){
            cin.ignore();
            // display text for user and get query
            cout << "Enter a name: ";
            getline(cin, query);
            // call searchIterative function and get value
            foundIndex = searchIterative(names, query); 
        
            // display the result of no found(-1) or found index information(foundIndex)
            if(foundIndex == -1){
                    cout << "\n" << "No Result Found" << endl << endl;
            } else {
                cout << "\n" << foundIndex+1 << ". " << names[foundIndex] << " - " << phoneNumbers[foundIndex] << endl << endl;
            }
        } 
        
        if(option == 3){
            cin.ignore();
            // display text for user and get query
            cout << "Enter a phone nunmber: ";
            getline(cin, query);
            // call searchIterative function and get value
            foundIndex = searchRecursive(phoneNumbers, query, 0, phoneNumbers.size() -1); // call searchRecursive function to match phone number
        
            // display the result of no found(-1) or found index information(foundIndex)
            if(foundIndex == -1){
                    cout << "\n" << "No Result Found" << endl << endl;
            } else {
                cout << "\n" << foundIndex+1 << ". " << names[foundIndex] << " - " << phoneNumbers[foundIndex] << endl << endl;
            }
        } 
        
        if(option == 4){
            cin.ignore();
            // display text for user and get query
            cout << "Enter a phone nunmber: ";
            getline(cin, query);
            // call searchIterative function and get value
            foundIndex = searchIterative(phoneNumbers, query); // call searchIterative function to match phone number
        
            // display the result of no found(-1) or found index information(foundIndex)
            if(foundIndex == -1){
                    cout << "\n" << "No Result Found" << endl << endl;
            } else {
                cout << "\n" << foundIndex+1 << ". " << names[foundIndex] << " - " << phoneNumbers[foundIndex] << endl << endl;
            }
        }

    } while (option != 5); // if option is not equal to 5, it keep the loop 

    inFile.close(); // close text file
    return 0;
} // end main()