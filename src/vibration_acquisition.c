#include "vibration_acquisition.h"

#include <stddef.h>

bool VibrationAcquisition_Init(void)
{
    return true;
}

bool VibrationAcquisition_GetSamples(
    int16_t *samples,
    uint32_t sampleCapacity,
    uint32_t *sampleCount)
{
    if (samples == NULL)
    {
        return false;
    }

    if (sampleCount == NULL)
    {
        return false;
    }

    if (sampleCapacity < 4U)
    {
        return false;
    }

    samples[0] = 100;
    samples[1] = -100;
    samples[2] = 200;
    samples[3] = -200;

    *sampleCount = 4U;

    return true;
}