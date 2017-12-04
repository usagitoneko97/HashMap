#include "build/temp/_test_HashMap.c"
#include "linkedlist.h"
#include "Compare.h"
#include "HashMap.h"
#include "unity.h"
void setUp(void)

{

}



void tearDown(void)

{

}





void test_hashMapAdd_given_empty_hash_table_add_value_3(void)

{

    HashTable table;

    int data = 5;

    hashMapInit(&table, 10);

    _hashMapAdd(&table, (void*)&data, 5);



    if ((((table.list)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(21))));};

    if ((((table.list[5])) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(22))));};

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((*(int *)table.list[5]->head->data)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

}
