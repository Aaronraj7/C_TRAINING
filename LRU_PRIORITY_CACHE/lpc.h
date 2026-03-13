#ifndef LRU_PRIORITY_CACHE_H
#define LRU_PRIORITY_CACHE_H
#define MAX_PRIORITY 10

typedef struct Node{
    int value;
    int key;
    int priority;
    struct Node *next, *prev;
    struct Node *next_hash;
}Node;

typedef struct LRU_PRIORITY_CACHE{
    int capacity;
    int count;
    Node *head[MAX_PRIORITY], *tail[MAX_PRIORITY];
    Node **hash_table;
    int hash_size;
}LRU_PRIORITY_CACHE;

Node* createNode(int key, int value, int priority);
void detach_Node(LRU_PRIORITY_CACHE *obj, Node *node);
void move_to_head(LRU_PRIORITY_CACHE *obj, Node *node);
LRU_PRIORITY_CACHE* create_cache(int capacity);
void LRU_put(LRU_PRIORITY_CACHE* obj, int key, int value, int priority);
int LRU_get(LRU_PRIORITY_CACHE* obj, int key);
int free_lru(LRU_PRIORITY_CACHE* obj);

#endif