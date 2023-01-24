#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// Default list length for testing
#define LIST_LENGTH 10

/* LINKED LIST IMPLEMENTATION FROM linkedlist.h 
    - Node struct = {.string = char *, .num = int .next = node *}
      node displays as "(node->string, node->num)"
    - printList() displays list elements starting
      with given node address onward along with 
      field to display ("string", "num", or "all")
*/
int main(void) {
    /* ------ INSTANTIATE ------ */
    // From given number of random nodes
    node *firstList = randomList(LIST_LENGTH);
    printList(&firstList, "all"); 

    // From array of nodes
    node head      = {.string = "head",      .num = 0};
    node shoulders = {.string = "shoulders", .num = 1};
    node knees     = {.string = "knees",     .num = 2};
    node toes      = {.string = "toes",      .num = 3};
    node sampleNodes[4] = {head, shoulders, knees, toes};
    node *secondList = fromArray(sampleNodes, 4);
    printList(&secondList, "string"); // head->shoulders->knees->toes-> End
    
    /* ------ VOID FUNCTIONS ------ */
    /*  - append() appends node to list
        - prepend() prepends node to list
        - delete() deletes node from list
        - insert() inserts node after specified node
        - reverse() reverses list */
    node first  = {.string = "first",  .num = 0};
    node middle = {.string = "middle", .num = 50};
    node last   = {.string = "last",   .num = 99};
    node *thirdList = &middle;
    prepend(&thirdList, &first); 
    append(&thirdList, &last); 
    printList(&thirdList, "string"); // first->middle->last->End

    node another = {.string = "another node!", .num = 75}; 
    insert(&thirdList, &another, &middle); // insert "another" after "middle"
    delete(&thirdList, &last);
    reverse(&thirdList);
    printList(&thirdList, "all"); // (another node!, 75)->(middle, 50)->(first, 0)->End

    /* ------ NON VOID FUNCTIONS ------ */
    /*  - tail() returns ptr to last node in list
        - length() returns number of nodes in list
        - traverseTo() returns ptr to node at given index */
    node *longList = randomList(1000);
    node *fifth = traverseTo(&longList, 4); 
    delete(&longList, fifth); 
    int len = length(&longList); 
    printf("%i\n", len); // 999
}