CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -std=c11

INCLUDES = -Iinclude

TARGET = industrial-edge-monitor

SOURCES = src/main.c src/application.c src/measurement_service.c src/temperature_sensor.c src/battery_monitor.c src/vibration_processing.c src/platform_time.c src/vibration_acquisition.c
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) -o $(TARGET) -lm

test-vibration:
	$(CC) $(CFLAGS) $(INCLUDES) tests/test_vibration_processing.c src/vibration_processing.c -o test-vibration -lm