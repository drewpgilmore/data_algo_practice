/* Testing of data structures */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "hashtable.h"

int main(void) {
    printf("-------------------\n");
    printf("TESTING LINKED LIST\n");
    int sample = 5;
    node *llist = makeList(sample);
    
    /* Print */
    printf("Make list of length %i : ", sample);
    print(&llist);

    /* Length */
    printf("Length of list = %i\n", length(&llist));

    /* Traverse to */
    printf("Traversing to node at index 3...");
    node *n = traverseTo(&llist, 3);
    printf("%i\n", n->data);

    /* Tail */
    node *t = tail(&llist);
    printf("Tail = %i\n", t->data);
    printf("Tail->next should be null ... %p\n", t->next);


    /* Prepend, append, insert, delete */
    prepend(&llist, 12); 
    printf("Prepending 12...");
    print(&llist);
    
    append(&llist, 33);
    printf("Appending 33...");
    print(&llist);
    
    node *insertNodeAfterMe = traverseTo(&llist, 4);
    insert(&llist, insertNodeAfterMe, 100); 
    printf("Inserting 100 at index 5...");
    print(&llist); 


    /* Reverse */
    printf("Reversing...");
    print(&llist);
    
    /* Sort */
    printf("Sorting...");
    sorted(&llist);
    print(&llist);

    /* **************** */
    /* Hash table       */
    /* init empty table */
    printf("------------------\n");
    printf("TESTING HASH TABLE\n");
    clearTable();
    
    person drew = {.name="Drew", .age=29};
    person lauren = {.name="Lauren", .age=29};
    person georgia = {.name="Georgia", .age=4};
    person clark = {.name="Clark", .age=2};
    person charlotte = {.name="Charlotte", .age=0};
    
    insertPerson(&drew);
    insertPerson(&charlotte);
    insertPerson(&clark);
    insertPerson(&lauren);
    insertPerson(&georgia);

    printTable();
}