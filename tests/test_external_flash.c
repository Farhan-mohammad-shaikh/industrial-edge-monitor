#include "external_flash.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const uint8_t writeData[] =
    {
        0x11U,
        0x22U,
        0x33U,
        0x44U
    };

    uint8_t readData[4] = {0U};

    if (!ExternalFlash_Init())
    {
        printf("FAIL: flash initialization failed.\n");
        return EXIT_FAILURE;
    }

    if (!ExternalFlash_Write(
            10U,
            writeData,
            sizeof(writeData)))
    {
        printf("FAIL: flash write failed.\n");
        return EXIT_FAILURE;
    }

    if (!ExternalFlash_Read(
            10U,
            readData,
            sizeof(readData)))
    {
        printf("FAIL: flash read failed.\n");
        return EXIT_FAILURE;
    }

    for (uint32_t i = 0U; i < sizeof(writeData); i++)
    {
        if (readData[i] != writeData[i])
        {
            printf(
                "FAIL: byte %u expected 0x%02X, got 0x%02X\n",
                i,
                writeData[i],
                readData[i]);

            return EXIT_FAILURE;
        }
    }

    printf("PASS: external flash write/read test.\n");

    return EXIT_SUCCESS;
}