#include <malloc.h>
#include "Data.h"

Data *dataCreate(void *key, void *value){
    Data *data = (Data*)malloc(sizeof(Data));
    data->key = key;
    data->value = value;
    return data;
}
