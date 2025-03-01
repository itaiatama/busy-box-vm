#include <stdio.h>
#include <assert.h>

#include "return_code.h"
#include "sequence.h"

int main(void) {

    Op ops[] = {
        (Op) { .code = OP_CODE_NOP  },
        (Op) { .code = OP_CODE_NOP  },
        (Op) { .code = OP_CODE_NOP  },
        (Op) { .code = OP_CODE_HALT },
    };

    Sequence seq = { .operation = ops };

    ReturnCode code = bbox_execute_sequence(&seq);

    printf("%s\n", return_code_report[code]);
    return 0;
}

