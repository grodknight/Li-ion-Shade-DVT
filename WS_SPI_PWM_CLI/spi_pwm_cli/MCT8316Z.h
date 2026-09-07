/*
 * MCT8316Z.h
 *
 *  Created on: Dec 21, 2022
 *      Author: Fabian
 */

#ifndef MCT8316Z_DRIVER_MCT8316Z_H_
#define MCT8316Z_DRIVER_MCT8316Z_H_

// #include "stm32l4xx_hal.h" /* Needed for SPI */
// #include <stdio.h>
#include "stdbool.h"
#include "stdint.h"

#include "MCT18316Z_REGS.h"

#include "spidrv.h"


 void setClockwise(bool clockwise);
 bool isClockwise(void);
 bool motorOn(void);
 bool motorOff(void);
 bool mct8316z_read_reg(uint8_t reg, uint8_t *value);
 
void MCT8316_ReadAllRegs(void);
bool mct8316z_write_reg(uint8_t reg, uint8_t value);
void mct8316z_UnlockRegs(void);

#endif