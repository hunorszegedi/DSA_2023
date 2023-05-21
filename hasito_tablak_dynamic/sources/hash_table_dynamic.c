//
// Created by Lenovo on 20/05/2023.
//

#include "hash_table_dynamic.h"

HashItem createHashItem(char *key, char *data);

int hashCode(char *key) {
    int bucketIndex;
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); ++i) {
        sum = (((sum % CAPACITY) + (((int) key[i]) * factor) % CAPACITY)) % CAPACITY;
        factor = ((factor % __INT16_MAX__)
                  * (31 % __INT16_MAX__))
                 % __INT16_MAX__;
    }
    bucketIndex = sum;
    return bucketIndex;
}

void createHashArray(HashTable *pHashTable) {
    for (int i = 0; i < CAPACITY; ++i) {
        pHashTable->items[i] = NULL;
    }

}

void insert(HashTable *hashTable, char *key, char *data) {
    int index = hashCode(key);
    printf("key (%s) -> index (%d)\n", key, index);
    insertFirst(&hashTable->items[index], createHashItem(key, data));
}

void display(HashTable hashTable) {
    for (int i = 0; i < CAPACITY; ++i) {
        if (hashTable.items[i] != NULL) {
            printf("%i index has the following list items:\n", i);
            printList(hashTable.items[i]);
            printf("\n");
        }
    }

}

bool search(HashTable hashTable, char *key) {
    int index = hashCode(key);
    return searchNode(hashTable.items[index], key);
}

void delete(HashTable *hashTable, char *key) {
    int index = hashCode(key);
    if (!search(*hashTable, key)) {
        printf("Could not delete key (%s)\n", key);
        return;
    }
    deleteNode(&hashTable->items[index], key);
    printf("Item with key (%s) deleted!\n", key);

}

void destroyHashArray(HashTable *pHashTable) {
    for (int i = 0; i < CAPACITY; ++i) {
        freeList(&pHashTable->items[i]);
        pHashTable->items[i] = NULL;
    }
    pHashTable = NULL;
}

HashItem createHashItem(char *key, char *data) {
    HashItem result;
    strcpy(result.key, key);
    strcpy(result.data, data);
    return result;
}
