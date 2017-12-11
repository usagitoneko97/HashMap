#include "unity.h"
#include "Compare.h"
#include <stdint.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void dummy(void *str){
    // printf("my favourite artist : %s", (char*)str);
    printf("my favourite artist : %d", (int)str);
}

void test_dummy(void){
    dummy((void*)(intptr_t)19);
}

