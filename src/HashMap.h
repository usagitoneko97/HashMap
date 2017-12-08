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

#define _hashMapAddInt(table, data, index) _hashMapAdd(table, data, index, compareKeyInt);
#define hashMapSearchKeyInt(table, key) hashMapSearch(table, key, compareKeyInt)

void hashMapInit(HashTable *table, int size, int sizeFactor);
void _hashMapAdd(HashTable *table, void *data, int index, Compare compareFunc);
void hashMapAdd(HashTable *table, Data *data);
uint32_t hashUsingModulus(int data, int size);

void *_hashMapSearch(HashTable *table, uint32_t key, int index, Compare compareFunc);
void *hashMapRemove(HashTable *table, uint32_t key, int index, Compare compareFunc);
void listAddUniqueKey(LinkedList *list, Item *data, uint32_t key, Compare compareFunc);
void *hashMapSearch(HashTable *table, uint32_t key, Compare compareFunc);

#endif // _HASHMAP_H
