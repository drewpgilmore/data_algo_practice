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
    int i = 0;
    while (i < index) {
        llist = llist->next;
        i++;
    }
    return llist;
}

/* Append or prepend node       */
/* Method "prepend" or "append" */
node *addNode(node *llist, int i, char *method) {
    node *n = malloc(sizeof(node));
    n->data = i;
    if (strcmp(method, "prepend") == 0) {
        node *tmp = llist;
        llist = n;
        n->next = tmp;
        return llist;
    } 
    else if (strcmp(method, "append") == 0) {
        node *last = traverseTo(llist, length(llist) - 1);
        last->next = n;
        return llist;
    } else {
        printf("Invalid method entered\nEnter 'prepend' or 'append'\n");
        return llist;
    }
}

/* Delete node from list */
node *deleteNode(node *llist, node *target) {
    if (llist == target) { 
        llist = llist->next; 
        return llist;
    }
    
    node *iterator = llist;
    while (iterator->next != target) {
        iterator = iterator->next;
    }
    iterator->next = iterator->next->next;
    return llist;
}

/* Reverse list */
// node *reverse(node *llist) {
//     for (int i = 0; i < length(llist); i++) {
//         node *tmp = malloc(sizeof(node));

//         llist = traverseTo(llist, length(llist) - 1);
//         //free(tmp);
//     }
//     return llist;
// }


// node *insertBefore(node *llist, node n, node before) {
//     // inserts node "n" before node "before"
//     return llist;
// }

// bool contains(node *llist, node n) {
//     // returns bool if node "n" is in list
//     return 0;
// }

// node *deleteNode(node *llist, node n, char *method) {
//     // deletes node "n" from llist according to "method"
//     // method = "any" deletes all instances of node "n"
//     // method = "first" deletes first instance of node "n"
//     return llist;
// }

// node *reverse(node *llist) {
//     // reverses llist without creating new list
//     return llist;
// }

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