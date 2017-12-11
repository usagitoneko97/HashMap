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

#define _hashMapAddInt(table, data, index)  _hashMapAdd(table, data, index, compareKeyInt)

#define hashMapSearchKeyInt(table, key)     hashMapSearch(table, key, compareKeyInt)
#define hashMapRemoveKeyInt(table, key)     hashMapRemove(table, key, compareKeyInt)

#define hashMapPutKeyInt(table, value, key)                                      \
            int valueVar = value; int keyVar = key;                              \
            hashMapAdd(table, (void *)&valueVar, (void *)&keyVar, compareKeyInt)    
#define hashMapPutKeyString(table, value, key) hashMapPut(table, (void *)value, (void *)key, compareKeyString)

void hashMapInit(HashTable *table, int size, int sizeFactor);
void _hashMapAdd(HashTable *table, void *data, int index, Compare compareFunc);
void hashMapAdd(HashTable *table, void *value, void *key, Compare compareFunc);

uint32_t hashUsingModulus(const char *data, int size);

Item *_hashMapSearch(HashTable *table, void *key, int index, Compare compareFunc);
int _hashMapRemove(HashTable *table, void *key, int index, Compare compareFunc);
int hashMapRemove(HashTable *table, void *key, Compare compareFunc);
void listAddUniqueKey(LinkedList *list, Item *data, Compare compareFunc);
Item *hashMapSearch(HashTable *table, void *key, Compare compareFunc);

void hashMapAddStr(HashTable *table, char *strValue, void *key);
void hashMapAddInt(HashTable *table, int intValue, void *key);

void hashMapPut(HashTable *table, void *Value, void *key, Compare compare);

#endif // _HASHMAP_H
