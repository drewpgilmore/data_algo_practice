/* Testing of data structures */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {
    node *llist = makeList(10);
    
    /* Test print */
    print(llist);

    /* Test length */
    int l = length(llist);
    printf("Length is %i\n", l);

    /* Test traverse to */
    int index = 3;
    node *targetNode = traverseTo(llist, index);
    printf("Node at index %i is %i\n", index, targetNode->data);

    /* Test add node */
    llist = addNode(llist, 3, "append");
    llist = addNode(llist, 12, "prepend");
    llist = addNode(llist, 14, "faulty input");
    print(llist);

    /* Test delete node */
    node *n = traverseTo(llist, 4); 
    printf("Deleting node %i\n", n->data);
    llist = deleteNode(llist, n); 
    print(llist);

}