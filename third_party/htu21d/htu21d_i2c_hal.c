/*
 * Copyright (c) 2022, Mezael Docoy
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "htu21d_i2c_hal.h" 
#include "stm32f1xx_hal.h"
/* Hardware Specific Components */

/* I2C User Defines */

int16_t htu21d_i2c_hal_init(void *context)
{
	if (!context)
	{
		return HTU21D_ERR;
	}

	return HTU21D_OK;
}

int16_t htu21d_i2c_hal_read(void *context,uint8_t address, uint8_t *reg, uint8_t *data, uint16_t count)
{
    //int16_t err = HTU21D_OK;

    if (!context || !reg || !data)
    {
    	return HTU21D_ERR;
    }


    htu21d_context_t *ctx = (htu21d_context_t *)context;

    if (!ctx->hi2c)
    {
        return HTU21D_ERR;
    }

    //User implementation here
    if (HAL_I2C_Master_Transmit(ctx->hi2c,
        address << 1,
        reg,
        1,
        HAL_MAX_DELAY) != HAL_OK)
    {
    	return HTU21D_ERR;
    }

        /* read response */
    if (HAL_I2C_Master_Receive(ctx->hi2c,
    	address << 1,
        data,
        count,
        HAL_MAX_DELAY) != HAL_OK)
    {
    	return HTU21D_ERR;
    }

    return HTU21D_OK ;
}

int16_t htu21d_i2c_hal_write(void *context,uint8_t address, uint8_t *data, uint16_t count)
{
    //int16_t err = HTU21D_OK;

    if (!context || !data || !count)
    {
    	return HTU21D_ERR;
    }


    htu21d_context_t *ctx = (htu21d_context_t *)context;

    if (!ctx->hi2c)
    {
        return HTU21D_ERR;
    }
    //User implementation here
    if (HAL_I2C_Master_Transmit(ctx->hi2c,
       address << 1,
       data,
       count,
       HAL_MAX_DELAY) != HAL_OK)
     {
    	return HTU21D_ERR;
     }


    return HTU21D_OK;
}

void htu21d_i2c_hal_ms_delay(void *context ,uint32_t ms) {

	(void)context;
	//User implementation here
	HAL_Delay(ms);
}

