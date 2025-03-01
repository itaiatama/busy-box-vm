#include <stdio.h>
#include <assert.h>

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

typedef struct {
    Op* operation;
} Sequence;

typedef enum {
    RETURN_CODE_OK         ,
    RETURN_CODE_EMPTY_INPUT,
    RETURN_CODE_HALTED     ,
    RETURN_CODE_COUNT      ,
} ReturnCode;


// If assertion failed, update 'return_code_report' array with new return code
static_assert(RETURN_CODE_COUNT == 3);
const char* return_code_report[RETURN_CODE_COUNT] = 
{
    [RETURN_CODE_OK         ] = "OK",
    [RETURN_CODE_EMPTY_INPUT] = "No input was provided",
    [RETURN_CODE_HALTED     ] = "Execution is halted",
};


ReturnCode bbox_execute_op(Op* op) {
    assert(OP_CODE_COUNT == 2 && "New operation was added, update 'bbox_execute_op' switch-case");

    switch(op->code) {
        case OP_CODE_NOP:
            printf("no-op executed\n");
        break;

        case OP_CODE_HALT:
            return RETURN_CODE_HALTED;
        break;

        default:
            return RETURN_CODE_HALTED;
        break;
    }

    return RETURN_CODE_OK;
}

ReturnCode bbox_execute_sequence(Sequence* sequence) {
    u64 ip = 0;

    if(sequence == NULL) {
        return RETURN_CODE_EMPTY_INPUT;
    }

    ReturnCode code = bbox_execute_op(&(sequence->operation[ip]));
    while(code == RETURN_CODE_OK) {
        ip += 1;
        code = bbox_execute_op(&(sequence->operation[ip]));
    }

    return code;
}

int main(void) {

    Op ops[] = {
        (Op) { .code = OP_CODE_NOP  },
        (Op) { .code = OP_CODE_NOP  },
        (Op) { .code = OP_CODE_NOP  },
        (Op) { .code = OP_CODE_HALT },
    };

    Sequence seq = { .operation = ops };

    ReturnCode code = bbox_execute_sequence(&seq);

    printf("%s\n", return_code_report[code]);
    return 0;
}

