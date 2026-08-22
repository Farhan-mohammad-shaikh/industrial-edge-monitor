#include "measurement_service.h"
#include <stddef.h>
#include "temperature_sensor.h"
#include "vibration_processing.h"
#include "platform_time.h"
#include "battery_monitor.h"



bool MeasurementService_Init(void)
{
    if (!TemperatureSensor_Init())
    {
        return false;
    }

    if (!BatteryMonitor_Init())
    {
        return false;
    }

    if (!VibrationProcessing_Init())
    {
        return false;
    }

    if(!PlatformTime_Init())
    {
        return false;
    }

    return true;

}


bool MeasurementService_TakeMeasurement(Measurement_t *measurement)
{
    if (measurement == NULL)
    {
        return false;
    }

    if (!TemperatureSensor_Read(&measurement->temperatureCdeg))
    {
        return false;
    }

    if (!BatteryMonitor_ReadVoltage(&measurement->batteryMv))
    {
        return false;
    }
    
    if(!VibrationProcessing_GetRms(&measurement->vibrationRmsMg))
    {
        return false;
    }

    if (!PlatformTime_GetTimestamp(&measurement->timestamp))
    {
        return false;
    }
    
    return true;


}