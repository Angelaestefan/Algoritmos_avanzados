/*
Created by Juan Avalos, Roberto Morales, Angela Aguilar y Benjamin Ortiz
12 / 08 / 2024
*/

#include <iostream>
using namespace std;


void merge (double [] , int , int , int); // O(n)

void mergeSort (double [], int, int); // O(n log n)

// Helps the MergeSort to create sub-arrays from a previous array. It compares them, and insert the sorted values into the previous array
void merge ( double array[], int left, int pivot, int right) {

    // Creation of sub-arrays
    int leftArrayL = pivot - left + 1;
    int rightArrayL = right - pivot;

    double leftArray [leftArrayL];
    double rightArray [rightArrayL];

    // Copies data from the previous array into the sub-arrays
    for (int i = 0; i < leftArrayL; i++){ // O(n)
        leftArray[i] = array [left + i];
    }

    for (int j = 0; j < rightArrayL; j++){ // O(n)
        rightArray[j] = array [pivot + 1 + j];
    }

    // Compares both sub-arrays, sorts and insert them in the previous array (merges the sub-arrays)
    int indexL = 0;
    int indexR = 0;
    int indexP = left;

    while (indexL < leftArrayL && indexR < rightArrayL){ // O(n)
        
        if (leftArray[indexL] <= rightArray[indexR]){
            array [indexP] = leftArray[indexL];
            indexL ++;
        }
        
        else {
            array [indexP] = rightArray[indexR];
            indexR ++;
        }
        indexP ++;
    }

    // If there are remaining elements in one of the sub-arrays, they will be added into the previous array
    while (indexL < leftArrayL){ // O(n)
        array [indexP] = leftArray[indexL];
        indexL ++;
        indexP ++;
    }

    while ( indexR < rightArrayL){ // O(n)
        array [indexP] = rightArray[indexR];
        indexR ++;
        indexP ++;
    }
};

// Divides the array until it becomes a set of sub-arrays with only 1 value(Base Case).Uses merge() to to sort and merge the sub-arrays
void mergeSort (double array[], int left, int right){
    
    // Base Case
    if (left >= right) {
        return;
    }

    int pivot = left + (right - left) / 2;
    
    // Division Case
    mergeSort (array, left, pivot);
    mergeSort (array, pivot + 1, right);
    
    // Conquest Case
    merge(array, left, pivot, right);
};