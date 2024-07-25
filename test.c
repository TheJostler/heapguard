#include <stdio.h>
#include "heap.h"

void printlist(char **list) {
    int i=0;
    while(list[i][0] != '\0') {
        printf("i: %i\n", i);
        printf("%s\n", list[i]);
        i++;
    }
}

int main() {
    initheapguard();

    List test;
    List *testptr = &test;
    char *word = allocstr("Hello World, \n");
    newList(testptr);
    setListItem(testptr, "This");
    setListItem(testptr, "is");
    setListItem(testptr, "a");
    char *rogue = allocstr("Rogue String\n");
    setListItem(testptr, "test");
    finishList();
    
    printf("%s%i\n", word, n_alloc_str);
    printf("%i, %i\n\n", test.start, test.end);
    for(int i=test.start; i<=test.end; i++) {
        printf("%s ", alloc_str[i]);
    }
    printf("\n");

    char *list[] = {
        "Hello",
        "This",
        "is",
        "a",
        "list",
        "of",
        "strings",
        "\0"
    };

    printlist(list);
}