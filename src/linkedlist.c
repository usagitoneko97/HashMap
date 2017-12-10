#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include <stdint.h>
#include <stdlib.h>
#include "Exception.h"
#include "CException.h"

void ListInit(LinkedList *list){
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;

}

void ListAddEmptyLinkedList (LinkedList *list, Item *item){
  list->head = item;
  list->tail = item;
  list->len = 1;
  item->next = NULL;

}

void ListAddLinkedList(LinkedList *list, Item *item){
  if(list->head==NULL){
    //empty list
    list->head = item;
    list->tail = item;
    list->len = 1;
    item->next = NULL;
  }
  else{
    list->tail->next = item;
    item->next = NULL;
    list->tail = item;
    list->len++;

  }
}

Item* ListRemoveFirst(LinkedList *list){
  if(list->head == NULL){
    return NULL;
  }
  else{
    list->head = list->head->next;
  }
}
Item* ListRemoveLinkedListByName(char* name, LinkedList *list){
  //preserve the head
  Item* tempHead = list->head;
  Item* deleteHead = NULL;
  Item *prevL = NULL;
  if(list->head == NULL){
    return NULL;
  }
  else{
    while(strcmp(((Student*)list->head->data)->name, name) != 0 || prevL == NULL){
      // prevL = currL;
      // currL = currL->next;
      prevL = list->head;
      list->head = list->head->next;  //move to next item to search
    }
      //succesfully found the name
      deleteHead = list->head;
      list->head = prevL;

      list->head->next = deleteHead->next;  //deleting the data
      list->head = tempHead;//restore the head
      list->len--;
  }
}

void listRemoveByKey(LinkedList *list, uint32_t key, Compare compareFunc){
  //preserve the head
  Item *tempHead = list->head;
  Item *deleteHead = NULL;
  Item *prevL = NULL;
  if (list->head == NULL)
  {
    return;
  }
  else
  {
    while (prevL != NULL)
    {
      if(compareFunc((void*)&(((Data *)(list->head->data))->key), (void*)&key) == 1){
        break;
      }
      prevL = list->head;
      list->head = list->head->next; //move to next item to search
    }
    //succesfully found the name
    if(prevL == NULL){
      Throw(createException("key given not available in the hash", HASH_KEY_NA));
      return ;
    }
    deleteHead = list->head;
    free(list->head);
    list->head = prevL;

    list->head->next = deleteHead->next; //deleting the data
    list->head = tempHead;               //restore the head
    list->len--;
  }
}

Item *listSearch(LinkedList list, uint32_t key, Compare compareFunc){
  while(list.head != NULL){
    if (compareFunc((void*)&(((Data *)(list.head->data))->key), (void*)&key) == 1){
      return list.head;
    }
    list.head = list.head->next;
  }
  Throw(createException("key given not available in the hash", HASH_KEY_NA));
  return NULL;
}

void createItem(Item *item, void *data, Item *next){
  item->data = data;
  item->next = next;
}

