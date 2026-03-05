//LRU cache simplified implementation using a fixed hashtable
#include "LRUcache.h"

Node* create_Node(int key, int value){
    Node* node=(Node*)malloc(sizeof(Node));
    node->key=key;
    node->value=value;
    node->next=node->prev=NULL;
    return node;
}

void detach_Node(LRUcache *obj, Node* node){
    if(node->prev)  node->prev->next=node->next;
    else    obj->head=node->next;

    if(node->next)   node->next->prev=node->prev;
    else    obj->tail=node->prev;

}

void move_to_head(LRUcache *obj, Node* node){
    node->next=obj->head;
    node->prev=NULL;
    if(obj->head)   obj->head->prev=node;
    obj->head=node;
    if(!obj->tail)   obj->tail=node;
}

LRUcache* create_cache(int capacity){
    LRUcache *obj=(LRUcache*)malloc(sizeof(LRUcache));
    obj->capacity=capacity;
    obj->count=0;
    obj->hash_size=1000;
    obj->hashtable=(Node**)calloc(obj->hash_size,sizeof(Node*));
    obj->head=obj->tail=NULL;
    return obj;
}

int get(LRUcache *obj, int key){
    int hash=key%obj->hash_size;
    Node* node=obj->hashtable[hash];

    if(node && node->key==key){
        detach_Node(obj, node);
        move_to_head(obj, node);
        return node->value;
    }
    return -1;
}

void put(LRUcache *obj, int key, int value){
    int hash=key%obj->hash_size;
    Node* node=obj->hashtable[hash];
    
    if(node && node->key==key){
        node->value=value;
        detach_Node(obj,node);
        move_to_head(obj,node);
    }
    else{
        if(obj->count==obj->capacity){
            Node* lru=obj->tail;
            obj->hashtable[lru->key%obj->hash_size]=NULL;
            detach_Node(obj,lru);
            free(lru);
            obj->count--;
        }

        Node *newnode=create_Node(key, value);
        obj->hashtable[hash]=newnode;
        move_to_head(obj,newnode);
        obj->count++;
    }

}