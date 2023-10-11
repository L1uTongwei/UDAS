#pragma once
#include <time.h>
#include <stdlib.h>
struct account{
    char username[48];
    unsigned long long password[8];
    char saltA[8], saltB[8];
    char metadata[128];
}; //size = 256 Bytes
typedef unsigned long session;
struct trie{
    short** next;
    void** data;
    int count, size;
    short charset;
};
#define ACCOUNT_SIZE 100000
#define FULL_CHARSET 256
#define SESSION_SIZE 1000000
#define ALPHA_CHARSET 26
short trie_init(struct trie* t, int size, short charset);
short trie_insert(struct trie* t, const char* s, void* data);
void* trie_find(struct trie* t, const char* s);
void trie_free(struct trie* t);
