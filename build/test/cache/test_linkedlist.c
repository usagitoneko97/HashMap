#include "build/temp/_test_linkedlist.c"
#include "linkedlist.h"
#include "unity.h"


Student ali = {

  "Ali",

  23,

  72.35,

  1.78

};



Item itemAli = {

  (Item *)342523452,

  (void *)&ali

};



Student baba = {

  "baba",

  22,

  71.35,

  2.78

};



Item itemBaba = {

  (Item *)3425152,

  (void *)&baba

};



Student abu = {

  "abu",

  25,

  76.35,

  2.58

};



Item itemAbu = {

  (Item *)3425152,

  (void *)&abu

};





void setUp(void)

{

}



void tearDown(void)

{

}



void test_Listlinit_ensure_initialize_to_NULL_and_0(void){

  LinkedList list = {

    (Item*)-1,

    (Item*)-1,

    10};



  ListInit(&list);

  if ((((list.head)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(56))));};

  if ((((list.tail)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(57))));};

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.len)), (

 ((void *)0)

 ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

}



void test_ListAdd_with_emptyList_(void){

  LinkedList list;

  Student ali = {

    "Ali",

    23,

    72.35,

    1.78

  };



  Item itemAli = {

    (Item *)342523452,

    (void *)&ali

  };

  ListInit(&list);

  ListAddEmptyLinkedList(&list, &itemAli);

  UnityAssertEqualNumber((UNITY_INT64)((&itemAli)), (UNITY_INT64)((list.head)), (

 ((void *)0)

 ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&itemAli)), (UNITY_INT64)((list.tail)), (

 ((void *)0)

 ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list.len)), (

 ((void *)0)

 ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT);

  if ((((itemAli.next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(79))));};

}



void test_ListAddLinkedList_2_addwith_1(void){

  LinkedList list;

  list.head = &itemAli;

  list.tail = &itemAli;

  list.len = 1;

  itemAli.next = 

                ((void *)0)

                    ;

  itemBaba.next = (Item *)-1;



  ListAddLinkedList(&list, &itemBaba);



  UnityAssertEqualNumber((UNITY_INT64)((&itemAli)), (UNITY_INT64)((list.head)), (

 ((void *)0)

 ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&itemBaba)), (UNITY_INT64)((list.tail)), (

 ((void *)0)

 ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((list.len)), (

 ((void *)0)

 ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((UNITY_INT64)((&itemBaba)), (UNITY_INT64)((itemAli.next)), (

 ((void *)0)

 ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_HEX64);



  if ((((itemBaba.next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(98))));};



  UnityAssertEqualNumber((UNITY_INT64)((&baba)), (UNITY_INT64)((itemBaba.data)), (

 ((void *)0)

 ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_HEX64);

}



void test_ListAddLinkedList_3_addwith_1(void){

  LinkedList list;

  list.head = &itemAli;

  list.tail = &itemBaba;

  list.len = 2;

  itemAli.next = &itemBaba;

  itemBaba.next = 

                 ((void *)0)

                     ;

  ListAddLinkedList(&list, &itemAbu);



  UnityAssertEqualNumber((UNITY_INT64)((&itemAli)), (UNITY_INT64)((list.head)), (

 ((void *)0)

 ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&itemAbu)), (UNITY_INT64)((list.tail)), (

 ((void *)0)

 ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((list.len)), (

 ((void *)0)

 ), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_INT);



  UnityAssertEqualNumber((UNITY_INT64)((&itemBaba)), (UNITY_INT64)((itemAli.next)), (

 ((void *)0)

 ), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&itemAbu)), (UNITY_INT64)((itemBaba.next)), (

 ((void *)0)

 ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_HEX64);



  if ((((itemAbu.next)) == 

 ((void *)0)

 )) {} else {UnityFail( (((" Expected NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(119))));};



}



void test_removeFirstList(void){

  LinkedList list;

  ListInit(&list);

  ListAddLinkedList(&list, &itemAli);

  ListAddLinkedList(&list, &itemAbu);

  ListAddLinkedList(&list, &itemBaba);

  ListRemoveFirst(&list);

  UnityAssertEqualNumber((UNITY_INT64)((&itemAbu)), (UNITY_INT64)((list.head)), (

 ((void *)0)

 ), (UNITY_UINT)(130), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&itemBaba)), (UNITY_INT64)((list.tail)), (

 ((void *)0)

 ), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&itemAbu)), (UNITY_INT64)((itemAli.next)), (

 ((void *)0)

 ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&itemBaba)), (UNITY_INT64)((itemAbu.next)), (

 ((void *)0)

 ), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_HEX64);

}



void test_removeLinkedList_ali_abu_baba_remove_abu_expect_ali_baba(void){

  LinkedList list;

  ListInit(&list);

  ListAddLinkedList(&list, &itemAli);

  ListAddLinkedList(&list, &itemAbu);

  ListAddLinkedList(&list, &itemBaba);

  ListRemoveLinkedListByName("abu", &list);

  UnityAssertEqualNumber((UNITY_INT64)((&itemBaba)), (UNITY_INT64)((itemAli.next)), (

 ((void *)0)

 ), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&itemAli)), (UNITY_INT64)((list.head)), (

 ((void *)0)

 ), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&itemBaba)), (UNITY_INT64)((list.tail)), (

 ((void *)0)

 ), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((list.len)), (

 ((void *)0)

 ), (UNITY_UINT)(146), UNITY_DISPLAY_STYLE_INT);

}
