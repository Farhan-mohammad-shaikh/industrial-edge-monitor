#include "application.h"
#include "measurement_service.h"
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    bool initializationSuccessful = Application_Init();
    
    if (initializationSuccessful)
    {
        Application_Run();

        return EXIT_SUCCESS;
    }

    else
    {
        return EXIT_FAILURE;
    }
}