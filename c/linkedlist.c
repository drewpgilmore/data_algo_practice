#include <stdio.h>
#include <stdlib.h>

// define node struct
typedef struct node {
    int data; 
    struct node *next;
} node; 

node makeList(int length);

int main(void) {
    // implement linked list of given length
    node llist = makeList(10);
    
    // iterate through list to print out contents
    node *ptr = &llist;
    while (ptr != NULL) {
        printf("%i -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("End\n");
}

node makeList(int length) {
    // initiate pointer to NULL (tail of list)
    node *llist = NULL;
    // loop length times, prepend random int to list
    for (int i = 0; i < length; i++) {
        node *n = malloc(sizeof(node));
        n->data = rand() % 50;
        n->next = llist;
        llist = n;
    }
    return *llist;
}