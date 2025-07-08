#include "vl53l0x_platform_log.h"
#include <stdarg.h>
#include <stdio.h>

void VL53L0X_Log(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}
