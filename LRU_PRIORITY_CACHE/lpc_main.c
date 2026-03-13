#include <stdio.h>
#include "lpc.h" 

int main() {
    // Create a cache with a max capacity of 3
    LRU_PRIORITY_CACHE* cache = create_cache(3);
    
    if (!cache) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\n--- Test 1: Basic Insertion ---\n");
    LRU_put(cache, 10, 100, 2); 
    LRU_put(cache, 20, 200, 2); 
    LRU_put(cache, 30, 300, 1); 
    
    printf("Get 10: %d\n", LRU_get(cache, 10)); 
    printf("Get 20: %d\n", LRU_get(cache, 20)); 
    printf("Get 30: %d\n", LRU_get(cache, 30)); 

    printf("\n--- Test 2: Priority Eviction ---\n");
    // Cache is full. Inserting a new item should evict the lowest priority item (Key 30).
    LRU_put(cache, 40, 400, 2); 
    printf("Inserted Key 40. Key 30 should have been evicted.\n");
    printf("Get 30 (Expect -1): %d\n", LRU_get(cache, 30)); 
    printf("Get 40 (Expect 400): %d\n", LRU_get(cache, 40)); 

    printf("\n--- Test 3: LRU Eviction (Same Priority) ---\n");
    // Cache currently has: 10 (P2), 20 (P2), 40 (P2).
    // Key 10 is currently the oldest (Least Recently Used) in Priority 2.
    LRU_put(cache, 50, 500, 2);
    printf("Inserted Key 50. Key 10 should be evicted.\n");
    printf("Get 10 (Expect -1): %d\n", LRU_get(cache, 10));
    printf("Get 20 (Expect 200): %d\n", LRU_get(cache, 20));

    printf("\n--- Test 4: Update Existing Key ---\n");
    // Update key 20 to a new value and a higher priority (Priority 5)
    LRU_put(cache, 20, 999, 5);
    printf("Updated Key 20 to Value 999, Priority 5.\n");
    printf("Get 20 (Expect 999): %d\n", LRU_get(cache, 20));

    if(free_lru(cache)==0)  printf("Cache successfully removed\n");
    else    printf("Unsuccessfull \n");

    return 0;
}