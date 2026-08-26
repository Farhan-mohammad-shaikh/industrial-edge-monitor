CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c11

INCLUDES = -Iinclude

TARGET = industrial-edge-monitor

SOURCES = src/main.c src/application.c src/measurement_service.c src/temperature_sensor.c src/battery_monitor.c src/vibration_processing.c src/platform_time.c src/vibration_acquisition.c src/storage_service.c src/measurement_serializer.c src/external_flash.c
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) -o $(TARGET) -lm

test-vibration:
	$(CC) $(CFLAGS) $(INCLUDES) tests/test_vibration_processing.c src/vibration_processing.c -o test-vibration -lm

test-serializer:
	$(CC) $(CFLAGS) $(INCLUDES) tests/test_measurement_serializer.c src/measurement_serializer.c -o test-serializer -lm

test-external_flash:
	$(CC) $(CFLAGS) $(INCLUDES) tests/test_external_flash.c src/external_flash.c -o test-external_flash -lm
test-storage:
	$(CC) $(CFLAGS) $(INCLUDES) \
	tests/test_storage_service.c \
	src/storage_service.c \
	src/measurement_serializer.c \
	src/external_flash.c \
	-o test-storage