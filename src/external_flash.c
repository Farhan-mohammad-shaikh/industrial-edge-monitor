#include "external_flash.h"

#include <stddef.h>
#include <string.h>

static uint8_t flashMemory[EXTERNAL_FLASH_SIZE];

bool ExternalFlash_Init(void)
{
    return true;
}

bool ExternalFlash_Write(
    uint32_t address,
    const uint8_t *data,
    uint32_t length)
{
    if (data == NULL)
    {
        return false;
    }

    if (length == 0U)
    {
        return false;
    }

    if (address >= EXTERNAL_FLASH_SIZE)
    {
        return false;
    }

    if (length > (EXTERNAL_FLASH_SIZE - address))
    {
        return false;
    }

    memcpy(
        &flashMemory[address],
        data,
        length);

    return true;
}

bool ExternalFlash_Read(
    uint32_t address,
    uint8_t *data,
    uint32_t length)
{
    if (data == NULL)
    {
        return false;
    }

    if (length == 0U)
    {
        return false;
    }

    if (address >= EXTERNAL_FLASH_SIZE)
    {
        return false;
    }

    if (length > (EXTERNAL_FLASH_SIZE - address))
    {
        return false;
    }

    memcpy(
        data,
        &flashMemory[address],
        length);

    return true;
}