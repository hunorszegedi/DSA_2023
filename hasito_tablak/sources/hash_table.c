//
// Created by Lenovo on 15/05/2023.
//

#include "hash_table.h"

int hashCode(int key) {
    return key & CAPACITY;
}

void createHashArray(HashTable *pHashTable) {
    pHashTable->items = (HashItem *) calloc(CAPACITY, sizeof(HashItem));
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
    if (hashTable->size >= CAPACITY) {
        printf("Hash table is full\n");
        return; //nincs szabad hely
    }
    int index = hashCode(key);
    HashItem item = {key, data};
    int i = 0;
    //% capacity, hogy ne haladjuk tul, ha netan a ++ olassal tulmennenk
    //vissza is jutunk az elejere
    while (hashTable->items[(index + i) % CAPACITY].key != dummyData.key) {
        i++;
    }
    hashTable->items[(index + i) % CAPACITY] = item;
    hashTable->size++;
}

int size(HashTable hashTable) {
    return hashTable.size;
}

//kiirjuk, hogy eloszor hova kellett volna keruljon s utana azt, hogy vegul hova kerult
void display(HashTable hashTable) {
    if (hashTable.size == 0) {
        printf("The hash table is empty!\n");
        return;
    }
    //capacity-ig megyunk, mert a size csak azt jelenti itt, hogy mennyi ertek van eddig benne
    printf("Index\t->\tKey\t->\tData\t->\tHash\n");
    for (int i = 0; i < CAPACITY; ++i) {
        if (hashTable.items[i].key != dummyData.key) {
            printf("%d\t->\t%d\t->\t%d\t->\t%d\n",
                   i, hashTable.items[i].key, hashTable.items[i].data, hashCode(hashTable.items[i].key));
        }
    }
    printf("\n\n");
}

int search(HashTable hashTable, int key) {
    int index = hashCode(key);
    int i = 0;
    //biztos, hogy nincs itt, mert akkor elhelyeztuk volna
    if (hashTable.items[index].key == dummyData.key) {
        return -1;
    }
    //kell egy extra feltetel, mert vegtelen ciklusba futhat
    //ha elertuk a capacity-t nincs miert tovabb keresni
    while (i < CAPACITY && hashTable.items[(index + i) % CAPACITY].key != key) {
        i++;
    }
    //ha korbementunk es nem talaltuk meg
    if (i == CAPACITY) {
        return -1;
    }
    //megtalaltuk ezen a pozicion az elemet
    return (index + i) % CAPACITY;
}

//visszaallitjuk dummy data-ra
void delete(HashTable *hashTable, int key) {
    int pos = search(*hashTable, key);
    if (pos == -1) {
        printf("Could NOT DELETE item with key: %d!\n", key);
        return;
    }
    hashTable->items[pos] = dummyData;
    hashTable->size--;
    printf("Item with key (%d) deleted!\n", key);
}

//felszabaditas
void destroyHashArray(HashTable *pHashTable) {
    pHashTable->size = 0;
    free(pHashTable->items);
    pHashTable = NULL;
}


