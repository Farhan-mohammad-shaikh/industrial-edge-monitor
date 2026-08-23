#include "vibration_acquisition.h"

#include <stddef.h>

static int16_t vibrationSamples[VIBRATION_SAMPLE_COUNT];

bool VibrationAcquisition_Init(void)
{
    vibrationSamples[0] = 100;
    vibrationSamples[1] = -100;
    vibrationSamples[2] = 200;
    vibrationSamples[3] = -200;

    return true;
}

bool VibrationAcquisition_GetSamples(
    const int16_t **samples,
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

    *samples = vibrationSamples;
    *sampleCount = VIBRATION_SAMPLE_COUNT;

    return true;
}