#include "vibration_processing.h"
#include <stddef.h>
#include <math.h>

bool VibrationProcessing_Init(void)
{
    return true;
}

bool VibrationProcessing_CalculateRms(const int16_t *samples,uint32_t sampleCount,uint32_t *vibrationRmsMg)
{
    
    if (samples == NULL)
    {
        return false;
    }

    if (vibrationRmsMg == NULL)
    {
        return false;
    }

    if (sampleCount == 0)
    {
        return false;
    }

    uint64_t sumOfSquares = 0;

    for (uint32_t i = 0; i < sampleCount; i++)
    {
        int32_t sample = samples[i];

        sumOfSquares += (uint64_t)(sample * sample);
    }

    uint64_t meanSquare = sumOfSquares / sampleCount;

    *vibrationRmsMg = (uint32_t)sqrt((double)meanSquare);

    return true;

}