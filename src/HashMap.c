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
    if (data == NULL)
    {
        Throw(createException("Data to be add should not be NULL", HASH_DATA_NULL));
    }
    if(index > (table->size * table->sizeFactor)){
        Throw(createException("hash index out of bound", HASH_INDEX_EXCEED));
    }
    if(table->list[index].head == NULL){
        ListInit(&(table->list[index]));
    }
	Item *newItem = (Item*)malloc(sizeof(Item));
    createItem(newItem, data, NULL);

    listAddUniqueKey(&(table->list[index]), newItem, compareFunc);
    // ListAddLinkedList(&(table->list[index]), newItem);
}

uint32_t hashUsingModulus(const char *data, int size){
    return *data % size;
}

void hashMapAdd(HashTable *table, void *value, void *key, Compare compareFunc){
    Data *data = dataCreate(key, value);
    //compute hash value
    if(data == NULL){
        Throw(createException("Data to be add should not be NULL", HASH_DATA_NULL));
    }
    uint32_t hashValue = hashUsingModulus((char *)data->key, table->size * table->sizeFactor);
    printf("hash value = %d", hashValue);
    Try{
        _hashMapAdd(table, (void *)data, hashValue, compareFunc);
    }Catch(ex){
        Throw(ex);
    }
    //_hashmapAdd(...)
}

/*Item *_hashMapSearch(HashTable *table, void *key, int index, Compare compareFunc)
{
    return listSearch((table->list[index]), key, compareFunc);
}

int _hashMapRemove(HashTable *table, void *key, int index, Compare compareFunc){
    Try{
        listRemoveByKey(&table->list[index], key, compareFunc);
    }Catch(ex){
        Throw(ex);
    }
    //free memory
}
int hashMapRemove(HashTable *table, void *key, Compare compareFunc){
    uint32_t hashValue = hashUsingModulus((char*)key, table->size * table->sizeFactor);
    Try{
        _hashMapRemove(table, key, hashValue, compareFunc);
    }Catch(ex){
        Throw(ex);
    }
}

Item *hashMapSearch(HashTable *table, void * key, Compare compareFunc){
    uint32_t hashValue = hashUsingModulus(key, table->size * table->sizeFactor);
    return _hashMapSearch(table, key, hashValue, compareFunc);
}*/

void listAddUniqueKey(LinkedList *list, Item *data, Compare compareFunc)
{
    LinkedList listTemp = *list;
    while(listTemp.head != NULL){
        if(compareFunc((void*)&(((Data *)(listTemp.head->data))->key), (void*)&(((Data*)(data->data))->key)) == 1)
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

void hashMapAddStr(HashTable *table, char *strValue, void *key)
{
    hashMapAdd(table, (void *)strValue, key, compareKeyInt);
}

void hashMapAddInt(HashTable *table, int intValue, void *key)
{
    hashMapAdd(table, (void *)&intValue, key, compareKeyInt);
}

