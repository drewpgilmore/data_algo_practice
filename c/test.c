#include <stdio.h>

int main(void) { 
    for (int x = 0; x < 10; x++) {
        if (x == 5) {
            printf("Found a five!");
        }
        else {
            printf("Number is %i\n", x);
        }
    }
}