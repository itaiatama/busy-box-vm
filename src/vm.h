#ifndef  BBOX_VM_H
#define  BBOX_VM_H

#define BBOX_STACK_SIZE 256

#include <stdio.h>

#include "value.h"
#include "return_code.h"

typedef struct {
    u64 top;
    Value stack[BBOX_STACK_SIZE];
} Vm;

ReturnCode bbox_vm_stack_push(Vm* vm, Value value);
ReturnCode bbox_vm_stack_pop(Vm* vm, Value* value);

void bbox_vm_stack_dump(Vm* vm);

#endif //BBOX_VM_H
