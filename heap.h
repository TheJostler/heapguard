#ifndef HEAP_GUARD_H
#define HEAP_GUARD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

char *allocstr(const char *str);
void freeall();
int initheapguard();

#endif
