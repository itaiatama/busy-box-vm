#include "operation.h"

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