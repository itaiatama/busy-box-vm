#include "vm.h"

ReturnCode bbox_vm_stack_push(Vm* vm, Value value) {
    if(vm->top >= BBOX_STACK_SIZE) {
        return RETURN_CODE_STACK_OVERFLOW;
    }

    vm->stack[vm->top++] = value;
    return RETURN_CODE_OK;
}

ReturnCode bbox_vm_stack_pop(Vm* vm, Value* value) {

    if(vm->top - 1 < 0) {
        return RETURN_CODE_STACK_UNDERFLOW;
    }

    *value = vm->stack[--vm->top];
    return RETURN_CODE_OK;
}

void bbox_vm_stack_dump(Vm* vm) {
    printf("=== [STACK DUMP] ===\n");

    for(u64 i = vm->top; i > 0; i--) {
        printf("[%lu]: ", vm->top - i);
        bbox_value_dump(&(vm->stack[i - 1]));
        printf("\n");
    }

    printf("====================\n");
}
