#ifndef MEASUREMENT_SERIALIZER_H
#define MEASUREMENT_SERIALIZER_H
#define MEASUREMENT_SERIALIZED_SIZE 13U

#include "measurement_types.h"

#include <stdbool.h>
#include <stdint.h>


bool MeasurementSerializer_Serialize(
    const Measurement_t *measurement,
    uint8_t *buffer,
    uint32_t bufferSize);


#endif