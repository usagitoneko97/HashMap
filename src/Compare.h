#ifndef _COMPARE_H
#define _COMPARE_H

typedef int ((*Compare)(void *data, void *refData));
int compareKeyInt(void *key1, void *key2);
int compareKeyStr(void *key1, void *key2);
#endif // _COMPARE_H
