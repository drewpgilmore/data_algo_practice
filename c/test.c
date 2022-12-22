/* Testing of data structures */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {
    int sample = 5;
    node *llist = makeList(sample);
    
    /* Print */
    printf("Make list of length %i : ", sample);
    print(llist);

    /* Length */
    int l = length(llist);
    printf("Length of list = %i\n", l);

    /* Prepend & append */
    node *a = malloc(sizeof(node));
    a->data = 3;
    llist = prepend(llist, a);
    
    node *b = malloc(sizeof(node));
    b->data = 30;
    append(llist, b);

    printf("Prepending %i : ", a->data);
    print(llist);
    printf("Appending %i : ", b->data);
    print(llist);   

    /* Test traverse to */
    node *targetNode = traverseTo(llist, 3);
    printf("Node at index 3 is %i\n", targetNode->data);

    node *tail = lastNode(llist);
    printf("Tail node is %i\n", tail->data);

    /* Test delete node */
    int i = 4;
    node *n = traverseTo(llist, i); 
    delete(llist, n); 
    printf("Deleting node at index %i (%i) : ", i, n->data);
    print(llist);

    /* Test reverse */
    llist = reverse(llist); 
    printf("Reversing list : ");
    print(llist);

    
}