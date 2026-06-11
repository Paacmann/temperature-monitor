#pragma once

#include <stdint.h>

typedef struct {} I2C_HandleTypeDef;

typedef enum {
    HAL_OK = 0
} HAL_StatusTypeDef;

#define HAL_MAX_DELAY 0xFFFFFFFF

static inline void HAL_Delay(int ms) {}
