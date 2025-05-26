#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hashTable[SIZE];
int isEmpty = 1;

void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = index;
    while (hashTable[i] != -1) {
        i = (i + 1) % SIZE;
        if (i == index) {
            printf("Hash table is full\n");
            return;
        }
    }
    hashTable[i] = key;
    isEmpty = 0;
}

int search(int key) {
    int index = hashFunction(key);
    int i = index;
    while (hashTable[i] != -1) {
        if (hashTable[i] == key) {
            return i;
        }
        i = (i + 1) % SIZE;
        if (i == index) {
            break;
        }
    }
    return -1;
}

void delete(int key) {
    int index = search(key);
    if (index == -1) {
        printf("Key %d not found\n", key);
        return;
    }
    hashTable[index] = -1;
}

void display() {
    if (isEmpty) {
        printf("Hash table is empty\n");
        return;
    }
    printf("Hash Table: ");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("[%d]:%d ", i, hashTable[i]);
        } else {
            printf("[%d]:- ", i);
        }
    }
    printf("\n");
}

int main() {
    initTable();
    insert(15);
    insert(25);
    insert(35);
    insert(45);
    insert(5);
    display();
    int key = 25;
    int result = search(key);
    if (result != -1) {
        printf("Key %d found at index %d\n", key, result);
    } else {
        printf("Key %d not found\n", key);
    }
    delete(25);
    display();
    return 0;
}
