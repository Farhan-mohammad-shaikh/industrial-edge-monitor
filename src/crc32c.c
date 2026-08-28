#include "crc32c.h"

#include <stddef.h>

#define CRC32C_INITIAL_VALUE 0xFFFFFFFFU
#define CRC32C_POLYNOMIAL    0x82F63B78U
#define CRC32C_FINAL_XOR     0xFFFFFFFFU

uint32_t Crc32c_Calculate(
    const uint8_t *data,
    uint32_t length)
{
    uint32_t crc = CRC32C_INITIAL_VALUE;

    if ((data == NULL) || (length == 0U))
    {
        return 0U;
    }

    for (uint32_t byteIndex = 0U;
         byteIndex < length;
         byteIndex++)
    {
        crc ^= data[byteIndex];

        for (uint8_t bitIndex = 0U;
             bitIndex < 8U;
             bitIndex++)
        {
            if ((crc & 1U) != 0U)
            {
                crc =
                    (crc >> 1U) ^
                    CRC32C_POLYNOMIAL;
            }
            else
            {
                crc >>= 1U;
            }
        }
    }

    crc ^= CRC32C_FINAL_XOR;

    return crc;
}