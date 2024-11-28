// list.c
#include "heap.h"

static List **all_lists = NULL;
static size_t list_count = 0;
static size_t list_capacity = 16;

static void cleanup_handler(void) {
    for (size_t i = 0; i < list_count; i++) {
        if (all_lists[i]) {
            for (size_t j = 0; j < all_lists[i]->count; j++) {
                free(all_lists[i]->strings[j]);
            }
            free(all_lists[i]->strings);
            free(all_lists[i]);
        }
    }
    free(all_lists);
}

void init_cleanup_handler(void) {
    all_lists = malloc(list_capacity * sizeof(List*));
    atexit(cleanup_handler);
    signal(SIGINT, (void (*)(int))cleanup_handler);
}

List *list_create(void) {
    if (!all_lists) init_cleanup_handler();
    
    List *list = malloc(sizeof(List));
    list->strings = malloc(16 * sizeof(char*));
    list->count = 0;
    list->capacity = 16;
    
    if (list_count >= list_capacity) {
        list_capacity *= 2;
        all_lists = realloc(all_lists, list_capacity * sizeof(List*));
    }
    all_lists[list_count++] = list;
    
    return list;
}

void list_add(List *list, const char *str) {
    if (list->count >= list->capacity) {
        list->capacity *= 2;
        list->strings = realloc(list->strings, list->capacity * sizeof(char*));
    }
    
    list->strings[list->count] = strdup(str);
    list->count++;
}