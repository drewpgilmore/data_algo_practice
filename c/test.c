#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

#define LIST_LENGTH 5000000

int main(void) {
    // Create list of random numbers
    node *llist = NULL;
    for (int i = 0; i < LIST_LENGTH; i++) {
        node *n = randomNumNode();
        prepend(&llist, n);
    }
    printList(&llist);
}