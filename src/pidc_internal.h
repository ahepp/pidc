#ifndef PIDC_INTERNAL_H
#define PIDC_INTERNAL_H

struct pidc_t {
    int32_t kp;
    int32_t ki;
    int32_t kd;
    int32_t total_e;
    int32_t last_e;
};

#endif // PIDC_INTERNAL_H
