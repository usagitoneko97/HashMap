#ifndef _DATA_H
#define _DATA_H

#include <stdint.h>

typedef struct Data Data;
struct Data{
    void *key;
    void *value;
};

Data *dataCreate(void *key, void *value);

#endif // _DATA_H
