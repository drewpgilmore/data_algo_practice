/* linkedlist.h                       */
/* Defines linked list data structure */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Node struct */
typedef struct node {
    char *name; 
    int age;
    int data; 
    struct node *next;
} node; 

/* ************** */
/* Core functions */
/* Print list     */
void print(node **llist) {
    node *iterator = *llist;
    while (iterator != NULL) {
        //printf("%i->", current->data);
        printf("%s (%i)->", iterator->name, iterator->age);
        iterator = iterator->next;
    }
    printf("End\n");
}

/* length of list */
/* add 1 to counter with each node, return counter int */
int length(node **llist) {
    int length = 0;
    node *iterator = *llist;
    while (iterator != NULL) {
        length++;
        iterator = iterator->next;
    }
    return length;
}

/* traverse to index */
/* return pointer to node at given (non negative) index */
node *traverseTo(node **llist, unsigned int index) {
    if (index > length(llist)) {
        printf("Index out of range!");
        return 0;
    } else if (index == 0) {
        return *llist;
    }
    node *iterator = *llist;
    int i = 0;
    while (i < index) {
        iterator = iterator->next;
        i++;
    }
    return iterator;
}

/* tail of llist */
/* return pointer to node that has .next == NULL */
node *tail(node **llist) {
    node *iterator = *llist; 
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    return iterator; 
}

/* Prepend node to list */
/* make .next of node "n" = head of llist, make llist point to node "n" */
void prepend(node **llist, node *n) {
    n->next = *llist;
    *llist = n;
}

/* Append node to list */
/* traverse to node where .next == NULL, assign node "n" to .next */
void append(node **llist, node *n) {
    node *iterator = *llist; 
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    iterator->next = n; 
}

/* insert node */
/* inserts node "n" after given node "after" */
void insert(node **llist, node *n, node *after) {
    node *tmp = after->next;
    n->next = tmp; 
    after->next = n;
}
/* delete node */
/* removes target node "n" from llist */
void delete(node **llist, node *n) {
    if (n == *llist) {
        *llist = n->next; // move head to n->next if n is head
        return; 
    }
    node *iterator = *llist; 
    while (iterator->next != n) {
        iterator = iterator->next; 
    }
    iterator->next = iterator->next->next;
}

/* bubble sort ascending */
void sort(node **llist) {
    node *i = *llist; 
    int temp;
    while (i->next != NULL) {
        node *curr, *next; 
        curr = i;
        next = i->next; 
        if (curr->data > next->data) {
            temp = curr->data;
            curr->data = next->data;
            next->data = temp;
            i = *llist;
        } else {
            i = i->next;
        }
    }
}

/* Reverse list */
void reverse(node **head) {
    node *prev = NULL; 
    node *curr = *head;
    node *next = NULL; 
    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev; 
        prev = curr;
        curr = next; 
    }
    *head = prev;
}

/* ************************************************ */
/* Testing Functions                                */
/* Generate linked list random ints of given length */
node *makeList(int length) {
    node *llist = NULL;
    for (int i = 0; i < length; i++) {
        node *n = malloc(sizeof(node));
        n->data = rand() % 100; /* random int between 1 and 50 */
        n->next = llist;
        llist = n;
    }
    return llist;
}

/* Generate list from array */
node *fromArray(node *arr, int len) {
    node *llist = NULL;
    for (int i = 0; i < len - 1; i++) {
        arr[i].next = &arr[i + 1]; 
    }
    llist = arr;
    return llist;
}

/* get integer from user input for test.c */
// int selectAction() {
//     int action;
//     char *actions = 
//         "options:\n"
//           "1. append\n"  
//           "2. prepend\n"
//           "3. insert node\n"
//           "3. reverse\n" 
//           "9. quit\n";
//     printf("%s\nchoose action to perform: ", actions);
//     scanf("%c", &action); 
//     return action;
// }