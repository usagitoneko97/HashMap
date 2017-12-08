#include <stdlib.h>
#include <malloc.h>
#include "unity.h"
#include "HashMap.h"
#include "Compare.h"
#include "linkedlist.h"
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

    TEST_ASSERT_NOT_NULL(table.list);
    TEST_ASSERT_EQUAL(5, *(int *)table.list[5].head->data);
}

void test_hashMapAddInteger_add_15_expect_hashValue_15(void){
    HashTable table;
    hashMapInit(&table, 10);
    hashMapAddInteger(&table, 15, 10);
    TEST_ASSERT_NOT_NULL(table.list);
    TEST_ASSERT_EQUAL(15, *(int *)table.list[15].head->data);
}

void test_hashMapAddInteger_add_32_expect_hashValue_2(void){
    HashTable table;
    hashMapInit(&table, 10);
    hashMapAddInteger(&table, 32, 10);

    TEST_ASSERT_EQUAL(32, *(int *)table.list[2].head->data);
}


void test_hashMapAddInteger_add_15_given_collision_expect_15_addedTo_linkedlist_chain(void){
    HashTable table;
    hashMapInit(&table, 10);
    //preload value 23 to bucket 15 to create collision
    int data = 23;
    _hashMapAdd(&table, (void*)&data, 15);
    TEST_ASSERT_EQUAL(23, *(int *)table.list[15].head->data);
	int data2 = 15;
    _hashMapAdd(&table, (void*)&data2, 15);
    TEST_ASSERT_EQUAL(23, *(int *)table.list[15].head->data);
    TEST_ASSERT_NOT_NULL(table.list[15].head->next->data);
    // TEST_ASSERT_EQUAL(15, *(int *)table.list[15].head->next->data);
    TEST_ASSERT_EQUAL(15, *(int *)table.list[15].tail->data);
}

//TEST ADD HASH value is larger than init hash value
//add duplicate value should not add inside hash