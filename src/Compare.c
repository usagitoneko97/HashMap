#include "Compare.h"

int compareKeyInt(void *key1, void *key2){
    int intKey1 = *(int *)key1;
    int intKey2 = *(int *)key2;

    return intKey1 == intKey2;
}