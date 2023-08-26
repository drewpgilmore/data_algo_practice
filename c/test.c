#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedlist.h"

#define LIST_LENGTH 20

// bool test_tail(node **llist, node *target) {
//     if (tail(llist) == target) {
//         printf("Pass\n");
//         return true;
//     } else {
//         printf("FAIL\n");
//         return false;
//     }
// }


int main(void) {
    // Create list of random numbers
    node *llist = NULL;
    for (int i = 0; i < LIST_LENGTH; i++) {
        node *n = randomNumNode();
        prepend(&llist, n);
    }
    printList(&llist);

    // Test functions
    bool passAll = true;
    int len, index;
    node *dummy = randomNumNode();
    node *emptyList = NULL;

    // Length
    printf("length()\n");

    // Test length of empty list
    printf("Test 1 - ");
    len = length(&emptyList);
    if (len == 0) {
        printf("Pass\n");
    } else {
        printf("FAIL - ");
        printf("Expected: %i, Actual: %i\n", 0, len);
        passAll = false;
    }

    // Test length of non-empty list
    printf("Test 2 - ");
    len = length(&llist);
    if (len == LIST_LENGTH) {
        printf("Pass\n");
    } else {
        printf("FAIL - ");
        printf("Expected: %i, Actual: %i\n", LIST_LENGTH, len);
        passAll = false;
    }
    
    // Traverse to
    printf("traverseTo()\n");
    
    // Test index 0 = head
    printf("Test 1 - ");
    if (traverseTo(&llist, 0) == llist) {
        printf("Pass\n");
    } else {
        printf("FAIL\n");
        passAll = false;
    }

    // Test index LIST_LENGTH - 1 = tail
    printf("Test 2 - ");
    if (traverseTo(&llist, LIST_LENGTH - 1) == tail(&llist)) {
        printf("Pass\n");
    } else {
        printf("FAIL\n");
        passAll = false;
    }

    // Test index out of range
    printf("Test 3 - ");
    if (traverseTo(&llist, LIST_LENGTH) == 0) {
        printf("Pass\n");
    } else {
        printf("FAIL\n");
        passAll = false;
    }

    // Tail
    printf("tail()\n");
    // Test tail->next is NULL
    printf("Test 1 - ");
    if (tail(&llist)->next == NULL) {
        printf("Pass\n");
    } else {
        printf("FAIL\n");
        passAll = false;
    }

    // Test tail of empty list

    // Test tail is equal to traverseTo(LIST_LENGTH - 1)

    // Prepend
    printf("prepend()\n");
    // Test prepend to empty list
    printf("Test 1 - ");
    prepend(&emptyList, dummy);
    if (emptyList == dummy) {
        printf("Pass\n");
    } else {
        printf("FAIL\n");
        passAll = false;
    }

    // Test prepend to non-empty list
    printf("Test 2 - "); 
    dummy = randomNumNode();
    prepend(&llist, dummy);
    // Test n is now head
    if (llist == dummy) {
        printf("Pass\n");
    } else {
        printf("FAIL\n");
        passAll = false;
    }
    
    // Test length has increased by 1
    printf("Test 3 - ");
    if (length(&llist) == LIST_LENGTH + 1) {
        printf("Pass\n");
    } else {
        printf("FAIL\n");
        passAll = false;
    }

    // Append

    // Insert
    printf("insert()\n");
    // Test insert out of range
    printf("Test 1 - ");
    len = length(&llist);
    dummy = randomNumNode();
    insert(&llist, dummy, len + 1); // should print error message and return
    if (length(&llist) == len) {
        printf("Pass\n");
    } else {
        printf("FAIL\n"); 
    }

    // Test insert to empty list
    printf("Test 2 - ");
    emptyList = NULL;
    dummy = randomNumNode();
    insert(&emptyList, dummy, 0);
    if (emptyList == dummy) {
        printf("Pass\n");
    } else {
        printf("FAIL: ");
        printList(&emptyList);
        passAll = false;
    }
    
    // Test insert to beginning of list
    printf("Test 3 - ");
    dummy = randomNumNode();
    insert(&llist, dummy, 0);
    if (llist == dummy) {
        printf("Pass\n");
    } else {
        printf("FAIL\n"); 
        passAll = false;
    }
    
    // Test insert to end of list
    printf("Test 4 - ");
    len = length(&llist);
    dummy = randomNumNode();
    insert(&llist, dummy, len - 1);
    if (tail(&llist) == dummy) {
        printf("Pass\n");
    } else {
        printf("FAIL\n");
        passAll = false;
    }

    // Test insert to non-empty list
    printf("Test 5 - ");
    index = 5;
    dummy = randomNumNode();
    insert(&llist, dummy, index);
    if (traverseTo(&llist, index) == dummy) {
        printf("Pass\n");
    } else {
        printf("FAIL\n");
        passAll = false;
    }

    // Delete

    // Reverse

    printf("\n"); 
    if (passAll) {
        printf("All tests passed!\n");
        return 0;
    } else {
        printf("Some tests failed!\n");
    }
}