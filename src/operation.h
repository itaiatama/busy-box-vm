#ifndef  BBOX_OPERATION_H
#define  BBOX_OPERATION_H

#include <stdio.h>
#include "return_code.h"
#include "value.h"

typedef enum {
    OP_CODE_NOP  ,
    OP_CODE_HALT ,
    OP_CODE_COUNT,
} OpCode;

typedef struct  {
    OpCode code;
    u8 count;
    Value* operand;
} Op;

// Execute single operation (passed as pointer) and 
// return operation execution return code
ReturnCode bbox_execute_op(Op* op);

#endif //BBOX_OPERATION_H