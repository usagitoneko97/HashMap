#include <stdlib.h>
#include <malloc.h>
#include "unity.h"
#include "HashMap.h"
#include "Compare.h"
#include "linkedlist.h"
#include "Data.h"
#include "Exception.h"
#include "CException.h"

CEXCEPTION_T ex;
void setUp(void)
{
}

void tearDown(void)
{
}


void test_hashMapAddInt_given_empty_hash_table_add_key_5_value_5_in_index_5(void)
{
    HashTable table;
    int dataInt = 5;
    hashMapInit(&table, 10, 3);
    Data *data = dataCreate(5, (void *)&dataInt);
    Try{
        _hashMapAddInt(&table, data, 5);   
    }Catch(ex){
        dumpException(ex);
    }

    TEST_ASSERT_NOT_NULL(table.list);
    TEST_ASSERT_EQUAL(5, *(int *)(((Data *)(table.list[5].head->data))->value));
}

void test_hashMapAddIntInteger_add_key15_value_int_15_expect_hashValue_15(void){
    HashTable table;
    hashMapInit(&table, 10, 3);
    int dataInt = 15;
    Data *data = dataCreate(15, (void *)&dataInt);    
    hashMapAdd(&table, (void*)data);
    TEST_ASSERT_NOT_NULL(table.list);
    TEST_ASSERT_EQUAL(15, *(int *)(((Data *)(table.list[15].head->data))->value));
}

void test_hashMapAddIntInteger_add_key32_value_int_20_expect_hashValue_2(void){
    HashTable table;
    hashMapInit(&table, 10, 3);
    int dataInt = 20;
    Data *data = dataCreate(32, (void *)&dataInt);
    hashMapAdd(&table, (void*)data);

    TEST_ASSERT_EQUAL(20, *(int *)(((Data *)(table.list[2].head->data))->value));
}


void test_hashMapAddIntInteger_add_15_given_collision_expect_15_addedTo_linkedlist_chain(void){
    HashTable table;
    hashMapInit(&table, 10, 3);
    //preload value 23 to bucket 15 to create collision
    int dataInt23 = 23;
    Data *data23 = dataCreate(52, (void *)&dataInt23);
    _hashMapAddInt(&table, (void*)data23, 15);

    int dataInt15 = 15;
    Data *data15 = dataCreate(15, (void *)&dataInt15);

    Try{
        _hashMapAddInt(&table, (void*)data15, 15);
    }Catch(ex){
        dumpException(ex);
    }
    TEST_ASSERT_EQUAL(23, *(int *)(((Data *)(table.list[15].head->data))->value)    );
    TEST_ASSERT_EQUAL(15, *(int *)(((Data *)(table.list[15].head->next->data))->value));
    TEST_ASSERT_EQUAL(15, *(int *)(((Data *)(table.list[15].tail->data))->value));
}

void test_hashValue_exceed_total_bucket_size_expect_throw_exception(void){
    HashTable table;
    //hashMap size 2, sizeFactor 3, totalSize = 6
    hashMapInit(&table, 2, 3);
    int dataInt = 23;
    Data *data = dataCreate(7, (void *)&dataInt);
    Try{
        _hashMapAddInt(&table, (void *)data, 7);
        TEST_FAIL_MESSAGE("expect exception to be thrown when data added is out of the range of hashMap");
    }Catch(ex){
        dumpException(ex);
    }
}

void test_addHashTable_given_add_2_duplicate_key_expect_hashTable_update_value_to_the_newest_key_entry(void){
    HashTable table;
    hashMapInit(&table, 10, 3);

    // create a data that the key is not the same with the rest
    int dataInt15 = 15;
    Data *data15 = dataCreate(32, (void *)&dataInt15);
    Try
    {
        _hashMapAddInt(&table, (void *)data15, 15);

        //load value int 23 to bucket 15 (key 15)
        int valueInt = 23;
        Data *dataInt = dataCreate(15, (void *)&valueInt);
        hashMapAdd(&table, dataInt);

        //load value string "" to also bucket 15 (key15)
        char *valueStr = "Spangle call illi line";
        Data *dataStr = dataCreate(15, (void *)valueStr);
        hashMapAdd(&table, dataStr);
    }
    Catch(ex)
    {
        dumpException(ex);
    }
    
    TEST_ASSERT_EQUAL(15, *(int *)(((Data *)(table.list[15].head->data))->value));
    printf("string 1 = %s", (char *)(((Data *)(table.list[15].head->next->data))->value));
    TEST_ASSERT_EQUAL_STRING("Spangle call illi line", (char *)(((Data *)(table.list[15].head->next->data))->value));
    // TEST_ASSERT_EQUAL(15, *(int *)(((Data *)(table.list[15].tail->data))->value));
}

/**
 * 
 *    bucket
 *    |0| 
 *    |1|                             search key3     return value23
 *    |2|                               ----->
 *    |3| --- key3  ----  key12   
 *    |4|      \            \
 *           value23        value34
 */
void test_hashTableGet_given_key3_value_int23_key12_value_int34(void){
    HashTable table;
    hashMapInit(&table, 10, 3);

    Try{
        int dataInt23 = 23;
        Data *data23 = dataCreate(3, (void *)&dataInt23);
        _hashMapAddInt(&table, (void *)data23, 3);
        int dataInt34 = 34;
        Data *data34 = dataCreate(12, (void *)&dataInt34);
        _hashMapAddInt(&table, (void *)data34, 3);

        TEST_ASSERT_EQUAL(23, *(int *)(((Data *)(table.list[3].head->data))->value));
        TEST_ASSERT_EQUAL(34, *(int *)(((Data *)(table.list[3].head->next->data))->value));

        void *dataReturn = hashMapSearchKeyInt(&table, 3);
        TEST_ASSERT_NOT_NULL(dataReturn);
        TEST_ASSERT_EQUAL(23, *(int*)((Data*)(((Item*)(dataReturn))->data))->value);
        
    }Catch(ex){
        dumpException(ex);
    }
}

/**
 * 
 *    bucket
 *    |0| 
 *    |1|                                      search key3     return "Jang"
 *    |2|                                        ----->
 *    |3| --- key12  ----  key3  ----  key8            
 *    |4|      \            \            \
 *           "stella"       "Jang"     "carol's"
 */
void test_hashTableGet_given_key3_value_String1_key12_value_string2(void)
{
    HashTable table;
    hashMapInit(&table, 10, 3);

    Try
    {
        char *string1 = "stella";
        Data *data1 = dataCreate(12, (void *)string1);
        _hashMapAddInt(&table, (void *)data1, 3);

        char *string2 = "Jang";
        Data *data2 = dataCreate(3, (void *)string2);
        _hashMapAddInt(&table, (void *)data2, 3);

        char *string3 = "carol's";
        Data *data3 = dataCreate(8, (void *)string3);
        _hashMapAddInt(&table, (void *)data3, 3);

        void *dataReturn = hashMapSearchKeyInt(&table, 3);
        TEST_ASSERT_NOT_NULL(dataReturn);
        TEST_ASSERT_EQUAL_STRING("Jang", (char *)((Data *)(((Item *)(dataReturn))->data))->value);
    }
    Catch(ex)
    {
        dumpException(ex);
    }
}