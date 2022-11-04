#include <stdio.h>
#include <stdlib.h>

#include "pidc.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        return 1;
    }
    int32_t kp = atoi(argv[1]);
    int32_t ki = atoi(argv[2]);
    int32_t kd = atoi(argv[3]);

    pidc_t *pidc;
    pidc_init(&pidc, kp, ki, kd);
    while (1) {
        int32_t e;
        scanf("%d", &e);
        int32_t gain = pidc_update(pidc, e);
        printf("error %d results in gain %d\n", e, gain);
    }
    return 0;
}
