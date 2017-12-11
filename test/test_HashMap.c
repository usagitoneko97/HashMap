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

/**
 * 
 *    bucket
 *    |12| 
 *    |13| 
 *    |14|                              
 *    |15| ---NULL                                 
 *            
 * 
 *     ---------
 *             |
 *        add NULL
 *  
 *    bucket
 *    |14|                              
 *    |15| ---  NULL
 *    |16|                  
 *                    
 * 
 */
/*
void test_addHashTable_given_empty_table_add_null_data_expect_NULL_DATA_Exception_to_be_thrown(void){
    HashTable table;
    int dataInt = 5;
    hashMapInit(&table, 10, 3);
    Data *data = NULL;

    Try
    {
        hashMapAdd(&table, data);
        TEST_FAIL_MESSAGE("expect null data exception to be thrown!");
    }
    Catch(ex)
    {
        dumpException(ex);
    }
}*/
/**
 * 
 *    bucket
 *    |12| 
 *    |13| 
 *    |14|                              
 *    |15| ---NULL                                 
 *            
 * 
 *     ---------
 *             |
 *        add key(x) value : int 5 
 *       Expect : _hashMapAddInt func will add data in bucket 5, regardless of the key value of the data
 *  
 *    bucket
 *    |14|                              
 *    |15| --- key15    
 *    |16|       \            
 *             int15         
 * 
 */
void test_hashMapAddInt_given_empty_hash_table_add_key_5_value_5_in_index_5(void)
{
    HashTable table;
    int dataInt = 5;
    hashMapInit(&table, 10, 3);
    Data *data = dataCreate(999999, (void *)&dataInt);
    Try{
        _hashMapAddInt(&table, data, 5);   
    }Catch(ex){
        dumpException(ex);
    }

    TEST_ASSERT_NOT_NULL(table.list);
    TEST_ASSERT_EQUAL(5, *(int *)(((Data *)(table.list[5].head->data))->value));
}

/**
 * 
 *    bucket
 *    |12| 
 *    |13| 
 *    |14|                              
 *    |15| ---NULL                                 
 *            
 * 
 *     ---------
 *             |
 *        add key15 value : int 15 
 *       Expect : key 15 % 30 = 15, will be stored inside bucket 15
 *  
 *    bucket
 *    |14|                              
 *    |15| --- key15    
 *    |16|       \            
 *             int15         
 * 
 */
void test_hashMapAddIntInteger_add_key15_value_int_15_expect_hashValue_15(void){
    HashTable table;
    hashMapInit(&table, 10, 3);
    //add int 15 key 15 to table
    hashMapAddInt(&table, 15, 15);
    TEST_ASSERT_NOT_NULL(table.list);
    TEST_ASSERT_EQUAL(15, *(int *)(((Data *)(table.list[15].head->data))->value));
}

/**
 * 
 *    bucket
 *    |1| 
 *    |2| ---NULL                                 
 *    |3|                              
 *    |4| ---
 *    |5|    
 *            
 * 
 *     ---------
 *             |
 *        add key32 value : int 20 
 *       Expect : key 32 % 30 = 2, will be stored inside bucket 2
 *  
 *    bucket
 *    |1|                              
 *    |2| --- key32    
 *    |3|      \            
 *            int20         
 * 
 */
void test_hashMapAddIntInteger_add_key32_value_int_20_expect_hashValue_2(void){
    HashTable table;
    hashMapInit(&table, 10, 3);
    //add int 20 to key 32
    hashMapAddInt(&table, 20, 32);

    TEST_ASSERT_EQUAL(20, *(int *)(((Data *)(table.list[2].head->data))->value));
}

/**
 * 
 *    bucket
 *    |12| 
 *    |13|                                 
 *    |14|                              
 *    |15| --- key52  
 *    |16|      \           
 *            int23        
 * 
 *     ---------
 *             |
 *        add key15 value : int 15
 *  
 *    bucket
 *    |12| 
 *    |13|                                
 *    |14|                               
 *    |15| --- key32  ----  key15   
 *    |16|      \            \
 *            int23         int 15
 * 
 */
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

/**
 * 
 *    bucket
 *    |12| 
 *    |13|                                 
 *    |14|                              
 *    |15| --- key32  ----  key15   
 *    |16|      \            \
 *            int15         int34
 * 
 *     ---------
 *             |
 *        add key15 value : "spangle call illi line"
 *  
 *    bucket
 *    |12| 
 *    |13|                                
 *    |14|                               
 *    |15| --- key32  ----  key15   
 *    |16|      \            \
 *            int15         "spangle call illi line"
 * 
 */
void test_addHashTable_given_add_2_duplicate_key_expect_hashTable_update_value_to_the_newest_key_entry(void){
    HashTable table;
    hashMapInit(&table, 10, 3);

    
    Try
    {
        // create a data that the key is not the same with the rest
        int dataInt15 = 15;
        Data *data15 = dataCreate(32, (void *)&dataInt15);
        _hashMapAddInt(&table, (void *)data15, 15);

        //load value int 23 to bucket 15 (key 15)
        hashMapAddInt(&table, 23, 15);

        //load value string "" to also bucket 15 (key15)
        hashMapAddStr(&table, "Spangle call illi line", 15);
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
 *    |3| --- key12  ----  key5  ----  key8            
 *    |4|      \            \            \
 *           "stella"       "Jang"     "carol's"
 */
void test_hashTableSearch_given_key12_key5_key8_search_key3_expect_NO_CHANGED_KEY_NA_exception_thrown(void)
{
    HashTable table;
    hashMapInit(&table, 10, 3);

    Try
    {
        char *string1 = "stella";
        Data *data1 = dataCreate(12, (void *)string1);
        _hashMapAddInt(&table, (void *)data1, 3);

        char *string2 = "Jang";
        Data *data2 = dataCreate(5, (void *)string2);
        _hashMapAddInt(&table, (void *)data2, 3);

        char *string3 = "carol's";
        Data *data3 = dataCreate(8, (void *)string3);
        _hashMapAddInt(&table, (void *)data3, 3);

        void *dataReturn = hashMapSearchKeyInt(&table, 3);
        TEST_FAIL_MESSAGE("expect key not available exception to be thrown!");
    }
    Catch(ex)
    {
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

/**
 * 
 *    bucket
 *    |0| 
 *    |1|                                      search key3     return "Jang"
 *    |2|                                        ----->
 *    |3| --- key12  ----  key5  ----  key8            
 *    |4|      \            \            \
 *           "stella"       "Jang"     "carol's"
 */
void test_hashTableRemove_given_key12_key5_key8_remove_key3_expect_NO_CHANGED_KEY_NA_exception_thrown(void){
    HashTable table;
    hashMapInit(&table, 10, 3);

    Try
    {
        char *string1 = "stella";
        Data *data1 = dataCreate(12, (void *)string1);
        _hashMapAddInt(&table, (void *)data1, 3);

        char *string2 = "Jang";
        Data *data2 = dataCreate(5, (void *)string2);
        _hashMapAddInt(&table, (void *)data2, 3);

        char *string3 = "carol's";
        Data *data3 = dataCreate(8, (void *)string3);
        _hashMapAddInt(&table, (void *)data3, 3);

        hashMapRemoveKeyInt(&table, 3);
        TEST_FAIL_MESSAGE("expect key not available exception to be thrown!");
        
    }
    Catch(ex)
    {
        TEST_ASSERT_EQUAL_STRING("stella", (char *)(((Data *)(table.list[3].head->data))->value));
        TEST_ASSERT_EQUAL_STRING("Jang", (char *)(((Data *)(table.list[3].head->next->data))->value));
        TEST_ASSERT_EQUAL_STRING("carol's", (char *)(((Data *)(table.list[3].head->next->next->data))->value));
        dumpException(ex);
    }
}

/**
 * 
 *    bucket
 *    |0|                                                                                                     
 *    |1|                                                                              
 *    |2|                                                                                        
 *    |3| --- key12  ----  key3  ----  key8                                                                  
 *    |4|      \            \            \                                                            
 *           "stella"       "Jang"     "carol's"   
 *           
 *    -----
 *        |        
 *    remove key3
 * 
 *    |0|                                       
 *    |1|                                       
 *    |2|                                       
 *    |3| --- key12  ----    key8     
 *    |4|      \               \      
 *          "stella"         "carol's"                                       
 */
void test_hashTableRemove_given_key12_key3_key8_on_bucket_3_remove_key3(void){
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

        hashMapRemoveKeyInt(&table, 3);

        TEST_ASSERT_EQUAL_STRING("stella", (char *)(((Data *)(table.list[3].head->data))->value));
        TEST_ASSERT_EQUAL_STRING("carol's", (char *)(((Data *)(table.list[3].head->next->data))->value));
    }
    Catch(ex)
    {
        dumpException(ex);
    }
}

void test_hashTableAdd_given_key_string_stella_data_int_5(void){

}