#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

//Crear struct para cada elemento del hash
typedef struct Hash_item {
    char* key;
    char* value;
} Hash_item;

//Crear struct para la Hashtable
typedef struct Hashtable {
    Hash_item** items;
    int size;
    int count;
} Hashtable;

//Constructor de hashtable
Hashtable* create_Hashtable(int size){
}
