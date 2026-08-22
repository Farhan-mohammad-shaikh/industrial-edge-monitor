#ifndef MEASUREMENT_TYPES_H
#define MEASUREMENT_TYPES_H
#include <stdint.h> 
#include <stdbool.h>


typedef struct 
{
    int16_t temperatureCdeg;
    uint16_t batteryMv;
    uint32_t vibrationRmsMg;
    uint32_t timestamp;
} Measurement_t;




#endif