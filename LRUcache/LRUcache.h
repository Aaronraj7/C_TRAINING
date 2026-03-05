#ifndef LRU_CACHE_H
#define LRU_CACHE_H
#include<stdlib.h>

typedef struct Node{
    int key;
    int value;
    struct Node *next, *prev;
}Node;

typedef struct{
    int capacity;
    int count;
    Node *head, *tail;
    Node **hashtable;
    int hash_size;
}LRUcache;

Node* create_Node(int key, int value);
void detach_Node(LRUcache *obj, Node *node);
void move_to_head(LRUcache *obj, Node *node);
LRUcache *create_cache(int capacity);
int get(LRUcache *obj, int key);
void put(LRUcache *obj, int key, int value);

#endif