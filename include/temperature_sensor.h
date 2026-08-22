#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H
#include <stdint.h>
#include <stdbool.h>

bool TemperatureSensor_Init(void);

bool TemperatureSensor_Read( int16_t *temperatureCdeg);


#endif