#include "unity.h"
#include "linkedlist.h"

Student ali = {
  "Ali",
  23,
  72.35,
  1.78
};

Item itemAli = {
  (Item *)342523452,  //next
  (void *)&ali       //data
};

Student baba = {
  "baba",
  22,
  71.35,
  2.78
};

Item itemBaba = {
  (Item *)3425152,  //next
  (void *)&baba       //data
};

Student abu = {
  "abu",
  25,
  76.35,
  2.58
};

Item itemAbu = {
  (Item *)3425152,  //next
  (void *)&abu       //data
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
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
  TEST_ASSERT_EQUAL(0, list.len);
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
    (Item *)342523452,  //next
    (void *)&ali       //data
  };
  ListInit(&list);
  ListAddEmptyLinkedList(&list, &itemAli);
  TEST_ASSERT_EQUAL_PTR(&itemAli, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemAli, list.tail);
  TEST_ASSERT_EQUAL(1, list.len);
  TEST_ASSERT_NULL(itemAli.next);
}

void test_ListAddLinkedList_2_addwith_1(void){
  LinkedList list;
  list.head = &itemAli;
  list.tail = &itemAli;
  list.len = 1;
  itemAli.next = NULL;
  itemBaba.next = (Item *)-1; //item needed to add

  ListAddLinkedList(&list, &itemBaba);

  TEST_ASSERT_EQUAL_PTR(&itemAli, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemBaba, list.tail);
  TEST_ASSERT_EQUAL(2, list.len);

  TEST_ASSERT_EQUAL_PTR(&itemBaba, itemAli.next);

  TEST_ASSERT_NULL(itemBaba.next);

  TEST_ASSERT_EQUAL_PTR(&baba, itemBaba.data);
}

void test_ListAddLinkedList_3_addwith_1(void){
  LinkedList list;
  list.head = &itemAli;
  list.tail = &itemBaba;
  list.len = 2;
  itemAli.next = &itemBaba;
  itemBaba.next = NULL; //item needed to add
  ListAddLinkedList(&list, &itemAbu);

  TEST_ASSERT_EQUAL_PTR(&itemAli, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemAbu, list.tail);
  TEST_ASSERT_EQUAL(3, list.len);

  TEST_ASSERT_EQUAL_PTR(&itemBaba, itemAli.next);
  TEST_ASSERT_EQUAL_PTR(&itemAbu, itemBaba.next);

  TEST_ASSERT_NULL(itemAbu.next);

}

void test_removeFirstList(void){
  LinkedList list;
  ListInit(&list);
  ListAddLinkedList(&list, &itemAli);
  ListAddLinkedList(&list, &itemAbu);
  ListAddLinkedList(&list, &itemBaba);
  ListRemoveFirst(&list);
  TEST_ASSERT_EQUAL_PTR(&itemAbu, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemBaba, list.tail);
  TEST_ASSERT_EQUAL_PTR(&itemAbu, itemAli.next);
  TEST_ASSERT_EQUAL_PTR(&itemBaba, itemAbu.next);
}

void test_removeLinkedList_ali_abu_baba_remove_abu_expect_ali_baba(void){
  LinkedList list;
  ListInit(&list);
  ListAddLinkedList(&list, &itemAli);
  ListAddLinkedList(&list, &itemAbu);
  ListAddLinkedList(&list, &itemBaba);
  ListRemoveLinkedListByName("abu", &list);
  TEST_ASSERT_EQUAL_PTR(&itemBaba, itemAli.next); //Ali next is baba
  TEST_ASSERT_EQUAL_PTR(&itemAli, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemBaba, list.tail);
  TEST_ASSERT_EQUAL(2, list.len);
}
// void test_removeLinkedList_ali_abu_remove_abu_expect_ali(void){
//   LinkedList list;
//   ListInit(&list);
//   ListAddLinkedList(&list, &itemAli);
//   ListAddLinkedList(&list, &itemAbu);
//   ListRemoveLinkedListByName("abu", &list);
//   TEST_ASSERT_EQUAL(&itemAli, list.head);
//   TEST_ASSERT_NULL(itemAli.next);
//
//   TEST_ASSERT_EQUAL(1, list.len);
// }
// void test_removeLinkedList_ali_remove_ali_expect_null(void){
//   LinkedList list;
//   ListInit(&list);
//   ListAddLinkedList(&list, &itemAli);
//   ListRemoveLinkedListByName("ali", &list);
//   TEST_ASSERT_NULL(list.head);
//
//   TEST_ASSERT_EQUAL(0, list.len);
// }
