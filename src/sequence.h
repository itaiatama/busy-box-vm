#ifndef  BBOX_SEQUENCE_H
#define  BBOX_SEQUENCE_H

#include <stdlib.h>
#include "operation.h"

typedef struct {
    Op* operation;
} Sequence;

// Executes operation sequence (each with return code == OK) and 
// return latest operation execution return code
// or empty input return code
ReturnCode bbox_execute_sequence(Sequence* sequence);

#endif //BBOX_SEQUENCE_H