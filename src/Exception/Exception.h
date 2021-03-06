#ifndef _EXCEPTION_H
#define _EXCEPTION_H


#define HASH_INDEX_EXCEED   1
#define ROOT_NULL           2
#define HASH_KEY_NA         3
#define HASH_DATA_NULL      4
typedef struct Exception Exception;
typedef Exception *ExceptionPtr;
struct Exception
{
    char *msg;
    int errorCode;
};

Exception *createException(char *msg, int errorCode);
void freeException(Exception *e);
void dumpException(Exception *e);

#endif // _EXCEPTION_H
