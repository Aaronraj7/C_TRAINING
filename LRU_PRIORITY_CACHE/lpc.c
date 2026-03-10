#include"lpc.h"

Node* createNode(int key, int value, int priority){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->value=value;
    newNode->priority=priority;
    newNode->next=newNode->prev=NULL;
    return newNode;
}

void detach_Node(LRU_PRIORITY_CACHE *obj, Node *node){
    int p=node->priority;
    
    if(node->prev)  node->prev->next=node->next;
    else    obj->head[p]=node->next;

    if(node->next)  node->next->prev=node->prev;
    else    obj->tail[p]=node->prev;

    node->prev=node->next=NULL;
}

void move_to_head(LRU_PRIORITY_CACHE *obj, Node *node){
    int p=node->priority;

    node->next=obj->head[p];
    node->prev=NULL;
    if(obj->head[p])    obj->head[p]->prev=node;
    obj->head[p]=node;
    if(!obj->tail[p])   obj->tail[p]=node;
}

LRU_PRIORITY_CACHE* create_cache(int capacity){
    LRU_PRIORITY_CACHE *obj=(LRU_PRIORITY_CACHE*)malloc(sizeof(LRU_PRIORITY_CACHE));
    if(!obj) return NULL;

    obj->capacity=capacity;
    obj->count=0;
    for(int i=0;i<MAX_PRIORITY;i++){
        obj->head[i]==NULL;
        obj->tail[i]==NULL;
    }

    obj->hash_size=capacity*2;
    obj->hash_table=(Node**)calloc(obj->hash_size,sizeof(Node*));

    if(!obj->hash_table)    return NULL;   
}