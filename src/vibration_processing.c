#include "vibration_processing.h"
#include <stddef.h>

bool VibrationProcessing_Init(void)
{
    return true;
}

bool VibrationProcessing_GetRms(uint32_t *vibrationRmsMg)
{
    if(vibrationRmsMg == NULL)
    {
        return false;
    }

    *vibrationRmsMg = 120;

    return true;

}