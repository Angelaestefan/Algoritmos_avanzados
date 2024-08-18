#include <iostream>
#include "hash.h" 

void test_hash_table() {
    // Crear una nueva hash table
    Hashtable* table = create_Hashtable(10);

    // insertarle valores
    insert(table, "Angela", "18");
    insert(table, "Emilio", "34");
    insert(table, "David", "89");

    print_table(table);

   

    // Testear update
    update(table, "Angela", "19");
    print_table(table);
    
    // Testear delete
    delete_key(table, "David");
    print_table(table);

    // Testear load factor and resizing de la hash
    for (int i = 0; i < 20; i++) {
        char key[10], value[10];
        sprintf(key, "key%d", i);
        sprintf(value, "value%d", i);
        insert(table, key, value);
    }

    

    // Print the table
    print_table(table);

    // eliminar la hash table
    delete_table(table);

    std::cout << "All tests passed successfully!" << std::endl;
    
}

int main() {
    test_hash_table();
    return 0;
}