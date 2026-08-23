#include "vibration_processing.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int16_t samples[] = {100, -100, 200, -200};
    uint32_t rmsMg = 0;

    if (!VibrationProcessing_CalculateRms(
            samples,
            4U,
            &rmsMg))
    {
        printf("FAIL: calculation returned false.\n");
        return EXIT_FAILURE;
    }

    if (rmsMg != 158U)
    {
        printf("FAIL: expected 158, got %u.\n", rmsMg);
        return EXIT_FAILURE;
    }

    printf("PASS: RMS calculation test.\n");

    return EXIT_SUCCESS;
}