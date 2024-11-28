// list.h
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <string.h>
#include <signal.h>

typedef struct List {
    char **strings;
    size_t count;
    size_t capacity;
} List;

List *list_create(void);
void list_add(List *list, const char *str);
void list_cleanup(void);
void init_cleanup_handler(void);

#endif