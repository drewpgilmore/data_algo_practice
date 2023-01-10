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
void print(node **llist) {
    node *current = *llist;
    while (current != NULL) {
        printf("%i -> ", current->data);
        current = current->next;
    }
    printf("End\n");
}

/* Return length of list */
int length(node **llist) {
    int length = 0;
    node *current = *llist;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

/* Return pointer to node at given index */
node *traverseTo(node **llist, int index) {
    if (index > length(llist)) {
        printf("Index out of range!");
    }
    node *iterator = *llist;
    int i = 0;
    while (i < index) {
        iterator = iterator->next;
        i++;
    }
    return iterator;
}

/* Return pointer of last node in list */
node *tail(node **llist) {
    int index = length(llist) - 1;
    node *last = traverseTo(llist, index);
    return last;
}

/* Prepend node to list */
void prepend(node **llist, int i) {
    node *n = malloc(sizeof(node)); 
    n->data = i; 
    n->next = *llist;
    *llist = n;
}

/* Append node to list */
void append(node **llist, int i) {
    node *n = malloc(sizeof(node)); 
    n->data = i; 
    n->next = NULL;
    node *t = tail(llist);
    t->next = n;
}

/* Inserts node with data i after given node */
void insert(node **llist, node *after, int i) {
    node *new = malloc(sizeof(node)); 
    new->data = i;
    node *tmp = malloc(sizeof(node)); 
    tmp = after->next;
    new->next = tmp; 
    after->next = new;
}
/* Delet node */
void delete(node **llist, node *n) {
    node *iterator = *llist; 
    while (iterator->next != n) {
        iterator = iterator->next; 
    }
    iterator->next = iterator->next->next; 
}

/* bubble sort ascending */
void sorted(node **llist) {
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
        n->data = rand() % 50; /* random int between 1 and 50 */
        n->next = llist;
        llist = n;
    }
    return llist;
}

/* Generate list from array */
node *fromArray(int a[], int len) {
    node *head = malloc(sizeof(node));
    head->data = a[0];
    node *llist = head;
    for (int i = 1; i < len; i++) {
        append(&llist, a[i]);
    }
    return llist;
}