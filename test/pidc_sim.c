#include <stdio.h>
#include <stdlib.h>

#include "pidc.h"

int main(int argc, char **argv) {
    if (argc != 6) {
        return 1;
    }
    int32_t sp    = atoi(argv[1]);
    int32_t kp    = atoi(argv[2]);
    int32_t ki    = atoi(argv[3]);
    int32_t kd    = atoi(argv[4]);
    int32_t shift = atoi(argv[5]);

    pidc_t *pidc;
    pidc_init(&pidc, kp, ki, kd);
    while (1) {
        int32_t e, pv;
        printf("> ");
        scanf("%d", &pv);
        e = sp - pv;
        int32_t gain = pidc_update(pidc, e) >> shift;
        printf("error %d results in gain %d\n", e, gain);
    }
    return 0;
}
