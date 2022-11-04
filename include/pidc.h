#ifndef PIDC_H
#define PIDC_H

#include <stdint.h>

typedef struct pidc_t pidc_t;

void pidc_create(pidc_t **pidc_ptr, int32_t kp, int32_t ki, int32_t kd);
int32_t pidc_update(pidc_t *const pidc, int32_t e);

#endif // PIDC_H
