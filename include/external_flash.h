#ifndef EXTERNAL_FLASH_H
#define EXTERNAL_FLASH_H
#include <stdint.h>
#include <stdbool.h>

#define EXTERNAL_FLASH_SIZE 256U

bool ExternalFlash_Init(void);

bool ExternalFlash_Write(
    uint32_t address,
    const uint8_t *data,
    uint32_t length);

bool ExternalFlash_Read(
    uint32_t address,
    uint8_t *data,
    uint32_t length);

#endif