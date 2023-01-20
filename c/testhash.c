#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "hashtable.h"

int main() {
    
    clearTable();
    node drew      = {.string="Drew",      .num=29};
    node lauren    = {.string="Lauren",    .num=29};
    node georgia   = {.string="Georgia",   .num=4};
    node clark     = {.string="Clark",     .num=2};
    node charlotte = {.string="Charlotte", .num=0};
    
    insertPerson(&drew);
    insertPerson(&charlotte);
    insertPerson(&clark);
    insertPerson(&lauren);
    insertPerson(&georgia);
    printTable();

    node *result = search("Bill"); 
    //printf("%s: %i", result->string, result->num);

}