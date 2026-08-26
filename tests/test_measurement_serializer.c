#include "measurement_types.h"
#include "measurement_serializer.h"
#include <stdio.h>
#include <stdlib.h>

Measurement_t measurement =
{
    .temperatureCdeg = 2350,
    .batteryMv = 3720,
    .vibrationRmsMg = 158,
    .timestamp = 1000
};

uint8_t buffer[MEASUREMENT_SERIALIZED_SIZE];
int main (void)
{
MeasurementSerializer_Serialize(
    &measurement,
    buffer,
    sizeof(buffer));

const uint8_t expected[MEASUREMENT_SERIALIZED_SIZE] =
{
    0x01U,
    0x2EU, 0x09U,
    0x88U, 0x0EU,
    0x9EU, 0x00U, 0x00U, 0x00U,
    0xE8U, 0x03U, 0x00U, 0x00U
};

for (uint32_t i = 0; i < MEASUREMENT_SERIALIZED_SIZE; i++)
{
    if (buffer[i] != expected[i])
    {
        printf(
            "FAIL: byte %u expected 0x%02X, got 0x%02X\n",
            i,
            expected[i],
            buffer[i]);

        return EXIT_FAILURE;
    }

}
printf ("pass the serilizer.\n");
}