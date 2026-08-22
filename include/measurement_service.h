#ifndef MEASUREMENT_SERVICE_h
#define MEASUREMENT_SERVICE_h
#include "measurement_types.h"

bool MeasurementService_Init(void);

bool MeasurementService_TakeMeasurement(Measurement_t *measurement);

#endif
