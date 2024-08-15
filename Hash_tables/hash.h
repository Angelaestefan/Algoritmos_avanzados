#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>


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

//CRUD IMPLEMENTATION
//Constructor elemento de hash
Hash_item* create_item(char* key, char* value){
    Hash_item* item = (Hash_item*) malloc(sizeof(Hash_item));
    item->key = (char*) malloc(strlen(key) + 1);
    strcpy(item->key, key);
    item->value = (char*) malloc(strlen(value) + 1);
    strcpy(item->value, value);
    return item;
}

//Constructor de hashtable
Hashtable* create_Hashtable(int size){
    Hashtable* h_table =(Hashtable*) malloc(sizeof(Hashtable));
    h_table -> size = size;
    h_table ->count = 0;
    h_table->items = (Hash_item**) calloc(h_table->size, sizeof(Hash_item*));

    for (int i = 0; i < h_table->size; i++)
        h_table->items[i] = NULL;

    return h_table;
}


