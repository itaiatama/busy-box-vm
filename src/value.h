#ifndef  BBOX_VALUE_H
#define  BBOX_VALUE_H

#include "types.h"

typedef enum {
    VALUE_TYPE_I64  ,
    VALUE_TYPE_COUNT,
} ValueType;

typedef union {
    i64 I64;
} ValueData;

typedef struct {
    ValueType type;
    ValueData data;
} Value;

#endif //BBOX_VALUE_H