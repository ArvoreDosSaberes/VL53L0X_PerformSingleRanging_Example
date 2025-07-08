#include "vl53l0x_platform.h"
#include "vl53l0x_types.h"
#include "pico/stdlib.h"
#include <hardware/i2c.h>
#include <hardware/timer.h>
#include <string.h>

VL53L0X_Error VL53L0X_WriteMultiPlatform(VL53L0X_Dev_t *pdev, uint16_t reg, uint8_t *pdata, uint32_t count) {
    uint8_t buf[2 + count];
    buf[0] = (uint8_t)(reg >> 8);
    buf[1] = (uint8_t)(reg & 0xFF);
    memcpy(buf + 2, pdata, count);
    int32_t ret = i2c_write_blocking(pdev->i2c, pdev->address, buf, count + 2, false);
    return (ret == (int32_t)(count + 2)) ? VL53L0X_ERROR_NONE : (VL53L0X_Error)(-1);
}

VL53L0X_Error VL53L0X_ReadMultiPlatform(VL53L0X_Dev_t *pdev, uint16_t reg, uint8_t *pdata, uint32_t count) {
    uint8_t regbuf[2];
    regbuf[0] = (uint8_t)(reg >> 8);
    regbuf[1] = (uint8_t)(reg & 0xFF);
    int32_t ret = i2c_write_blocking(pdev->i2c, pdev->address, regbuf, 2, true);
    if (ret != 2) return (VL53L0X_Error)(-1);
    ret = i2c_read_blocking(pdev->i2c, pdev->address, pdata, count, false);
    return (ret == (int32_t)count) ? VL53L0X_ERROR_NONE : (VL53L0X_Error)(-1);
}

void VL53L0X_Delay(uint32_t ms) {
    sleep_ms(ms);
}

uint32_t VL53L0X_GetTick(void) {
    return (uint32_t)(time_us_64() / 1000);
}
