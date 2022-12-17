// linkedlist.h
// headers for node struct and linkedlist core functions

typedef struct node {
    int data; 
    struct node *next;
} node; 

// testing functions
node *makeList(int length) {
    node *llist = NULL;
    for (int i = 0; i < length; i++) {
        node *n = malloc(sizeof(node));
        n->data = rand() % 50;
        n->next = llist;
        llist = n;
    }
    return llist;
}

// core functions
node *llist(int arr[]) {
    // returns linked list from array of ints
    
}

int length(node *llist) {
    // returns length of list
    // node *ptr = &llist;
    // while (ptr != NULL) {
    //     printf("%i -> ", ptr->data);
    //     ptr = ptr->next;
    // }
    // printf("End\n");
    return 1
}

char *print(node *llist) {
    // prints list
    return "list string"
}

node *traverseTo(node *llist, int index) {
    // returns pointer to node at index
    return node
}

node *append(node *llist, node n) {
    // appends node "n" to list
    return llist
}

node *insertBefore(node *llist, node n, node before) {
    // inserts node "n" before node "before"
    return llist
}

bool contains(node *llist, node n) {
    // returns bool if node "n" is in list
    return 0
}

node *deleteNode(node *llist, node n, char *method) {
    // deletes node "n" from llist according to "method"
    // method = "any" deletes all instances of node "n"
    // method = "first" deletes first instance of node "n"
    return llist
}

node *reverse(node *llist) {
    // reverses llist without creating new list
    return llist
}

node *sort(node *llist, char *method) {
    // sorts list according to "method"
    // method = "ascending" or "descending"
    return llist
}

