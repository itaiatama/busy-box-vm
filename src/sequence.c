#include "sequence.h"

ReturnCode bbox_execute_sequence(Vm* vm, Sequence* sequence) {
    u64 ip = 0;

    if(sequence == NULL) {
        return RETURN_CODE_EMPTY_INPUT;
    }

    ReturnCode code = bbox_execute_op(vm, &(sequence->operation[ip]));
    while(code == RETURN_CODE_OK) {
        ip += 1;
        code = bbox_execute_op(vm, &(sequence->operation[ip]));
    }

    return code;
}
