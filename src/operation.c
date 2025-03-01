#include "operation.h"

ReturnCode bbox_execute_op(Vm* vm, Op* op) {
    assert(OP_CODE_COUNT == 4 && "New operation was added, update 'bbox_execute_op' switch-case");

    switch(op->code) {
        case OP_CODE_NOP:
            printf("no-op executed\n");
        break;

        case OP_CODE_PUSH:
            {

                if(op->count != 1 || op->operand == NULL) {
                    return RETURN_CODE_OPERANDS_COUNT_MISSMATCH;
                }

                Value value = op->operand[0];
                return bbox_vm_stack_push(vm, value);
            }
        break;

        case OP_CODE_ADD:
            {
                ReturnCode code;
                Value a;
                Value b;
                Value c;

                code = bbox_vm_stack_pop(vm, &b);
                if(code != RETURN_CODE_OK) { return code; }

                code = bbox_vm_stack_pop(vm, &a);
                if(code != RETURN_CODE_OK) { return code; }

                code = bbox_value_add(&a, &b, &c);
                if(code != RETURN_CODE_OK) { return code; }

                code = bbox_vm_stack_push(vm, c);
                if(code != RETURN_CODE_OK) { return code; }
            }
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
