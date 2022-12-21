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

/* Linked list core funcstions */
/* 
    print
    insert nodes
    delete nodes
    reverse
    sort
    traverse
*/

/* Print list */
void print(node *llist) {
    while (llist != NULL) {
        printf("%i -> ", llist->data);
        llist = llist->next;
    }
    printf("End\n");
}

/* Get length of list */
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

/* Get pointer to node at given index */
node *traverseTo(node *llist, int index) {
    node *iterator = llist;
    int i = 0;
    while (i < index) {
        iterator = iterator->next;
        i++;
    }
    return iterator;
}

/* Append or prepend node       */
/* Method "prepend" or "append" */
void addNode(node *llist, node *n, char *method) {
    //node *n = malloc(sizeof(node));
    //n->data = i;
    if (strcmp(method, "prepend") == 0) {
        node *tmp = llist;
        llist = n;
        n->next = tmp;
    } 
    else if (strcmp(method, "append") == 0) {
        node *last = traverseTo(llist, length(llist) - 1);
        last->next = n;
    } else {
        printf("Invalid method entered\nEnter 'prepend' or 'append'\n");
    }
}

/* Delete node from list */
void deleteNode(node *llist, node *target) {
    if (llist == target) { 
        llist = llist->next; 
        //return llist;
    }
    
    node *iterator = llist;
    while (iterator->next != target) {
        iterator = iterator->next;
    }
    iterator->next = iterator->next->next;
    //return llist;
}

/* Reverse list */
void reverse(node *llist) {
    
}



// node *sort(node *llist, char *method) {
//     // sorts list according to "method"
//     // method = "ascending" or "descending"
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