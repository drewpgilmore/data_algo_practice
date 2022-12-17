// place to test functionality
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {
    // implement list with random ints
    node llist = makeList(10);
    
    // iterate through list, print values
    node *ptr = &llist;
    while (ptr != NULL) {
        printf("%i -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("End\n");
}