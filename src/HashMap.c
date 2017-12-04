#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "HashMap.h"


void hashMapInit(HashTable *table, int size){

    table->list = (LinkedList**)calloc(size * SIZE_FACTOR, sizeof(LinkedList **));
    table->size = size;
}

void _hashMapAdd(HashTable *table, void *data, int index){
    table->list[index] = (LinkedList*)malloc(1);
    ListInit(table->list[index]);
    Item newItem = createItem(data, NULL);
    ListAddLinkedList(table->list[index], &newItem);
}

// uint32_t hashUsingModulus(int data, int size){
//     return 
// }

void hashMapAddInteger(HashTable *table, int data){
    //compute hash value
    // uint32_t hashValue = hashUsingModulus(data);
    // _hashMapAdd(table, (void*)&data, hashValue);
    //_hashmapAdd(...)
}

void _hashMapSearch(HashTable *table, void *data, int index, Compare compareFunc){

}

void _hashMapRemove(HashTable *table, void *data, int index, Compare compareFunc){
    //free memory
}

void hashMapSearch(HashTable *table, int data){
    //compute hash value

    // _hashMapSearch(table, data, hashValue, integerCompare);
}
