// Define hash table data structure
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h" 

#define MAX_NAME 256
#define TABLE_SIZE 20

// Array of pointers to lists of entries
node *hashTable[TABLE_SIZE];

// Hash function
unsigned int hash(char *name) {
    int h = name[0] % TABLE_SIZE;
    return h;
}

// Instantiates empty hash table
void clearTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Display elements of hash table
void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("%i: ", i);
            printList(&hashTable[i], "string");
        } else {
            printf("%i: ---\n", i);
        }
    }
}

// Insert in table at index or at end of list at index
// Nodes are inserted alphabetically based on .string
void insertPerson(node *person) {
    char *name = person->string; 
    int age = person->num;
    int index = hash(name);
    if (hashTable[index] != NULL) {
        if (strcmp(name, hashTable[index]->string) < 0) {
            prepend(&hashTable[index], person);
        } else {
            node *i = hashTable[index]; 
            while (i->next != NULL) {
                if (strcmp(name, i->next->string) < 0) {
                    insert(&hashTable[index], person, i);
                    return;
                } else {
                    i = i->next;
                }
            }
            append(&hashTable[index], person);
            return;
        }
    } else {
        hashTable[index] = person;
    }   
}

// Search table for input string
node *search(char *name) {
    int h = hash(name);
    printf("%i", h); 
    if (hashTable[h] == NULL) {
        printf("Person not found");
        return 0; 
    }
    node *person = hashTable[h];
    while (person != NULL) {
        if (strcmp(person->string, name) == 0) {
            printf("Found person at table index %i\n", h);
            return person;
        } else {
            person = person->next;
        }
    } 
    printf("Person not found");
    return 0;
}