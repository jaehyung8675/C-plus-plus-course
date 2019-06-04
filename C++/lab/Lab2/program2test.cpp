#include <vector>
#include <string>
#include <iostream>
#include <cassert>

#include "search_functions.h"

using namespace std;

int main() {
    //creat vector test and initialize test strings
    vector<string> test;
    test.push_back("Laura Bush,2142842934");
    test.push_back("Kathy Bates,2143954218");
    test.push_back("Lauren Graham,7130385534");
    test.push_back("Kourtney Kardasian,2149492789");
    test.push_back("Doak Walker,5127834500");
    
    // // for loop to test each vector line with searchRecursive function
    for(int i = 0; i < test.size(); i++){
        assert(searchRecursive(test, test[i], 0, test.size()-1) == i);
    }
    // // for loop to test each vector line with searchIterative function
    for(int i = 0; i < test.size(); i++){
        assert(searchIterative(test, test[i]) == i);
    }
    cout << "Success" << endl;
    return 0;
}