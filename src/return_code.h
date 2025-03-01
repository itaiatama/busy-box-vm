#ifndef  BBOX_RETURN_CODE_H
#define  BBOX_RETURN_CODE_H

#include <assert.h>

typedef enum {
    RETURN_CODE_OK                       ,
    RETURN_CODE_EMPTY_INPUT              ,
    RETURN_CODE_OPERANDS_COUNT_MISSMATCH ,
    RETURN_CODE_OPERANDS_TYPE_MISSMATCH  ,
    RETURN_CODE_STACK_OVERFLOW           ,
    RETURN_CODE_STACK_UNDERFLOW          ,
    RETURN_CODE_HALTED                   ,
    RETURN_CODE_COUNT                    ,
} ReturnCode;


// Human-readable description of the return codes
extern const char* return_code_report[RETURN_CODE_COUNT];

#endif //BBOX_RETURN_CODE_H
