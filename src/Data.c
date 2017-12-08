#include "Data.h"
#include <malloc.h>
Data *dataCreate(uint32_t key, void *value){
    Data *data = (Data*)malloc(sizeof(Data));
    data->key = key;
    data->value = value;
    return data;
}
