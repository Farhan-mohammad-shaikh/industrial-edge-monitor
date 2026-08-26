#include "external_flash.h"
#include "measurement_serializer.h"
#include "measurement_types.h"
#include "storage_service.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Measurement_t measurement =
    {
        .temperatureCdeg = 2350,
        .batteryMv = 3720,
        .vibrationRmsMg = 158,
        .timestamp = 1000
    };

    uint8_t readBuffer[MEASUREMENT_SERIALIZED_SIZE];

    const uint8_t expected[MEASUREMENT_SERIALIZED_SIZE] =
    {
        0x01U,
        0x2EU, 0x09U,
        0x88U, 0x0EU,
        0x9EU, 0x00U, 0x00U, 0x00U,
        0xE8U, 0x03U, 0x00U, 0x00U
    };

    if (!StorageService_Init())
    {
        printf("FAIL: StorageService_Init failed.\n");
        return EXIT_FAILURE;
    }

    if (!StorageService_SaveMeasurement(&measurement))
    {
        printf("FAIL: StorageService_SaveMeasurement failed.\n");
        return EXIT_FAILURE;
    }

    if (!ExternalFlash_Read(
            0U,
            readBuffer,
            sizeof(readBuffer)))
    {
        printf("FAIL: ExternalFlash_Read failed.\n");
        return EXIT_FAILURE;
    }

    for (uint32_t i = 0U;
         i < MEASUREMENT_SERIALIZED_SIZE;
         i++)
    {
        if (readBuffer[i] != expected[i])
        {
            printf(
                "FAIL: byte %u expected 0x%02X, got 0x%02X\n",
                i,
                expected[i],
                readBuffer[i]);

            return EXIT_FAILURE;
        }
    }

    printf("PASS: storage service integration test.\n");

    return EXIT_SUCCESS;
}