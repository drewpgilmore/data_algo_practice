#include <stdio.h>
#include <stdlib.h>

// define node struct
typedef struct node {
    int data; 
    struct node *next; // pointer to next node
} node; 

// Implement Linked List
int main(void) {
    node *llist = NULL; // initiate pointing to NULL
    // prepend 10 random ints
    int length = 10;
    for (int i = 0; i < length; i++) {
        node *n = malloc(sizeof(node));
        n->data = rand() % 50; // get random int between 0 and 50
        n->next = llist; // make node point to llist (head)
        llist = n;
    }
    // iterate through list
    node *ptr = llist; // copy ll pointer for iteration
    while (ptr != NULL) {
        printf("%i -> ", ptr->data);
        ptr = ptr->next; // set pointer to next
    }
    printf("End\n");
}

// linkedList make(int length) {
//     // make list
//     node *llist = NULL;
//     // loop length times, prepend random int to list
//     for (int i = 0; i < length; i++) {
//         node *n = malloc(sizeof(node));
//         n->data = rand() % 50; // get random int between 0 and 50
//         n->next = llist; // make node point to llist (head)
//         llist = n;
//     }
//     return llist;
// }