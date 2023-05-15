//
// Created by Lenovo on 15/05/2023.
//

#include "hash_table.h"

int hashCode(int key) {
    return key & CAPACITY;
}

void createHashArray(HashTable *pHashTable) {
    pHashTable->items = (HashTable *) calloc(CAPACITY, sizeof(HashTable));
    if (!pHashTable->items) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < CAPACITY; ++i) {
        pHashTable->items[i] = dummyData;
    }
    pHashTable->size = 0;
}

void insert(HashTable *hashTable, int key, int data) {
    if (hashTable->size >= CAPACITY) return; //nincs szabad hely
    int index = hashCode(key);
    HashItem item = {key, data};
    int i = 0;
    while (hashTable->items[(index + i) % CAPACITY].key != dummyData.key) {
        i++;
    }
    hashTable->items[(index + i) % CAPACITY] = item;
    hashTable->size++;
}

void display(HashTable hashTable) {
    printf("Hash table contents:\n");
    printf("\tPos\tkey\tvalue\n");
    for (int i = 0; i < hashTable.size; ++i) {
        HashItem item = hashTable.items[i];
        if (item.key != dummyData.key) {
            printf("\t%i \t%i \t%i\n", i, item.key, item.data);
        }
    }
}
