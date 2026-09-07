/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "spidrv_usart_master_baremetal.h"


/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  spidrv_app_init(); // will call mct8316z_init()

  void cli_app_init(void); // gk:

  cli_app_init();



}
typedef uint32_t Ecode_t;
typedef void (*SPIDRV_Callback_t)(struct SPIDRV_HandleData *handle,
                                  Ecode_t transferStatus,
                                  int itemsTransferred);

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  spidrv_app_process_action();
}
