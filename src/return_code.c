#include "return_code.h"

// If assertion failed, 
static_assert(RETURN_CODE_COUNT == 7, "New result code was added, update 'return_code_report' array");
const char* return_code_report[RETURN_CODE_COUNT] = 
{
    [RETURN_CODE_OK                      ] = "OK",
    [RETURN_CODE_EMPTY_INPUT             ] = "No input was provided",
    [RETURN_CODE_OPERANDS_COUNT_MISSMATCH] = "Unexpected operand count in operation",
    [RETURN_CODE_OPERANDS_TYPE_MISSMATCH ] = "Operand types are miss-matched" ,
    [RETURN_CODE_STACK_OVERFLOW          ] = "VM stack is overflow",
    [RETURN_CODE_STACK_UNDERFLOW         ] = "VM stack is underflow",
    [RETURN_CODE_HALTED                  ] = "Execution is halted",
};
