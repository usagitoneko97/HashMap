#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "HashMap.h"


void hashMapInit(HashTable *table, int size, int sizeFactor){

    table->list = (LinkedList *)calloc(size * sizeFactor, sizeof(LinkedList));
    table->size = size;
    table->sizeFactor = sizeFactor;
}

void _hashMapAdd(HashTable *table, void *data, int index){
    if(table->list[index].head == NULL){
        ListInit(&(table->list[index]));
    }
	Item *newItem = (Item*)malloc(sizeof(Item));
    createItem(newItem, data, NULL);
    ListAddLinkedList(&(table->list[index]), newItem);
}

uint32_t hashUsingModulus(int data, int size){
    return data % size;
}

void hashMapAddInteger(HashTable *table, Data *data){
    //compute hash value
    uint32_t hashValue = hashUsingModulus(data->key, table->size * table->sizeFactor);
    printf("hash value = %d", hashValue);
    _hashMapAdd(table, (void*)data, hashValue);
    //_hashmapAdd(...)
}

void *_hashMapSearch(HashTable *table, uint32_t key, int index, Compare compareFunc)
{
}

void _hashMapRemove(HashTable *table, void *data, int index, Compare compareFunc){
    //free memory
}

void hashMapSearch(HashTable *table, int data){
    //compute hash value

    // _hashMapSearch(table, data, hashValue, integerCompare);
}

