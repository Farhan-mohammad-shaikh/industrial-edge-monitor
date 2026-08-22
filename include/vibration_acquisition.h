#ifndef VIBRATION_ACQUISATION_H
#define VIBRATION_ACQUISATION_H
#include <stdint.h>
#include <stdbool.h>

bool VibrationAcquisition_Init(void);

bool VibrationAcquisition_GetSamples(
    int16_t *samples,
    uint32_t sampleCapacity,
    uint32_t *sampleCount);

#endif