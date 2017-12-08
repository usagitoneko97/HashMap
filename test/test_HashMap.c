#include <stdlib.h>
#include <malloc.h>
#include "unity.h"
#include "HashMap.h"
#include "Compare.h"
#include "linkedlist.h"
#include "Data.h"
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
    hashMapInit(&table, 10, 3);
    Data *data = dataCreate(5, (void *)&dataInt);
    _hashMapAdd(&table, data, 5);

    TEST_ASSERT_NOT_NULL(table.list);
    TEST_ASSERT_EQUAL(5, *(int *)(((Data *)(table.list[5].head->data))->value));
}

void test_hashMapAddInteger_add_key15_value_int_15_expect_hashValue_15(void){
    HashTable table;
    hashMapInit(&table, 10, 3);
    int dataInt = 15;
    Data *data = dataCreate(15, (void *)&dataInt);    
    hashMapAddInteger(&table, (void*)data);
    TEST_ASSERT_NOT_NULL(table.list);
    TEST_ASSERT_EQUAL(15, *(int *)(((Data *)(table.list[15].head->data))->value));
}

void test_hashMapAddInteger_add_key32_value_int_20_expect_hashValue_2(void){
    HashTable table;
    hashMapInit(&table, 10, 3);
    int dataInt = 20;
    Data *data = dataCreate(32, (void *)&dataInt);
    hashMapAddInteger(&table, (void*)data);

    TEST_ASSERT_EQUAL(20, *(int *)(((Data *)(table.list[2].head->data))->value));
}


void test_hashMapAddInteger_add_15_given_collision_expect_15_addedTo_linkedlist_chain(void){
    HashTable table;
    hashMapInit(&table, 10, 3);
    //preload value 23 to bucket 15 to create collision
    int dataInt23 = 23;
    Data *data23 = dataCreate(15, (void *)&dataInt23);
    _hashMapAdd(&table, (void*)data23, 15);
    TEST_ASSERT_EQUAL(23, *(int *)(((Data *)(table.list[15].head->data))->value));

    int dataInt15 = 15;
    Data *data15 = dataCreate(15, (void *)&dataInt15);
    _hashMapAdd(&table, (void*)data15, 15);
    TEST_ASSERT_EQUAL(23, *(int *)(((Data *)(table.list[15].head->data))->value));
    TEST_ASSERT_EQUAL(15, *(int *)(((Data *)(table.list[15].head->next->data))->value));
    TEST_ASSERT_EQUAL(15, *(int *)(((Data *)(table.list[15].tail->data))->value));
}

void xtest_hashValue_exceed_total_bucket_size_expect_throw_exception(void){
    
}

//TEST ADD HASH value is larger than init hash value
//add duplicate value should not add inside hash