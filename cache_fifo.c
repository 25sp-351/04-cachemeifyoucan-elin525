#include <stdio.h>
#include <stdlib.h>
#include "cache.h"

#define CACHE_SIZE 90

typedef struct CacheEntry {
    int rod_length;
    int value;
    struct CacheEntry *next;
} CacheEntry;

CacheEntry *head = NULL, *tail = NULL;
int cache_count = 0;

void init_cache() {
    head = tail = NULL;
    cache_count = 0;
}

// insert a new entry into the cache
void insert_cache(int rod_length, int value) {
    CacheEntry *new_entry = (CacheEntry *)malloc(sizeof(CacheEntry));
    if (!new_entry) return;

    // initialize the values of the new entry
    new_entry->rod_length = rod_length;
    new_entry->value = value;
    new_entry->next = NULL;

    if (cache_count == 0) {
        head = tail = new_entry;
    } else {
        tail->next = new_entry;
        tail = new_entry;
    }

    cache_count++;

    // if the cache is full, remove the oldest entry
    if (cache_count > CACHE_SIZE) {
        CacheEntry *temp = head;
        head = head->next;
        free(temp);
        cache_count--;
    }
}

// check if the value is in the cache
int check_cache(int rod_length) {
    CacheEntry *curr = head;
    while (curr) {
        if (curr->rod_length == rod_length) {
            return curr->value;
        }
        curr = curr->next;
    }
    return -1;
}

// free the cache memory
void free_cache() {
    CacheEntry *curr = head;
    while (curr) {
        CacheEntry *temp = curr;
        curr = curr->next;
        free(temp);
    }
    head = tail = NULL;
    cache_count = 0;
}
