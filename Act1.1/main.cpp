/*
Created by Juan Avalos, Roberto Morales, Angela Aguilar y Benjamin Ortiz
12 / 08 / 2024
*/


#include "MergeSort.h"
#include <iostream>
using namespace std;


int main () {
    
    int n;
    cout << "Digite el tamaño del arreglo (n) : " << endl;
    cin >> n ;

    auto* array = new double[n];
    
    for (int i = 0; i < n; i++){
        double num;
        cout << "Digite el numero que desea agregar al arreglo:" << endl;
        cin >> num;
        array[i] = num;
    }

    cout << "El arreglo sin ordenar es el siguiente:" << endl;

    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    cout <<  "\n" << endl;

    mergeSort (array, 0, n - 1);

    cout << "El arreglo ya ordenado es el siguiente:" << endl;

    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    cout << endl;


    delete[] array;
    return 0;
};