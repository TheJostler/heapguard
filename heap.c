#include "heap.h"

char **alloc_str = NULL;
int n_alloc_str = 0;
int c_alloc_str = 16; //how many slots to start with(this will be doubled when needed)

char ***alloc_str_lst = NULL;
int n_alloc_str_lst = 0;
int c_alloc_str_lst = 1;

char *allocstr(const char *str) {
 if (n_alloc_str == 0) {
  alloc_str = malloc(c_alloc_str*sizeof(char*));
 } else if (n_alloc_str >= c_alloc_str) {
  c_alloc_str *= 2;
  alloc_str = realloc(alloc_str, c_alloc_str*sizeof(char*));
 }

 alloc_str[n_alloc_str] = malloc((strlen(str) + 1) * sizeof(char));
 // NEW FEATURE Pass an unlimited number of parameters which all get concatonated into the appropriately sized buffer
 strcpy(alloc_str[n_alloc_str], str);
 n_alloc_str++;

 return alloc_str[n_alloc_str-1];
}

void allocstrlist(char **list, char *str) {
 //Ok now I need to copy the functionality from above but instead of simply allocating a string and recording the address to a builting cleanup function, I need to save the str pointer to an arbritary array and make sure that every item in each array is freed during freeall()
}

void freeall() {
 for(int i=0; i<n_alloc_str; i++) {
  printf("freeing:%s<-%p\n", alloc_str[i], &alloc_str[i]);
  // Shred the info that is in the heap.
  for(int c=0; c<=strlen(alloc_str[i]);c++) {
   alloc_str[i][c] = '\0';
  }
  // Free the memory from the heap 
  free(alloc_str[i]);
 }
 // Free the array itself 
 free(alloc_str);
 n_alloc_str = -1;

 exit(0);
}

int initheapguard() {
 signal(SIGINT, freeall);
 signal(SIGTERM, freeall);
 return atexit(freeall);
}
