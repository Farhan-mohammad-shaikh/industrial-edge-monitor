#include "crc32c.h"
#include "external_flash.h"
#include "measurement_serializer.h"
#include "measurement_types.h"
#include "storage_service.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define STORAGE_CRC_OFFSET MEASUREMENT_SERIALIZED_SIZE
#define STORAGE_RECORD_SIZE \
    (MEASUREMENT_SERIALIZED_SIZE + sizeof(uint32_t))

int main(void)
{
    Measurement_t measurement =
    {
        .temperatureCdeg = 2350,
        .batteryMv = 3720,
        .vibrationRmsMg = 158,
        .timestamp = 1000
    };

    uint8_t readBuffer[STORAGE_RECORD_SIZE];

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

    uint32_t storedCrc =
        ((uint32_t)readBuffer[STORAGE_CRC_OFFSET]) |
        ((uint32_t)readBuffer[STORAGE_CRC_OFFSET + 1U] << 8U) |
        ((uint32_t)readBuffer[STORAGE_CRC_OFFSET + 2U] << 16U) |
        ((uint32_t)readBuffer[STORAGE_CRC_OFFSET + 3U] << 24U);

    uint32_t calculatedCrc =
        Crc32c_Calculate(
            readBuffer,
            MEASUREMENT_SERIALIZED_SIZE);

    if (storedCrc != calculatedCrc)
    {
        printf(
            "FAIL: stored CRC 0x%08X does not match calculated CRC 0x%08X\n",
            storedCrc,
            calculatedCrc);

        return EXIT_FAILURE;
    }

    printf(
        "PASS: storage CRC verified: 0x%08X\n",
        storedCrc);

    return EXIT_SUCCESS;
}