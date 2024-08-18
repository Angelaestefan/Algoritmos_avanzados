#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>


using namespace std;


#ifndef HASH_H
#define HASH_H

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

//Destructors deletion methods

void delete_item(Hash_item* item){
    // Liberar el espacio en memoria de cada item struct
    free(item->key);
    free(item->value);
    free(item);
}

void delete_table(Hashtable* h_table) {
    if (h_table == NULL) return; // Verificar que la tabla no sea NULL

    // Iterar por cada item para liberar el espacio en memoria del mismo
    for (int i = 0; i < h_table->size; i++) {
        Hash_item* item = h_table->items[i];

        if (item != NULL) {
            delete_item(item);
        }
    }

    free(h_table->items); // Liberar la memoria de los items
    h_table->items = NULL; // Prevenir uso después de liberar

    free(h_table); // Liberar la memoria de la tabla hash
    h_table = NULL; // Prevenir uso después de liberar
}


//Hash function

unsigned int hash_function(const char* key, int table_size) {
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key); // calcular el length del key

    for (; i < key_len; ++i) { //itera sobre cada caracter de la key
        value = value * 37 + key[i]; // multiplica el valor actual por 37 y le añade el valor ASCII DEL valor actual
    }

    value = value % table_size; //asegurar de que el valor este dentro del rango de la tabla
    return (unsigned int)value; //regresa el valor
}


// Insert method
void insert(Hashtable* table, const char* key, const char* value) {
    // Check si el load factor excede .80, para crear una nueva hash table con el valor necesario
    if ((float)(table->count + 1) / table->size > 0.8) {
        // Resize the table
        int new_size = table->size * 2; //aumentar al doble el tamaño de la tabla
        Hashtable* new_table = create_Hashtable(new_size); //crear la nueva hash con el tamaño necesario
        
        for (int i = 0; i < table->size; i++) { //insetar a la new_table los valores de table
            if (table->items[i] != NULL) {
                insert(new_table, table->items[i]->key, table->items[i]->value);
            }
        }
        
        Hashtable temp = *table;
        *table = *new_table;
        *new_table = temp;
        delete_table(new_table); // eliminar la antigua hash table
    }

    unsigned int index = hash_function(key, table->size);
    Hash_item* item = create_item((char*)key, (char*)value);

    // Linear probing
    while (table->items[index] != NULL) {
        index = (index + 1) % table->size;
    }

    table->items[index] = item;
    table->count++;
}

// Search method
char* search(Hashtable* table, const char* key) {
    unsigned int index = hash_function(key, table->size);
    Hash_item* item = table->items[index];
    int i = 0;

    while (item != NULL) {
        if (strcmp(item->key, key) == 0) {
            return item->value;
        }
        index = (index + 1) % table->size;
        item = table->items[index];
        if (i++ > table->size) break; // Prevent infinite loop
    }
    return NULL;
}   


// Delete method
void delete_key(Hashtable* table, const char* key) {
    unsigned int index = hash_function(key, table->size);
    Hash_item* item = table->items[index];
    int i = 0;

    while (item != NULL) {
        if (strcmp(item->key, key) == 0) {
            delete_item(item);
            table->items[index] = NULL;
            table->count--;
            return;
        }
        index = (index + 1) % table->size;
        item = table->items[index];
        if (i++ > table->size) break; // Prevent infinite loop
    }
}

// Update method
void update(Hashtable* table, const char* key, const char* value) {
    unsigned int index = hash_function(key, table->size);
    Hash_item* item = table->items[index];
    int i = 0;

    while (item != NULL) {
        if (strcmp(item->key, key) == 0) {
            free(item->value);
            item->value = (char*)malloc(strlen(value) + 1);
            strcpy(item->value, value);
            return;
        }
        index = (index + 1) % table->size;
        item = table->items[index];
        if (i++ > table->size) break; // Prevent infinite loop
    }
}

// Print method (for debugging)
void print_table(Hashtable* table) {
    printf("\nHash Table\n-------------------\n");
    for (int i = 0; i < table->size; i++) {
        if (table->items[i]) {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("-------------------\n\n");
}

#endif