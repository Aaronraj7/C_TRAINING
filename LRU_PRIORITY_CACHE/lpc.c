#include"lpc.h"
#include<stdlib.h>

Node* createNode(int key, int value, int priority){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->key=key;
    newNode->value=value;
    newNode->priority=priority;
    newNode->next=newNode->prev=NULL;
    newNode->next_hash=NULL;
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
        obj->head[i]=NULL;
        obj->tail[i]=NULL;
    }

    obj->hash_size=capacity*2;
    obj->hash_table=(Node**)calloc(obj->hash_size,sizeof(Node*));

    if(!obj->hash_table){
        free(obj);
        return NULL;
    } 
    return obj;  
}

void LRU_put(LRU_PRIORITY_CACHE *obj, int key, int value, int priority){
    int hash= key % obj->hash_size;
    Node *node=obj->hash_table[hash];

    while(node){
        if(node && node->key==key){
            detach_Node(obj,node);
            node->value=value;
            node->priority=priority;
            move_to_head(obj,node);
            return;
        }
        node=node->next_hash;
    }
    if(obj->count==obj->capacity){
        for(int i=0;i<MAX_PRIORITY;i++){
            if(obj->tail[i]){
                
                Node* lru=obj->tail[i];
                int v_hash=lru->key%obj->hash_size;
                Node **curr = &(obj->hash_table[v_hash]);
                
                while(*curr && *curr!=lru)  curr=&((*curr)->next_hash);
                if(*curr)   *curr=lru->next_hash;
                
                detach_Node(obj,lru);
                free(lru);
                obj->count--;
                break;
            }
        }
    }
        Node *newNode= createNode(key,value,priority);
        newNode->next_hash=obj->hash_table[hash];
        obj->hash_table[hash]=newNode;
        move_to_head(obj,newNode);
        obj->count++;
}

int LRU_get(LRU_PRIORITY_CACHE* obj, int key){
    int hash=key%obj->hash_size;
    Node* node=obj->hash_table[hash];

    while(node){
        if(node->key==key){
            detach_Node(obj,node);
            move_to_head(obj,node);
            return node->value;
        }
        node=node->next_hash;
    }
    return -1;

}

int free_lru(LRU_PRIORITY_CACHE* obj){
    if(!obj) return -1;
    for(int i=0;i<MAX_PRIORITY;i++){
        Node* current = obj->head[i];
        while(current){
            Node* next=current->next;
            free(current);
            current=next;
        }
    }
    if(obj->hash_table) free(obj->hash_table);
    free(obj);
    return 0;
}