#include "platform_time.h"
#include <stddef.h>

bool PlatformTime_Init(void)
{
    return true;
}


bool PlatformTime_GetTimestamp(uint32_t *timestamp)
{
    if (timestamp == NULL)
    {
        return false;
    }
    
    *timestamp = 1000;

    return true;

}