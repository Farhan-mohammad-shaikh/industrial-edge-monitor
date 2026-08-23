#include "vibration_processing.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static bool Test_CalculateRms_ValidSamples(void)
{
    int16_t samples[] = {100, -100, 200, -200};
    uint32_t rmsMg = 0;

    if (!VibrationProcessing_CalculateRms(samples, 4U, &rmsMg))
    {
        printf("FAIL: valid RMS calculation returned false.\n");
        return false;
    }

    if (rmsMg != 158U)
    {
        printf("FAIL: expected 158, got %u.\n", rmsMg);
        return false;
    }

    return true;
}

static bool Test_CalculateRms_NullSamples(void)
{
    uint32_t rmsMg = 0;

    if (VibrationProcessing_CalculateRms(NULL, 4U, &rmsMg))
    {
        printf("FAIL: NULL samples should return false.\n");
        return false;
    }

    return true;
}



int main(void)
{
    if (!Test_CalculateRms_ValidSamples())
    {
        return EXIT_FAILURE;
    }

    if (!Test_CalculateRms_NullSamples())
    {
        return EXIT_FAILURE;
    }

    printf("PASS: all vibration processing tests.\n");

    return EXIT_SUCCESS;
}