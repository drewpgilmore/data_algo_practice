#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hashtable.h"

/* HASH TABLE
    - Node struct = {.string = char *, .num = int .next = node *}
      node displays as "(node->string, node->num)"
    - Nodes are stored in the table by hashing first char in .string
    - Nodes with same hash form linked list sorted alphabetically by .string

    Samle output of printTable():
    0: ---
    1: (Samwise, 40) -> (Shadowfax, 7) -> End  
    2: (Bilbo, 111) -> (Boromir, 80) -> End
    ...
    n: (Gandalf, 100000) -> (Gimli, 90) -> End

*/

int main() {
    // Start with empty table
    clearTable();

    // Insert random nodes
    for (int i = 0; i < 50; i++) {
        node *n = malloc(sizeof(node)); 
        n = randomNode(); 
        insertPerson(n);
    }
    
    // Display entire table
    printList(&hashTable[8], "all");
}