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

// Function to push value on top of the VM stack
ReturnCode bbox_vm_stack_push(Vm* vm, Value value);

// Function to pop value from top of the VM stack
ReturnCode bbox_vm_stack_pop(Vm* vm, Value* value);

// Debug function to dump current content of the VM stack
void bbox_vm_stack_dump(Vm* vm);

#endif //BBOX_VM_H
