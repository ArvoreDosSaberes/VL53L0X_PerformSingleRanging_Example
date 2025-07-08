#ifndef VL53L0X_PLATFORM_LOG_H
#define VL53L0X_PLATFORM_LOG_H

#include "vl53l0x_def.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

// Logging function for VL53L0X
void VL53L0X_Log(const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif // VL53L0X_PLATFORM_LOG_H
