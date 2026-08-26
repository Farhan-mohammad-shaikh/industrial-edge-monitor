#include "storage_service.h"
#include "external_flash.h"
#include "measurement_serializer.h"
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>


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
    uint8_t serializedRecord[MEASUREMENT_SERIALIZED_SIZE];

    if (measurement == NULL)
    {
        return false;
    }

    if (!MeasurementSerializer_Serialize(
            measurement,
            serializedRecord,
            sizeof(serializedRecord)))
    {
        return false;
    }

    if (!ExternalFlash_Write(
            0U,
            serializedRecord,
            sizeof(serializedRecord)))
    {
        return false;
    }

    return true;
}