#include "crc32c.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const uint8_t testData[] =
    {
        '1', '2', '3', '4', '5',
        '6', '7', '8', '9'
    };

    const uint32_t expectedCrc = 0xE3069283U;

    uint32_t calculatedCrc =
        Crc32c_Calculate(
            testData,
            sizeof(testData));

    if (calculatedCrc != expectedCrc)
    {
        printf(
            "FAIL: expected 0x%08X, got 0x%08X\n",
            expectedCrc,
            calculatedCrc);

        return EXIT_FAILURE;
    }

    printf(
        "PASS: CRC32C = 0x%08X\n",
        calculatedCrc);

    return EXIT_SUCCESS;
}