/* linkedlist.h                       */
/* Defines linked list data structure */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node struct */
typedef struct node {
    int data; 
    struct node *next;
} node; 

/* ************** */
/* Core functions */
/* Print list     */
void print(node *llist) {
    while (llist != NULL) {
        printf("%i -> ", llist->data);
        llist = llist->next;
    }
    printf("End\n");
}

/* Return length of list */
int length(node *llist) {
    if (llist == NULL) {
        return 0;
    }
    int length = 0;
    while (llist != NULL) {
        length++;
        llist = llist->next;
    }
    return length;
}

/* Return pointer to node at given index */
node *traverseTo(node *llist, int index) {
    node *iterator = llist;
    int i = 0;
    while (i < index) {
        iterator = iterator->next;
        i++;
    }
    return iterator;
}

/* Return pointer of last node in list */
node *lastNode(node *llist) {
    int index = length(llist) - 1;
    node *last = traverseTo(llist, index);
    return last;
}

/* Prepend node to list */
node *prepend(node *llist, node *n) {
    n->next = llist;
    llist = n; 
    return llist;
}

/* Append node to list */
void append(node *llist, node *n) {
    node *last = traverseTo(llist, length(llist) - 1); 
    last->next = n;
}

/* Delete node from list */
void delete(node *llist, node *target) {
    if (llist == target) { 
        llist = llist->next; 
    }
    node *iterator = llist;
    while (iterator->next != target) {
        iterator = iterator->next;
    }
    iterator->next = iterator->next->next;
}

/* Reverse list */
// node *reverse(node *llist) {
//     node *iterator = llist;
//     while (iterator != NULL) {
//         print(llist);
//         node *last = lastNode(llist);
//         delete(llist, last);
//         print(llist);
//         node *tmp = llist;
//         llist = last;
//         last->next = tmp;
//         print(llist);
//         iterator = iterator->next;
//     }
//     return llist;
// }

/* ************************************************ */
/* Testing Functions                                */
/* Generate linked list random ints of given length */
node *makeList(int length) {
    node *llist = NULL;
    for (int i = 0; i < length; i++) {
        node *n = malloc(sizeof(node));
        n->data = rand() % 50; /* random int between 1 and 50 */
        n->next = llist;
        llist = n;
    }
    return llist;
}