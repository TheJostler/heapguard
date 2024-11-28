#include <stdio.h>
#include "heap.h"

int main() {
  List *list1 = list_create();
  List *list2 = list_create();

  list_add(list1, "hello");
  list_add(list2, "Second");
  list_add(list1, "world");


  // Method 1: Direct array access
  printf("\nList1:\n");
  for (size_t i = 0; i < list1->count; i++) {
    printf("%s\n", list1->strings[i]);
  }

  printf("\nList2:\n");
  for (size_t i = 0; i < list2->count; i++) {
    printf("%s\n", list2->strings[i]);
  }
  // Memory automatically freed on exit
  return 0;
}