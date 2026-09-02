#include "storage_service.h"
#include "external_flash.h"
#include "measurement_serializer.h"
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include "crc32c.h"

#define STORAGE_RECORD_SIZE \
    (MEASUREMENT_SERIALIZED_SIZE + sizeof(uint32_t))
#define STORAGE_CRC_OFFSET MEASUREMENT_SERIALIZED_SIZE


bool StorageService_Init(void)
{
    if (!ExternalFlash_Init())
    {
        return false;
    }

    return true;
}


bool StorageService_SaveMeasurement(const Measurement_t *measurement)
{
    uint8_t record[STORAGE_RECORD_SIZE];
    uint32_t crc;

    if (measurement == NULL)
    {
        return false;
    }

    if (!MeasurementSerializer_Serialize(
            measurement,
            record,
            MEASUREMENT_SERIALIZED_SIZE))
    {
        return false;
    }

    crc = Crc32c_Calculate(record,MEASUREMENT_SERIALIZED_SIZE);

    record[STORAGE_CRC_OFFSET] =(uint8_t)(crc & 0xFFU);

    record[STORAGE_CRC_OFFSET + 1U] =(uint8_t)((crc >> 8U) & 0xFFU);

    record[STORAGE_CRC_OFFSET + 2U] =(uint8_t)((crc >> 16U) & 0xFFU);

    record[STORAGE_CRC_OFFSET + 3U] =(uint8_t)((crc >> 24U) & 0xFFU);

    if (!ExternalFlash_Write(
            0U,
            record,
            sizeof(record)))
    {
        return false;
    }

    return true;
}