#include "return_code.h"

// If assertion failed, update 'return_code_report' array with new return code
static_assert(RETURN_CODE_COUNT == 3);
const char* return_code_report[RETURN_CODE_COUNT] = 
{
    [RETURN_CODE_OK         ] = "OK",
    [RETURN_CODE_EMPTY_INPUT] = "No input was provided",
    [RETURN_CODE_HALTED     ] = "Execution is halted",
};
