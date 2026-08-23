#ifndef VIBRATION_ACQUISITION_H
#define VIBRATION_ACQUISITION_H

#include <stdbool.h>
#include <stdint.h>

#define VIBRATION_SAMPLE_COUNT 4U

bool VibrationAcquisition_Init(void);

bool VibrationAcquisition_GetSamples(
    const int16_t **samples,
    uint32_t *sampleCount);

#endif