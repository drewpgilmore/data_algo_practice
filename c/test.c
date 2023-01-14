/* Testing of data structures */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linkedlist.h"

#define MAX_STRING 256

int main(void) {
    int sampleLength, num, index, action;
    char string[MAX_STRING];
    node n;
    char *actions = 
        "options:\n"
            "1. quit\n"
            "2. prepend\n"  
            "3. append\n"
            "4. insert node\n"
            "5. delete node\n"
            "5. traverse to node\n"
            "6. sort\n"
            "7. reverse\n";

    printf("----------------------------------------------\n");  
    printf("* LINKED LIST IMPLENTATION FROM linkedlist.h *\n");
    printf("----------------------------------------------\n");
    printf("\nenter length of sample list to generate: ");
    scanf("%i", &sampleLength);
    node *llist = randomInts(sampleLength);
    printf("\n llist = ");
    print(&llist, "num");
    printf("%s\n", actions);
    action = selectAction();
    while (action != 1) {
        printf("\n");
        if (action == 2) {
            n = inputNode("name", "age"); 
            prepend(&llist, &n);
        } else if (action == 3) {
            n = inputNode("name", "age"); 
            append(&llist, &n);
        } else if (action == 4) {
            n = inputNode("name", "age"); 
            printf("insert at index = ");
            scanf("%i", &index);
            node *after = traverseTo(&llist, index - 1);
            insert(&llist, &n, after);
        } else if (action == 5) {
            printf("delete node at index = ");
            scanf("%i", &index);
            node *target = traverseTo(&llist, index);
            //printf("appending %i to llist...\n", num);
            delete(&llist, target);
        } else if (action == 6) {
            printf("sort function is under construction");
        } else if (action == 7) {
            printf("reversing llist...\n");
            reverse(&llist);
        } else {
            printf("invalid input -- please enter different action\n");
            //fflush(stdin); 
            action = selectAction();
        }
        printf("\n llist = ");
        print(&llist, "all");
        printf("\n");
        //fflush(stdin); 
        action = selectAction();
    }
    printf("test complete!\n");
    //free(llist);
    return 0;
}