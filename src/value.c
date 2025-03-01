#include "value.h"

void bbox_value_dump(Value* value) {
    assert(VALUE_TYPE_COUNT == 1 && "New value type was added, update 'bbox_value_dump' switch-case");

    switch(value->type) {
        case VALUE_TYPE_I64:
            printf("%ld [I64]", value->data.I64);
        break;

        default:
            assert(0 && "Unreahcable");
        break;
    }
}

ReturnCode bbox_value_add(Value* a, Value* b, Value* out) {
    assert(VALUE_TYPE_COUNT == 1 && "New value type was added, update 'bbox_value_add' switch-case");

    if(a->type != b->type) {
        return RETURN_CODE_OPERANDS_TYPE_MISSMATCH;
    }

    switch(a->type) {
        case VALUE_TYPE_I64:
            {
                out->type = VALUE_TYPE_I64;
                out->data.I64 = a->data.I64 + b->data.I64;
            }
        break;

        default:
            assert(0 && "Unreahcable");
        break;
    }

    return RETURN_CODE_OK;
}
