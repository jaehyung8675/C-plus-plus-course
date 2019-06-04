#include <iostream> // for in and out stream
#include <cstdlib>  // for rand/srand
#include <ctime>   // for time
#include <fstream> // for output csv file
#include "SortFunctions.h" // split up sort function definitions, and sort function prototypes

using namespace std;

int main() {

    ofstream myFile("output.csv"); // open myFile

    int numbersOne[100]; // initialize empty array one
    int numbersTwo[100]; // initialize empty array two
    int randNum = 0; // initialize random number
    
    srand((unsigned)time(0)); // seed RNG at startup
    // to get a random number size between [2 - 100]
    int numbersSize = 2;

    // initialize two counting sorting function 
    int countSelectionSort = 0;
    int countMergeSort = 0;
    // initialize two tempery integers to exchange value
    int tmp = 0;
    int tmp1 = 0;

    for(int i = 2; i <= 100; i++) {

        // for loop to perform 10,000 trial
        for(int i = 0; i < 10000; ++i) {
            
            // for loop, to create random array size  
            for (int i = 0; i < numbersSize; i++){
                // to get a random number between [1 - 1000]
                randNum = (rand() % 1000) + 1;
                // assgin randon number in two arrays
                numbersOne[i] = randNum; 
                numbersTwo[i] = randNum;
            } // end for loop

            // call selection sort funtion
            tmp = SelectionSort(numbersOne, numbersSize);
            // call merge sort funtion
            tmp1 = MergeSort(numbersTwo, 0, numbersSize - 1);

            if( countSelectionSort < tmp ){
                // assgin tmp value if countSelectionSort less than tmp
                countSelectionSort = tmp;
            } 

            if( countMergeSort < tmp1 ){
                // assgin tmp value if countMergeSort less than tmp1
                countMergeSort = tmp1;
            } 
        }
        // cout << numbersSize << ", " << countSelectionSort << ", " << countMergeSort << endl;
        // input the worst-case number of operations for each sort algorithm
        myFile << numbersSize << ", " << countSelectionSort << ", " << countMergeSort << endl;
        numbersSize++; 
    } // end for loop
  
    myFile.close(); // close myFile
    return 0;
} // end main