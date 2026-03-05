#include <stdio.h>
#include "LRUcache.h"

int main() {
    
    LRUcache* cache = create_cache(2);

    printf("Putting (1, 10)...\n");
    put(cache, 1, 10);
    
    printf("Putting (2, 20)...\n");
    put(cache, 2, 20);

    
    printf("Get key 1: %d\n", get(cache, 1)); 

    
    printf("Putting (3, 30) - should evict key 2...\n");
    put(cache, 3, 30);

    
    printf("Get key 2 (should be -1): %d\n", get(cache, 2));
    printf("Get key 3 (should be 30): %d\n", get(cache, 3));
    printf("Get key 1 (should be 10): %d\n", get(cache, 1));

    printf("Putting (2, 20) -should evict key 3...\n");
    put(cache, 2, 20);
    printf("Get key 1 : %d\n", get(cache, 1));
    printf("Get key 2 : %d\n", get(cache, 2));

    return 0;
}