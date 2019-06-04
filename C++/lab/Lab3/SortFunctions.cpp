#include <iostream>
using namespace std;

int SelectionSort(int numbers[], int numbersSize) {
   int i;
   int j;
   int indexSmallest;
   int temp;    // Temporary variable for swap
   int count = 0;
   
   for (i = 0; i < numbersSize - 1; ++i) {
     
      // Find index of smallest remaining element
      indexSmallest = i;
      for (j = i + 1; j < numbersSize; ++j) {
         if ( numbers[j] < numbers[indexSmallest] ) {
            indexSmallest = j;
         }
         count++; // comparsion count
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      temp = numbers[i];
      numbers[i] = numbers[indexSmallest];
      numbers[indexSmallest] = temp;
      count++; // swap count
   }

   return count; // return value of count
}

int Merge(int numbers[], int i, int j, int k) {
   int mergedSize;                            // Size of merged partition
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition
   int* mergedNumbers = nullptr;

   int count = 0; // declare and initialize count

   mergePos = 0;
   mergedSize = k - i + 1;
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   mergedNumbers = new int[mergedSize];       // Dynamically allocates temporary array
                                              // for merged numbers
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {

      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
         count++; // comparsion count
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         count++; // comparsion count
      }
      ++mergePos;
      count++; // count
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
      count++; // count
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
      count++; // count
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }

   return count; // return value of count
}

int MergeSort(int numbers[], int i, int k) {
   int j;
   int count = 0; // declare and initialize count
   
   if (i < k) {
      count++;
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      count += MergeSort(numbers, i, j); // add count from MergeSort 
      count += MergeSort(numbers, j + 1, k); // add count from MergeSort 
      
      // Merge left and right partition in sorted order
      count += Merge(numbers, i, j, k); // add count form Merge 
   }
   return count;
}

