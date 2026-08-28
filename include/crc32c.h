#ifndef CRC32C_H
#define CRC32C_H

#include <stdint.h>

uint32_t Crc32c_Calculate(
    const uint8_t *data,
    uint32_t length);

#endif