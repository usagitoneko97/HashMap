#ifndef _HASHMAP_H
#define _HASHMAP_H

#include "linkedlist.h"
#include "Compare.h"
#include "Data.h"
typedef struct HashTable HashTable;

struct HashTable{
    LinkedList *list;
    int size;
    int sizeFactor;
};



void hashMapInit(HashTable *table, int size, int sizeFactor);
void _hashMapAdd(HashTable *table, void *data, int index);
void hashMapAddInteger(HashTable *table, Data *data);
uint32_t hashUsingModulus(int data, int size);

void *_hashMapSearch(HashTable *table, uint32_t key, int index, Compare compareFunc);
void *hashMapRemove(HashTable *table, uint32_t key, int index, Compare compareFunc);

#endif // _HASHMAP_H
