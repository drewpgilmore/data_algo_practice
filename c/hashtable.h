/* hashtable.h                       */
/* Defines hash table data structure */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

/* basic data struct for testing */
typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next;
} person; 

/* array of pointers to person structs */
/* indexes with multiple results will point to head of linked list */
person *hashTable[TABLE_SIZE];

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

void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("%i: ", i);
            while (hashTable[i] != NULL) {
                printf("%s (%i) -> ", hashTable[i]->name, hashTable[i]->age);
                hashTable[i] = hashTable[i]->next;
            }
            printf("End\n");
        } else {
            printf("%i: ---\n", i);
        }
    }
}

/* insert at end of linked list at hash index */
void insertPerson(person *p) {
    int index = hash(p->name);
    if (hashTable[index] != NULL) {
        /* go to end of list at index, insert */
        person *curr = hashTable[index]; 
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = p; 
    } else {
        hashTable[index] = p;
    }   
}



