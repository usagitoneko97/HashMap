#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct Item Item;
typedef struct LinkedList LinkedList;
typedef struct Student Student;
#include <stdint.h>
#include "Compare.h"
#include "Data.h"

struct Student{
  char name[256];
  int age;
  float weight;
  float height;
};

struct Item{
  Item* next;
  void* data;
};

struct LinkedList{
  Item *head;
  Item *tail;
  int len;
};


void ListInit(LinkedList *list);
void ListAddEmptyLinkedList (LinkedList *list, Item *item);
void ListAddLinkedList(LinkedList *list, Item *item);
Item* ListRemoveFirst(LinkedList *list);
Item* ListRemoveLinkedListByName(char* name, LinkedList *list);
void listRemoveByKey(LinkedList *list, uint32_t key, Compare compareFunc);
void createItem(Item *item, void *data, Item *next);
Item *listSearch(LinkedList list, uint32_t key, Compare compareFunc);
#endif // _LINKEDLIST_H
