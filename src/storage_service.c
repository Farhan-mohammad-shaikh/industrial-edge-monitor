#include "storage_service.h"
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

bool StorageService_Init(void)
{
    return true;
}

bool StorageService_SaveMeasurement(const Measurement_t *measurement)
{
    if (measurement ==NULL)
    {
        return false;
    }
    printf("The saved temperature is: %d\n", measurement->temperatureCdeg);
    printf("The saved battery voltage is: %u\n", measurement->batteryMv);
    printf("The saved vibration RMS is: %u\n", measurement->vibrationRmsMg);
    printf("The saved timestamp is: %u\n", measurement->timestamp);

    return true;
}