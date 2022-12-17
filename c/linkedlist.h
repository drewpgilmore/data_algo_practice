#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data; 
    struct node *next;
} node; 

node makeList(int length) {
    node *llist = NULL;
    for (int i = 0; i < length; i++) {
        node *n = malloc(sizeof(node));
        n->data = rand() % 50;
        n->next = llist;
        llist = n;
    }
    return *llist;
}