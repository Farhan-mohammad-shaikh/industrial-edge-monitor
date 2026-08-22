#include "temperature_sensor.h"
#include <stddef.h>

bool TemperatureSensor_Init(void)
{
    return true;
}

bool TemperatureSensor_Read( int16_t *temperatureCdeg)
{
    if (temperatureCdeg == NULL)
    {
        return false;
    }

    *temperatureCdeg = 4536;

    return true;

}