#include <stdio.h>
#include <stdlib.h>
#include "cache.h"

#define CACHE_SIZE 90

typedef struct CacheEntry {
    int rod_length;
    int value;
    struct CacheEntry *next;
    struct CacheEntry *prev;
} CacheEntry;

CacheEntry *head = NULL, *tail = NULL;
int cache_count = 0;

// initialize the cache
void init_cache() {
    head = tail = NULL;
    cache_count = 0;
}

// insert a new entry into the cache with the given rod length and value
void insert_cache(int rod_length, int value) {
    CacheEntry *new_entry = (CacheEntry *)malloc(sizeof(CacheEntry));
    // if malloc fails, return
    if (!new_entry) return;

    new_entry->rod_length = rod_length;
    new_entry->value = value;
    new_entry->next = head;
    new_entry->prev = NULL;

    // if the cache is not empty, update the previous pointer of the current head
    if (head) head->prev = new_entry;
    head = new_entry;

    // if the cache is empty, update the tail
    if (!tail) tail = new_entry;

    cache_count++;

    // if the cache is full, remove the oldest entry
    if (cache_count > CACHE_SIZE) {
        CacheEntry *temp = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        free(temp);
        cache_count--;
    }
}

// check if the value is in the cache
int check_cache(int rod_length) {
    CacheEntry *curr = head;
    while (curr) {
        if (curr->rod_length == rod_length) {
            // if the entry is not the head, move it to the head
            if (curr != head) {
                if (curr->prev) curr->prev->next = curr->next;
                if (curr->next) curr->next->prev = curr->prev;
                if (curr == tail) tail = curr->prev;

                curr->next = head;
                curr->prev = NULL;
                head->prev = curr;
                head = curr;
            }
            // return the value
            return curr->value;
        }
        // move to the next entry
        curr = curr->next;
    }
    // return -1 if the value is not in the cache
    return -1;
}

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
