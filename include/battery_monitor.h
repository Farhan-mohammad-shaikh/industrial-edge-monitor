#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H
#include <stdint.h>
#include <stdbool.h>

bool BatteryMonitor_Init(void);

bool BatteryMonitor_ReadVoltage( uint16_t *batteryMv);


#endif