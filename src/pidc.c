#include <stdlib.h>

#include "pidc.h"
#include "pidc_internal.h"

void pidc_create(pidc_t **pidc_ptr, int32_t kp, int32_t ki, int32_t kd) {
    pidc_t *pidc = (pidc_t *) malloc(sizeof(pidc_t));
    *pidc_ptr = pidc;
    pidc->kp = kp;
    pidc->ki = ki;
    pidc->kd = kd;
    pidc->last_e = 0;
    pidc->total_e = 0;
}

int32_t pidc_update(pidc_t *const pidc, int32_t e) {
    pidc->total_e += e;

    int32_t p_gain = pidc->kp * e;
    int32_t i_gain = pidc->ki * pidc->total_e;
    int32_t d_gain = pidc->kd * (e - pidc->last_e);

    pidc->last_e = e;
    return p_gain + i_gain + d_gain;
}
