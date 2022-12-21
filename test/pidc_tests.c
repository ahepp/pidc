#include "unity.h"
#include "pidc.h"

void setUp() {
}

void tearDown() {
}

void gain_after_iter() {
    pidc_t *pidc;
    int32_t kp = 5;
    int32_t ki = 8;
    int32_t kd = 2;
    pidc_init(&pidc, kp, ki, kd);

    int32_t gain = pidc_update(pidc, -100);
    int32_t expected_gain = -500 + -800;

    TEST_ASSERT_EQUAL_INT32(expected_gain, gain);
}

void gain_after_two_iter() {
    pidc_t *pidc;
    int32_t kp = 5;
    int32_t ki = 8;
    int32_t kd = 2;
    pidc_init(&pidc, kp, ki, kd);

    pidc_update(pidc, -100);
    int32_t gain = pidc_update(pidc, -200);
    int32_t expected_gain = -1000 + -2400 + -200;

    TEST_ASSERT_EQUAL_INT32(expected_gain, gain);
}

int main(int argc, char** argv) {
    UNITY_BEGIN();
    RUN_TEST(gain_after_iter);
    RUN_TEST(gain_after_two_iter);
    return UNITY_END();
}
