#include "battery_monitor.h"
#include <stddef.h>

bool BatteryMonitor_Init(void)
{
    return true;
}

bool BatteryMonitor_ReadVoltage( uint16_t *batteryMv)
{
    if (batteryMv == NULL)
    {
        return false;
    }

    *batteryMv= 3720;

    return true;

}