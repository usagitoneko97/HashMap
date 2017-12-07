#ifndef _HASHMAP_H
#define _HASHMAP_H

#include "linkedlist.h"
#include "Compare.h"

#define SIZE_FACTOR  3
typedef struct HashTable HashTable;

struct HashTable{
    LinkedList **list;
    int size;
};



void hashMapInit(HashTable *table, int size);
void _hashMapAdd(HashTable *table, void *data, int index);
void hashMapAddInteger(HashTable *table, int data, int size);
uint32_t hashUsingModulus(int data, int size);

#endif // _HASHMAP_H
