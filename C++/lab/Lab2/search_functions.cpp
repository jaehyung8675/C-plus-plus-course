#include <vector>
#include <string>
using namespace std;

/* onther way to get result as indirective recursive functions 
// boolean function to find matchig name and phone number
boolIndex(string data, string query){
    // if data same with query, return true
    if(data.compare(query) == 0){
        return true;
    } else{
        return false; // not match, return false
    }
}

// use another function call boolIndex to find matching name or number
int searchRecursive(vector<string> &data, string query) {
    
    int counter = 0; // initialize counter as zero

    do{
        bool foundIndex = boolIndex(data[counter], query); // call foundIndex function to match query and data
        // if foundIndex is true, return found index, else increament counter for next data
        if( foundIndex ){
            return counter;
        } else {
            counter++; 
        }
    } while( counter < data.size() ); // while loop until end of data size
    
    return -1; // no found name or phone number, return -1
}
*/

// Recursive funtion - use vector data reference with query, initial lowerbound, data size to find matching name or phone number  
int searchRecursive(vector<string> &data, string query, int lowerBound, int upperBound) {
    // if search until the size of data and not match, return -1
    if (lowerBound > upperBound)
        return -1;
    // if data same query, return index number, which is lowerBound
    if (data[lowerBound] == query)
        return lowerBound;
    
    // if (data[upperBound] == query)
    //     return upperBound;

    return searchRecursive(data, query, lowerBound+1, upperBound); // recursive function with increament lowerBound
}

// Iterative funtion - use vector data reference and user's input to find matching name or phone number
int searchIterative(vector<string> &data, string query) {
    // for loop through the whole data lines 
    for(int i = 0; i < data.size(); i++){
        // if data is same with query, return index
        if(data[i].compare(query) == 0) {
            return i;
        }
    }
    return -1; // no found, return -1
}