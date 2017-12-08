#include "build/temp/_test_HashMap.c"
#include "Data.h"
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





void test_hashMapAdd_given_empty_hash_table_add_key_5_value_5_in_index_5(void)

{

    HashTable table;

    int dataInt = 5;

    hashMapInit(&table, 10);

    Data *data = dataCreate(5, (void *)&dataInt);

    _hashMapAdd(&table, data, 5);



    if ((((table.list)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(25))));};

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((*(int *)(((Data *)(table.list[5].head->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_INT);

}



void test_hashMapAddInteger_add_key15_value_int_15_expect_hashValue_15(void){

    HashTable table;

    hashMapInit(&table, 10);

    int dataInt = 15;

    Data *data = dataCreate(15, (void *)&dataInt);

    hashMapAddInteger(&table, (void*)data, 10);

    if ((((table.list)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(35))));};

    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((*(int *)(((Data *)(table.list[15].head->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}



void test_hashMapAddInteger_add_key32_value_int_20_expect_hashValue_2(void){

    HashTable table;

    hashMapInit(&table, 10);

    int dataInt = 20;

    Data *data = dataCreate(32, (void *)&dataInt);

    hashMapAddInteger(&table, (void*)data, 10);



    UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((*(int *)(((Data *)(table.list[2].head->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

}





void test_hashMapAddInteger_add_15_given_collision_expect_15_addedTo_linkedlist_chain(void){

    HashTable table;

    hashMapInit(&table, 10);



    int dataInt23 = 23;

    Data *data23 = dataCreate(15, (void *)&dataInt23);

    _hashMapAdd(&table, (void*)data23, 15);

    UnityAssertEqualNumber((UNITY_INT)((23)), (UNITY_INT)((*(int *)(((Data *)(table.list[15].head->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);



    int dataInt15 = 15;

    Data *data15 = dataCreate(15, (void *)&dataInt15);

    _hashMapAdd(&table, (void*)data15, 15);

    UnityAssertEqualNumber((UNITY_INT)((23)), (UNITY_INT)((*(int *)(((Data *)(table.list[15].head->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((*(int *)(((Data *)(table.list[15].head->next->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((*(int *)(((Data *)(table.list[15].tail->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

}
