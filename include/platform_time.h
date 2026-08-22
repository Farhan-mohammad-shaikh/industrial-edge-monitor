#ifndef PLATFORM_TIME_H
#define PLATFORM_TIME_H
#include <stdbool.h>
#include <stdint.h>

bool PlatformTime_Init(void);
bool PlatformTime_GetTimestamp(uint32_t *timestamp);

#endif