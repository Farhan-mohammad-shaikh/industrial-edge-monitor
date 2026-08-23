#ifndef STORAGE_SERVICE_H
#define STORAGE_SERVICE_H
#include "measurement_types.h"

#include <stdbool.h>

bool StorageService_Init(void);

bool StorageService_SaveMeasurement(const Measurement_t *measurement);

#endif