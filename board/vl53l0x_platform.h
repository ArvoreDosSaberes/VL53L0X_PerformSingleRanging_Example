#ifndef VL53L0X_PLATFORM_H
#define VL53L0X_PLATFORM_H

#include <stdint.h>
#include "vl53l0x_types.h"
#include "vl53l0x_def.h"

#ifdef __cplusplus
extern "C" {
#endif

// Write multiple bytes to a register (platform-specific)
VL53L0X_Error VL53L0X_WriteMultiPlatform(VL53L0X_Dev_t *pdev, uint16_t reg, uint8_t *pdata, uint32_t count);
// Read multiple bytes from a register (platform-specific)
VL53L0X_Error VL53L0X_ReadMultiPlatform(VL53L0X_Dev_t *pdev, uint16_t reg, uint8_t *pdata, uint32_t count);
// Delay in milliseconds
void VL53L0X_Delay(uint32_t ms);
// Get current tick in milliseconds
uint32_t VL53L0X_GetTick(void);

#ifdef __cplusplus
}
#endif

#endif // VL53L0X_PLATFORM_H
