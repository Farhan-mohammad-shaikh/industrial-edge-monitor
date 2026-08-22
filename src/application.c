#include "application.h"
#include "measurement_service.h"
#include "measurement_types.h"
#include <stdio.h>

bool Application_Init(void)

{

    if (MeasurementService_Init())
    {
        printf ("Application Initialized.\n");
        return true;
    }

    return false;

}


void Application_Run(void)
{
    Measurement_t measurement;

    if (!MeasurementService_TakeMeasurement(&measurement))
    {
        printf("Measurement failed.\n");
        return;
    }

    printf("Application Running.\n");
    printf("The temperature is: %d\n", measurement.temperatureCdeg);
    printf("The battery voltage is: %u\n", measurement.batteryMv);
    printf("The vibration RMS is: %u\n", measurement.vibrationRmsMg);
    printf("The timestamp is: %u\n", measurement.timestamp);
}