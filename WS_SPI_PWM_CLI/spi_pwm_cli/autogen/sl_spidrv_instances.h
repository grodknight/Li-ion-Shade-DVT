#ifndef SL_SPIDRV_INSTANCES_H
#define SL_SPIDRV_INSTANCES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sl_status.h"
#include "spidrv.h"
extern SPIDRV_Handle_t sl_spidrv_usart_exp_handle;

void sl_spidrv_init_instances(void);

/***************************************************************************//**
 * Set the handle as the default SPIDRV handle.
 *
 * @param[in] handle SPIDRV handle to set as default.
 *
 * @return  Status result
 ******************************************************************************/
sl_status_t sl_spidrv_set_default(SPIDRV_Handle_t handle);

/***************************************************************************//**
 * Get the default SPIDRV handle configured.
 *
 * @return  SPIDRV handle
 ******************************************************************************/
SPIDRV_Handle_t sl_spidrv_get_default(void);

#ifdef __cplusplus
}
#endif

#endif // SL_SPIDRV_INSTANCES_H
