/* linkedlist.h                       */
/* Defines linked list data structure */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Node struct */
typedef struct node {
    char *string; 
    int num;
    struct node *next;
} node; 

/* CORE FUNCTIONS */
/* print */
/* prints selected field of each node in the list */
void print(node **llist, char *field) {
    node *iterator = *llist;
    if (strcmp(field, "num") == 0) {
        while (iterator != NULL) {
            printf("%i->", iterator->num);
            iterator = iterator->next;
        }
        printf("End\n");
        return;
    } else if (strcmp(field, "string") == 0) { 
        while (iterator != NULL) {
            printf("%s->", iterator->string);
            iterator = iterator->next;
        }
        printf("End\n");
        return;
    } else if (strcmp(field, "all") == 0) { 
        while (iterator != NULL) {
            printf("(%s, %i)->", iterator->string, iterator->num);
            iterator = iterator->next;
        }
        printf("End\n");
        return;
    } else {
        printf("invalid field entered in print function\n");
        return;
    }
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

/* tail of list */
/* return pointer to node that has node->next == NULL */
node *tail(node **llist) {
    node *iterator = *llist; 
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    return iterator; 
}

/* prepend node "n" */
void prepend(node **llist, node *n) {
    n->next = *llist;
    *llist = n;
}

/* append node "n" */
void append(node **llist, node *n) {
    node *iterator = *llist; 
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    iterator->next = n; 
}

/* insert node "n" after specified node "after" */
void insert(node **llist, node *n, node *after) {
    node *tmp = after->next;
    n->next = tmp; 
    after->next = n;
}

/* delete node */
/* removes target node "n" from list */
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
// void sort(node **llist, char *field) {
//     node *iterator = *llist; 
//     node *temp = malloc(sizeof(node));
    
//     if (strcmp(field, "num") == 0) {
//         while (iterator != NULL) {
//             node *curr, *next; 
//             curr = iterator;
//             next = iterator->next; 
//             if (curr->num > next->num) {
//                 temp = curr->num;
//                 curr->num = next->num;
//                 next->num = temp;
//                 iterator = *llist;
//             } else {
//                 iterator = iterator->next;
//             }
//         } return;
//     } else if (strcmp(field, "string") == 0) {
//         while (iterator != NULL) {
//             node *curr, *next; 
//             curr = iterator;
//             next = iterator->next; 
//             if (curr->string > next->string) {
//                 temp = curr->num;
//                 curr->string = next->string;
//                 next->string = temp;
//                 iterator = *llist;
//             } else {
//                 iterator = iterator->next;
//             }
//         } return;
//     } else {
//         printf("invalid field entered in sort function\n");
//     }
// }

/* reverse list */
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

/* TESTING FUNCTIONS */ 
/* generate list of random ints */
node *randomInts(int length) {
    node *llist = NULL;
    for (int i = 0; i < length; i++) {
        node *n = malloc(sizeof(node));
        n->string = "";
        n->num = rand() % 100; 
        n->next = llist;
        llist = n;
    }
    return llist;
}

/* generate list from array */
node *fromArray(node *arr, int len) {
    node *llist = NULL;
    for (int i = 0; i < len - 1; i++) {
        arr[i].next = &arr[i + 1]; 
    }
    llist = arr;
    return llist;
}

/* gets user input for creating new node */
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


/* get integer from user input for test.c 
    "options:\n"
        "1. quit\n"
        "2. prepend\n"  
        "3. append\n"
        "4. insert node\n"
        "5. delete node\n"
        "5. traverse to node\n"
        "6. sort\n"
        "7. reverse\n"; */
int selectAction() {
    int action;
    printf("choose action to perform (enter 1 to quit): ");
    scanf("%i", &action); 
    while (action == 0 || action > 7) {
        printf("invalid choice, please enter valid action: ");
        scanf("%i", &action);
    };
    return action;
}