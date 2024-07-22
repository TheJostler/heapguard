#include <stdio.h>
#include "heap.h"

int main() {
    initheapguard();

    List test;
    List *testptr = &test;
    char *word = allocstr("Hello World, \n");
    initList(testptr);
    setListItem(testptr, "This");
    setListItem(testptr, "is");
    setListItem(testptr, "a");
    setListItem(testptr, "test");
    
    printf("%s%i\n", word, n_alloc_str);
    printf("%i, %i\n\n", test.start, test.end);
    for(int i=test.start; i<=test.end; i++) {
        printf("%s ", alloc_str[i]);
    }
    printf("\n");
}