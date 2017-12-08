#include "build/temp/_test_HashMap.c"
#include "CException.h"
#include "Exception.h"
#include "Data.h"
#include "linkedlist.h"
#include "Compare.h"
#include "HashMap.h"
#include "unity.h"




ExceptionPtr ex;

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

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

        _hashMapAdd(&table, data, 5, compareKeyInt);;

    }else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

        dumpException(ex);

    }



    if ((((table.list)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(33))));};

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((*(int *)(((Data *)(table.list[5].head->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

}



void test_hashMapAddIntInteger_add_key15_value_int_15_expect_hashValue_15(void){

    HashTable table;

    hashMapInit(&table, 10, 3);

    int dataInt = 15;

    Data *data = dataCreate(15, (void *)&dataInt);

    hashMapAdd(&table, (void*)data);

    if ((((table.list)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(43))));};

    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((*(int *)(((Data *)(table.list[15].head->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

}



void test_hashMapAddIntInteger_add_key32_value_int_20_expect_hashValue_2(void){

    HashTable table;

    hashMapInit(&table, 10, 3);

    int dataInt = 20;

    Data *data = dataCreate(32, (void *)&dataInt);

    hashMapAdd(&table, (void*)data);



    UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((*(int *)(((Data *)(table.list[2].head->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);

}





void test_hashMapAddIntInteger_add_15_given_collision_expect_15_addedTo_linkedlist_chain(void){

    HashTable table;

    hashMapInit(&table, 10, 3);



    int dataInt23 = 23;

    Data *data23 = dataCreate(52, (void *)&dataInt23);

    _hashMapAdd(&table, (void*)data23, 15, compareKeyInt);;



    int dataInt15 = 15;

    Data *data15 = dataCreate(15, (void *)&dataInt15);



    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    _hashMapAdd(&table, (void*)data15, 15, compareKeyInt);;

    }else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

        dumpException(ex);

    }

    UnityAssertEqualNumber((UNITY_INT)((23)), (UNITY_INT)((*(int *)(((Data *)(table.list[15].head->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((*(int *)(((Data *)(table.list[15].head->next->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((*(int *)(((Data *)(table.list[15].tail->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

}



void test_hashValue_exceed_total_bucket_size_expect_throw_exception(void){

    HashTable table;



    hashMapInit(&table, 2, 3);

    int dataInt = 23;

    Data *data = dataCreate(7, (void *)&dataInt);

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

        _hashMapAdd(&table, (void *)data, 7, compareKeyInt);;

        UnityFail( (("expect exception to be thrown when data added is out of the range of hashMap")), (UNITY_UINT)(87));

    }else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

        dumpException(ex);

    }

}



void test_addHashTable_given_add_2_duplicate_key_expect_hashTable_update_value_to_the_newest_key_entry(void){

    HashTable table;

    hashMapInit(&table, 10, 3);





    int dataInt15 = 15;

    Data *data15 = dataCreate(32, (void *)&dataInt15);

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1)

    {

        _hashMapAdd(&table, (void *)data15, 15, compareKeyInt);;





        int valueInt = 23;

        Data *dataInt = dataCreate(15, (void *)&valueInt);

        hashMapAdd(&table, dataInt);





        char *valueStr = "Spangle call illi line";

        Data *dataStr = dataCreate(15, (void *)valueStr);

        hashMapAdd(&table, dataStr);

    }

    else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A))

    {

        dumpException(ex);

    }



    UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((*(int *)(((Data *)(table.list[15].head->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(119), UNITY_DISPLAY_STYLE_INT);

    printf("string 1 = %s", (char *)(((Data *)(table.list[15].head->next->data))->value));

    UnityAssertEqualString((const char*)(("Spangle call illi line")), (const char*)(((char *)(((Data *)(table.list[15].head->next->data))->value))), (

   ((void *)0)

   ), (UNITY_UINT)(121));



}
