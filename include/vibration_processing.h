#ifndef VIBRATION_PROCESSING_H
#define VIBRATION_PROCESSING_H
#include <stdbool.h>
#include <stdint.h>

bool VibrationProcessing_Init(void);

bool VibrationProcessing_CalculateRms(const int16_t *samples, uint32_t sampleCount, uint32_t *vibrationRmsMg);

#endif