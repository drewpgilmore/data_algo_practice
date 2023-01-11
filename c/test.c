/* Testing of data structures */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "hashtable.h"

int main(void) {
    printf("LINKED LIST IMPLENTATION FROM linkedlist.h\n");
    printf("------------------------------------------\n");
    printf("enter length of sample list to generate: ");
    int sampleLength, data, index;
    scanf("%i", &sampleLength);
    node *llist = makeList(sampleLength);
    printf("\n llist = ");
    print(&llist);
    printf("\n");
    printf("actions:\n0. quit\n1. prepend node\n2. append node\n3. reverse\n");
    printf("\nenter action: ");
    int option;
    scanf("%i", &option); 
    while (option != 0) {
        if (option > 3) {
            printf("please enter valid option 0 - 3: ");
            scanf("%d", &option);
        } else {
            if (option == 1) {
                printf("enter value to prepend: ");
                scanf("%i", &data);
                prepend(&llist, data);
                printf("prepending %i to llist...\n", data);
            } else if (option == 2) {
                printf("enter value to append: ");
                scanf("%i", &data);
                append(&llist, data);
                printf("appending %i to llist...\n", data);
            } else if (option == 3) {
                reverse(&llist);
                printf("reversing llist...\n");
            }
        }
        printf("\n llist = ");
        print(&llist);
        printf("\n");
        printf("enter action: ");
        scanf("%i", &option);
    }
    printf("test complete!\n");
    return 0;
}