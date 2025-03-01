#ifndef  BBOX_OPERATION_H
#define  BBOX_OPERATION_H

#include <stdio.h>
#include "return_code.h"
#include "value.h"
#include "vm.h"

#define MAKE_OP_0(c)     (Op) { .code = c, .count = 0, .operand = NULL }
#define MAKE_OP_1(c, v1) (Op) { .code = c, .count = 1, .operand = v1   }

typedef enum {
    OP_CODE_NOP  ,
    OP_CODE_PUSH ,
    OP_CODE_ADD  ,
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
ReturnCode bbox_execute_op(Vm* vm, Op* op);

#endif //BBOX_OPERATION_H
