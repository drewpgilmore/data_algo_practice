// Define linked list data structure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constraints for random node generation
#define NODE_MAX_INT 100
#define NODE_STRING_LEN 10

// Basic node structure
typedef struct node {
    void *value;
    struct node *next;
    void (*printNode)(struct node *n);
} node; 

// NODE FUNCTIONS
void printNum(node *n) {
    int *value = n->value;
    printf("%i", *value);
}

void printString(node *n) {
    char **value = n->value;
    printf("%s", *value);
}

// LINKED LIST FUNCTIONS
// Print all nodes in list
void printList(node **head) {
    node *iterator = *head;
    while (iterator != NULL) {
        iterator->printNode(iterator);
        printf(" -> ");
        iterator = iterator->next;
    }
    printf("End\n");
}

// Return number of nodes in list
int length(node **llist) {
    int length = 0;
    node *iterator = *llist;
    while (iterator != NULL) {
        length++;
        iterator = iterator->next;
    }
    return length;
}

// Return pointer to node at non-negative index
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

// Return pointer to last node in list
node *tail(node **llist) {
    if (*llist == NULL) {
        return 0;
    }
    node *iterator = *llist; 
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    return iterator; 
}

// Prepend node to list
void prepend(node **llist, node *n) {
    n->next = *llist;
    *llist = n;
}

// Append node to list
void append(node **llist, node *n) {
    node *iterator = *llist; 
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    iterator->next = n; 
}

// Insert node after specified node
void insert(node **llist, node *n, unsigned int index) {
    // Handle edge cases
    // Index out of range
    if (index >= length(llist)) {
        printf("Index out of range...");
        //append(llist, n);
        return;
    // Empty list
    } else if (*llist == NULL) {
        *llist = n;
        return;
    // Insert at beginning
    } else if (index == 0) {
        prepend(llist, n);
        return;
    // Insert at end
    } else if (index == length(llist) - 1) {
        append(llist, n);
        return;
    } 
    
    // Insert between before & after nodes
    node *before = traverseTo(llist, index - 1);
    node *after = traverseTo(llist, index);
    before->next = n;
    n->next = after;
}

// Delete node
void delete(node **llist, node *n) {
    if (n == *llist) {
        *llist = n->next;
        return; 
    }
    node *iterator = *llist; 
    while (iterator->next != n) {
        iterator = iterator->next; 
    }
    iterator->next = iterator->next->next;
}

// Reverse list
void reverse(node **llist) {
    node *prev = NULL; 
    node *curr = *llist;
    node *next = NULL; 
    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev; 
        prev = curr;
        curr = next; 
    }
    *llist = prev;
}

// TEST FUNCTIONS
// Generate list from array of nodes
node *fromArray(node *arr, int length) {
    node *llist = NULL;
    for (int i = 0; i < length - 1; i++) {
        arr[i].next = &arr[i + 1]; 
    }
    llist = arr;
    return llist;
}

// Generate random integer node
node *randomNumNode() {
    node *n = malloc(sizeof(node));
    int *num = malloc(sizeof(int));
    *num = rand() % NODE_MAX_INT; 
    n->value = num;
    n->printNode = printNum;
    return n;
}

// Generate random string
char *randomString() {
    char charset[] = "abcdefghijklmnopqrstuvwxyz";
    int length = rand() % NODE_STRING_LEN;
    if (length <= 1) {length = 2;} 
    char *str = malloc(NODE_STRING_LEN);
    for (int i = 0; i < length; i++) { 
        int key = rand() % (sizeof charset - 1);
        str[i] = charset[key];
    }
    str[length] = '\0';
    return str;
}

// Generate random string node
node *randomStringNode() {
    node *n = malloc(sizeof(node));
    char **str = malloc(sizeof(NODE_STRING_LEN));
    *str = randomString();
    n->value = str;
    n->printNode = printString;
    return n;
}