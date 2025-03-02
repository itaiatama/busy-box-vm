#ifndef  BBOX_VALUE_H
#define  BBOX_VALUE_H

#include <assert.h>
#include <stdio.h>

#include "types.h"
#include "return_code.h"

#define MAKE_VALUE_I64(v) (Value) { .type = VALUE_TYPE_I64, .data = v }

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

// Function to dump value into stdout (with type description)
void bbox_value_dump(Value* value);

// Function to sum (add) two values
ReturnCode bbox_value_add(Value* a, Value* b, Value* out);

#endif //BBOX_VALUE_H
