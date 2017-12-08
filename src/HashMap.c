#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "HashMap.h"
#include "Exception.h"
#include "CException.h"

CEXCEPTION_T ex;
void hashMapInit(HashTable *table, int size, int sizeFactor){

    table->list = (LinkedList *)calloc(size * sizeFactor, sizeof(LinkedList));
    table->size = size;
    table->sizeFactor = sizeFactor;
}

void _hashMapAdd(HashTable *table, void *data, int index, Compare compareFunc){
    if(index > (table->size * table->sizeFactor)){
        Throw(createException("hash index out of bound", HASH_INDEX_EXCEED));
    }
    if(table->list[index].head == NULL){
        ListInit(&(table->list[index]));
    }
	Item *newItem = (Item*)malloc(sizeof(Item));
    createItem(newItem, data, NULL);

    listAddUniqueKey(&(table->list[index]), newItem, index, compareFunc);
    // ListAddLinkedList(&(table->list[index]), newItem);
}

uint32_t hashUsingModulus(int data, int size){
    return data % size;
}

void hashMapAdd(HashTable *table, Data *data){
    //compute hash value
    uint32_t hashValue = hashUsingModulus(data->key, table->size * table->sizeFactor);
    printf("hash value = %d", hashValue);
    Try{
        _hashMapAdd(table, (void *)data, hashValue, compareKeyInt);
    }Catch(ex){
        Throw(ex);
    }
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

void listAddUniqueKey(LinkedList *list, Item *data, uint32_t key, Compare compareFunc)
{   
    LinkedList listTemp = *list;
    while(listTemp.head != NULL){
        if(compareFunc((void*)&(((Data *)(listTemp.head->data))->key), (void*)&key) == 1)
        {
            //replacing data
            ((Data *)(listTemp.head->data))->value = ((Data*)(data->data))->value;
            return;
        }
        listTemp.head = listTemp.head->next;
    }
    //no duplicate key,
    ListAddLinkedList(list, (Item*)data);
}