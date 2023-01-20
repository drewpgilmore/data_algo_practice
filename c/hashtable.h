/* hashtable.h                       */
/* Defines hash table data structure */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

#define MAX_NAME 256
#define TABLE_SIZE 10

/* basic data struct for testing */
// typedef struct person{
//     char name[MAX_NAME];
//     int age;
//     struct person *next;
// } person; 

/* array of pointers to structs */
/* indexes with multiple results will point to head of linked list */
node *hashTable[TABLE_SIZE];

/* basic function to return int of first char + 1 */
unsigned int hash(char *name) {
    int h = name[0] % TABLE_SIZE + 1;
    return h;
}

/* make all table pointers NULL */
void clearTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

/* display table with lists at each index */
void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("%i: ", i);
            printList(&hashTable[i], "all");
        } else {
            printf("%i: ---\n", i);
        }
    }
}

/* insert at end of linked list at hash index */
void insertPerson(node *person) {
    char *name = person->string; 
    int age = person->num;
    int index = hash(name);
    if (hashTable[index] != NULL) {
        append(&hashTable[index], person);
    } else {
        hashTable[index] = person;
    }   
}

/* search table for given name */
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



