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
    TEST_ASSERT_NOT_NULL(table.list[5]);
    TEST_ASSERT_EQUAL(5, *(int *)table.list[5]->head->data);
}
