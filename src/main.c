#include <stdio.h>
#include <assert.h>

#include "return_code.h"
#include "sequence.h"

int main(void) {

    Vm vm = { 0 };

    Value v1 = MAKE_VALUE_I64({1});
    Value v2 = MAKE_VALUE_I64({2});

    Op ops[] = {

        MAKE_OP_0(OP_CODE_NOP)       ,
        MAKE_OP_0(OP_CODE_NOP)       ,
        MAKE_OP_0(OP_CODE_NOP)       ,
        MAKE_OP_1(OP_CODE_PUSH, &v1) ,
        MAKE_OP_1(OP_CODE_PUSH, &v2) ,
        MAKE_OP_0(OP_CODE_ADD)       ,
        MAKE_OP_0(OP_CODE_HALT)      ,
    };

    Sequence seq = { .operation = ops };
    ReturnCode code = bbox_execute_sequence(&vm, &seq);

    bbox_vm_stack_dump(&vm);

    printf("%s\n", return_code_report[code]);
    return 0;
}

