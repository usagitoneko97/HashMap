#ifndef _DATA_H
#define _DATA_H

#include <stdint.h>

typedef struct Data Data;
struct Data{
    uint32_t key;
    void *value;
};

Data *dataCreate(uint32_t key, void *value);

#endif // _DATA_H
