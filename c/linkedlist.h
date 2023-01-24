// Define linked list data structure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Variables for random node generation
#define NODE_STRING 10
#define NODE_NUM 100

// Defines node structure that list will hold
typedef struct node {
    char *string; 
    int num;
    struct node *next;
} node; 

/* ------ FUNCTIONS ------ */ 
// Display contents of list
// field = "string", "num", or "all"
void printList(node **head, char *field) {
    node *iterator = *head;
    if (strcmp(field, "num") == 0) {
        while (iterator != NULL) {
            printf("%i -> ", iterator->num);
            iterator = iterator->next;
        }
        printf("End\n");
        return;
    } else if (strcmp(field, "string") == 0) { 
        while (iterator != NULL) {
            printf("%s -> ", iterator->string);
            iterator = iterator->next;
        }
        printf("End\n");
        return;
    } else if (strcmp(field, "all") == 0) { 
        while (iterator != NULL) {
            printf("(%s, %i) -> ", iterator->string, iterator->num);
            iterator = iterator->next;
        }
        printf("End\n");
        return;
    } else {
        printf("invalid field entered in print function\n");
        return;
    }
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
void insert(node **llist, node *n, node *after) {
    node *tmp = after->next;
    n->next = tmp; 
    after->next = n;
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

/* ------ TESTING FUNCTIONS ------ */ 
// Generate list from array of nodes
node *fromArray(node *arr, int length) {
    node *llist = NULL;
    for (int i = 0; i < length - 1; i++) {
        arr[i].next = &arr[i + 1]; 
    }
    llist = arr;
    return llist;
}

// Generate node with random string and int
// Constrained by NODE_STRING and NODE_NUM
node *randomNode() {
    node *n = malloc(sizeof(node));
    char charset[] = "abcdefghijklmnopqrstuvwxyz";
    int length = rand() % NODE_STRING; 
    if (length <= 1) {length = 2;}
    char *str = malloc(length);
    for (int i = 0; i < length; i++) { 
        int key = rand() % (sizeof charset - 1);
        str[i] = charset[key];
    }
    str[length] = '\0';
    n->string = str; 
    n->num = rand() % NODE_NUM; 
    return n;
}

// Generate list of random nodes
node *randomList(int length) {
    node *llist = randomNode();
    for (int i = 0; i < length - 1; i++) { 
        node *n = randomNode();
        append(&llist, n);
    }
    return llist;
}

// Generate node from user input 
// strAlias and numAlias indicate intended context of .string and .num
node inputNode(char *strAlias, char *numAlias) {
    char *string; 
    int num;
    printf("enter a %s: ", strAlias);
    scanf("%s", string); 
    printf("enter a %s: ", numAlias);
    scanf("%i", &num); 
    node n = {.string = string, .num = num}; 
    return n;
}