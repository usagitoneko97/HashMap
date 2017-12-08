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





void test_hashMapAdd_given_empty_hash_table_add_value_3_in_index_5(void)

{

    HashTable table;

    int data = 5;

    hashMapInit(&table, 10);

    _hashMapAdd(&table, (void*)&data, 5);



    if ((((table.list)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(23))));};

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((*(int *)table.list[5].head->data)), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}



void test_hashMapAddInteger_add_15_expect_hashValue_15(void){

    HashTable table;

    hashMapInit(&table, 10);

    hashMapAddInteger(&table, 15, 10);

    if ((((table.list)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(31))));};

    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((*(int *)table.list[15].head->data)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

}



void test_hashMapAddInteger_add_32_expect_hashValue_2(void){

    HashTable table;

    hashMapInit(&table, 10);

    hashMapAddInteger(&table, 32, 10);



    UnityAssertEqualNumber((UNITY_INT)((32)), (UNITY_INT)((*(int *)table.list[2].head->data)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

}





void test_hashMapAddInteger_add_15_given_collision_expect_15_addedTo_linkedlist_chain(void){

    HashTable table;

    hashMapInit(&table, 10);



    int data = 23;

    _hashMapAdd(&table, (void*)&data, 15);

    UnityAssertEqualNumber((UNITY_INT)((23)), (UNITY_INT)((*(int *)table.list[15].head->data)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

 int data2 = 15;

    _hashMapAdd(&table, (void*)&data2, 15);

    UnityAssertEqualNumber((UNITY_INT)((23)), (UNITY_INT)((*(int *)table.list[15].head->data)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

    if ((((table.list[15].head->next->data)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(54))));};



    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((*(int *)table.list[15].tail->data)), (

   ((void *)0)

   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

}
