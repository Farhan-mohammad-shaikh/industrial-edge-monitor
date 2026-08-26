#include "measurement_serializer.h"

#include <stddef.h>
#include <stdint.h>

bool MeasurementSerializer_Serialize(
    const Measurement_t *measurement,
    uint8_t *buffer,
    uint32_t bufferSize)
{
    if (measurement == NULL)
    {
        return false;
    }

    if (buffer == NULL)
    {
        return false;
    }

    if (bufferSize < MEASUREMENT_SERIALIZED_SIZE)
    {
        return false;
    }

    buffer[0] = 1U;

    uint16_t temperatureRaw = (uint16_t)measurement->temperatureCdeg;

    buffer[1] = (uint8_t) (temperatureRaw & 0xFFU);
    buffer[2] = (uint8_t) ((temperatureRaw >> 8) & 0xFFU);

    buffer[3] = (uint8_t) (measurement->batteryMv & 0xFFU);
    buffer[4] = (uint8_t) ((measurement->batteryMv >> 8) & 0xFFU);

    buffer[5] = (uint8_t) (measurement->vibrationRmsMg & 0xFFU);
    buffer[6] = (uint8_t) ((measurement->vibrationRmsMg >> 8) & 0xFFU);
    buffer[7] = (uint8_t) ((measurement->vibrationRmsMg >> 16) & 0xFFU);
    buffer[8] = (uint8_t) ((measurement->vibrationRmsMg >> 24) & 0xFFU);

    buffer[9] = (uint8_t) (measurement->timestamp & 0xFFU);
    buffer[10] = (uint8_t) ((measurement->timestamp >> 8) & 0xFFU);
    buffer[11] = (uint8_t) ((measurement->timestamp >> 16) & 0xFFU);
    buffer[12] = (uint8_t) ((measurement->timestamp >> 24) & 0xFFU);

    return true;
}