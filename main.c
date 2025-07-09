#include <stdio.h>
#include "pico/stdlib.h"
#include <hardware/i2c.h>
#include "vl53l0x_api.h"
#include "vl53l0x_platform.h"
#include "vl53l0x_platform_log.h"

// I2C defines
#define I2C_PORT i2c1
#define I2C_SDA 2
#define I2C_SCL 3

int main()
{
    stdio_init_all();

    while(!stdio_usb_connected())
    {
        sleep_ms(100);
    }

    vl53l0x_platform_log("VL53L0X init\n");

    // I2C Initialisation. Using it at 400Khz.
    i2c_init(I2C_PORT, 400*1000);
    
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    vl53l0x_platform_log("Porta I2C inicializada\n");
    
    // Setup VL53L0X dev
    VL53L0X_Dev_t dev = {
        .I2cDevAddr = 0x29,
        .comms_type = VL53L0X_COMMS_I2C,
        .comms_speed_khz = 400
    };
    VL53L0X_Error status = VL53L0X_DataInit(&dev);
    if (status != VL53L0X_ERROR_NONE) {
        vl53l0x_platform_log("VL53L0X init failed\n");
        return -1;
    }

    while (1) {
        uint16_t distance;
        status = VL53L0X_PerformSingleRangingMeasurement(&dev, &distance);
        if (status == VL53L0X_ERROR_NONE) {
            printf("Distance: %u mm\n", distance);
        } else {
            printf("Ranging error: %d\n", status);
        }
        sleep_ms(500);
    }
}
