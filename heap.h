#ifndef HEAP_GUARD_H
#define HEAP_GUARD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

extern char **alloc_str;
extern int n_alloc_str;

struct list {
 unsigned short start;
 unsigned short end;
};

typedef struct list List;

void newList(List *list);
void finishList();
void setListItem(List *list, char *word);

char *allocstr(const char *str);
void freeall();
int initheapguard();

#endif
