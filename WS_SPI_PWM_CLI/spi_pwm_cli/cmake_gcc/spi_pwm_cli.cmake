####################################################################
# Automatically-generated file. Do not edit!                       #
####################################################################

set(SDK_PATH "C:/Users/gknight/.silabs/slt/installs/conan/p/simpleca33d691c539/p")
set(COPIED_SDK_PATH "simplicity_sdk_2026.6.1")
set(PKG_PATH "C:/Users/gknight/.silabs/slt/installs")

add_library(slc OBJECT
    "../${COPIED_SDK_PATH}/boards/hardware/board/src/sl_board_control_gpio.c"
    "../${COPIED_SDK_PATH}/boards/hardware/board/src/sl_board_init.c"
    "../${COPIED_SDK_PATH}/boards/hardware/driver/mx25_flash_shutdown/src/sl_mx25_flash_shutdown_eusart/sl_mx25_flash_shutdown.c"
    "../${COPIED_SDK_PATH}/platform_core/hardware/driver/configuration_over_swo/src/sl_cos.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/common/src/sl_assert.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/common/src/sl_core_cortexm.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/common/src/sl_slist.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/common/src/sl_string.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/common/src/sl_syscalls.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/Device/SiliconLabs/EFR32MG26/Source/startup_efr32mg26.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/Device/SiliconLabs/EFR32MG26/Source/system_efr32mg26.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/debug/src/sl_debug_swo.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/dma_channel/src/sl_dma_channel.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/dma_channel/src/sl_dma_descriptor_allocator.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/gpio/src/sl_gpio.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/leddrv/src/sl_led.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/leddrv/src/sl_simple_led.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/pwm/src/sl_pwm.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emdrv/spidrv/src/spidrv.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/src/em_burtc.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/src/em_cmu.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/src/em_emu.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/src/em_eusart.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/src/em_gpio.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/src/em_msc.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/src/em_prs.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/src/em_system.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/src/em_timer.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/src/em_usart.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/peripheral/src/sl_hal_eusart.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/peripheral/src/sl_hal_gpio.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/peripheral/src/sl_hal_ldma.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/peripheral/src/sl_hal_prs.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/peripheral/src/sl_hal_syscfg.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/peripheral/src/sl_hal_sysrtc.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/peripheral/src/sl_hal_sysrtc_subsystem.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/peripheral/src/sl_hal_system.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/cli/src/sl_cli.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/cli/src/sl_cli_arguments.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/cli/src/sl_cli_command.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/cli/src/sl_cli_input.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/cli/src/sl_cli_io.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/cli/src/sl_cli_tokenize.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/clock_manager/src/sl_clock_manager.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/clock_manager/src/sl_clock_manager_hal_s2.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/clock_manager/src/sl_clock_manager_init.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/clock_manager/src/sl_clock_manager_init_hal_s2.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_init/src/sl_device_init_dcdc_s2.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_init/src/sl_device_init_emu_s2.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_manager/clocks/sl_device_clock_efr32xg26.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_manager/devices/sl_device_peripheral_hal_efr32xg26.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_manager/dma/sl_device_dma_s2.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_manager/src/sl_device_clock.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_manager/src/sl_device_dma.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_manager/src/sl_device_gpio.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_manager/src/sl_device_peripheral.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/dma_manager/src/sl_dma_manager.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/dma_manager/src/sl_dma_manager_hal_ldma.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/interrupt_manager/src/sl_interrupt_manager_cortexm.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/iostream/src/sl_iostream.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/iostream/src/sl_iostream_dmadrv.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/iostream/src/sl_iostream_eusart.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/iostream/src/sl_iostream_retarget_stdio.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/iostream/src/sl_iostream_stdlib_config.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/iostream/src/sl_iostream_uart.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/memory_manager/src/sl_memory_manager.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/memory_manager/src/sl_memory_manager_dynamic_reservation.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/memory_manager/src/sl_memory_manager_pool.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/memory_manager/src/sl_memory_manager_pool_common.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/memory_manager/src/sl_memory_manager_region.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/memory_manager/src/sl_memory_manager_retarget.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/memory_manager/src/sli_memory_manager_common.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sl_main/src/sl_main_init.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sl_main/src/sl_main_init_memory.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sl_main/src/sl_main_process_action.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sleeptimer/src/sl_sleeptimer.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sleeptimer/src/sl_sleeptimer_hal_burtc.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sleeptimer/src/sl_sleeptimer_hal_sysrtc.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sleeptimer/src/sl_sleeptimer_hal_timer.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/udelay/src/sl_udelay.c"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/udelay/src/sl_udelay_armv6m_gcc.S"
    "../app.c"
    "../autogen/sl_board_default_init.c"
    "../autogen/sl_cli_command_table.c"
    "../autogen/sl_cli_instances.c"
    "../autogen/sl_dma_manager_instances.c"
    "../autogen/sl_event_handler.c"
    "../autogen/sl_iostream_handles.c"
    "../autogen/sl_iostream_init_eusart_instances.c"
    "../autogen/sl_pwm_init.c"
    "../autogen/sl_simple_led_instances.c"
    "../autogen/sl_spidrv_init.c"
    "../autogen/sli_cli_hooks.c"
    "../main.c"
    "../spidrv_usart_master_baremetal.c"
)

target_include_directories(slc PUBLIC
   "../config"
   "../autogen"
   "../."
    "../${COPIED_SDK_PATH}/platform_core/platform/Device/SiliconLabs/EFR32MG26/Include"
    "../${COPIED_SDK_PATH}/platform_core/platform/common/inc"
    "../${COPIED_SDK_PATH}/boards/hardware/board/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/cli/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/cli/src"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/clock_manager/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/clock_manager/src"
    "../${COPIED_SDK_PATH}/cmsis/Core/Include"
    "../${COPIED_SDK_PATH}/cmsis/Core/Include/m-profile"
    "../${COPIED_SDK_PATH}/cmsis/Core/Include/a-profile"
    "../${COPIED_SDK_PATH}/platform_core/hardware/driver/configuration_over_swo/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/debug/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_manager/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/device_init/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/dma_channel/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/dma_manager/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/dma_manager/src"
    "../${COPIED_SDK_PATH}/platform_core/platform/emdrv/common/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/emlib/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/common/errno_error_codes/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/gpio/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/peripheral/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/interrupt_manager/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/interrupt_manager/src"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/interrupt_manager/inc/arm"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/iostream/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/leddrv/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/memory_manager/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/memory_manager/src"
    "../${COPIED_SDK_PATH}/boards/hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_eusart"
    "../${COPIED_SDK_PATH}/platform_core/platform/driver/pwm/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sl_main/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sl_main/src"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sleeptimer/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/sleeptimer/src"
    "../${COPIED_SDK_PATH}/platform_core/platform/emdrv/spidrv/inc"
    "../${COPIED_SDK_PATH}/platform_core/platform/service/udelay/inc"
)

target_compile_definitions(slc PUBLIC
    "DEBUG_EFM=1"
    "EFR32MG26B420F3200IM68=1"
    "SL_CODE_COMPONENT_SYSTEM=system"
    "SL_BOARD_NAME=\"BRD4121A\""
    "SL_BOARD_REV=\"A05\""
    "HARDWARE_BOARD_DEFAULT_RF_BAND_2400=1"
    "HARDWARE_BOARD_SUPPORTS_1_RF_BAND=1"
    "HARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1"
    "HFXO_FREQ=39000000"
    "SL_CODE_COMPONENT_CLOCK_MANAGER=clock_manager"
    "SL_COMPONENT_CATALOG_PRESENT=1"
    "SL_CODE_COMPONENT_DEVICE_PERIPHERAL=device_peripheral"
    "SL_CODE_COMPONENT_DMA_CHANNEL=dma_channel"
    "SL_CODE_COMPONENT_DMA_MANAGER=dma_manager"
    "SL_CODE_COMPONENT_GPIO=gpio"
    "SL_CODE_COMPONENT_HAL_COMMON=hal_common"
    "SL_CODE_COMPONENT_HAL_GPIO=hal_gpio"
    "SL_CODE_COMPONENT_HAL_LDMA=hal_ldma"
    "SL_CODE_COMPONENT_HAL_SYSRTC=hal_sysrtc"
    "SL_CODE_COMPONENT_INTERRUPT_MANAGER=interrupt_manager"
    "CMSIS_NVIC_VIRTUAL=1"
    "CMSIS_NVIC_VIRTUAL_HEADER_FILE=\"cmsis_nvic_virtual.h\""
    "SL_CODE_COMPONENT_MEMORY_MANAGER=memory_manager"
    "SL_CODE_COMPONENT_CORE=core"
    "SL_CODE_COMPONENT_SLEEPTIMER=sleeptimer"
    "SL_CODE_COMPONENT_SPIDRV=spidrv"
)

target_link_libraries(slc PUBLIC
    "-Wl,--start-group"
    "gcc"
    "c"
    "m"
    "nosys"
    "-Wl,--end-group"
)
target_compile_options(slc PUBLIC
    $<$<COMPILE_LANGUAGE:C>:-mcpu=cortex-m33>
    $<$<COMPILE_LANGUAGE:C>:-mthumb>
    $<$<COMPILE_LANGUAGE:C>:-mfpu=fpv5-sp-d16>
    $<$<COMPILE_LANGUAGE:C>:-mfloat-abi=hard>
    $<$<COMPILE_LANGUAGE:C>:-mcmse>
    $<$<COMPILE_LANGUAGE:C>:-Wall>
    $<$<COMPILE_LANGUAGE:C>:-Wextra>
    $<$<COMPILE_LANGUAGE:C>:-Os>
    $<$<COMPILE_LANGUAGE:C>:-fdata-sections>
    $<$<COMPILE_LANGUAGE:C>:-ffunction-sections>
    $<$<COMPILE_LANGUAGE:C>:-fomit-frame-pointer>
    $<$<COMPILE_LANGUAGE:C>:-g>
    $<$<COMPILE_LANGUAGE:C>:--specs=nano.specs>
    $<$<COMPILE_LANGUAGE:C>:-fno-lto>
    $<$<COMPILE_LANGUAGE:CXX>:-mcpu=cortex-m33>
    $<$<COMPILE_LANGUAGE:CXX>:-mthumb>
    $<$<COMPILE_LANGUAGE:CXX>:-mfpu=fpv5-sp-d16>
    $<$<COMPILE_LANGUAGE:CXX>:-mfloat-abi=hard>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-mcmse>
    $<$<COMPILE_LANGUAGE:CXX>:-Wall>
    $<$<COMPILE_LANGUAGE:CXX>:-Wextra>
    $<$<COMPILE_LANGUAGE:CXX>:-O0>
    $<$<COMPILE_LANGUAGE:CXX>:-fdata-sections>
    $<$<COMPILE_LANGUAGE:CXX>:-ffunction-sections>
    $<$<COMPILE_LANGUAGE:CXX>:-fomit-frame-pointer>
    $<$<COMPILE_LANGUAGE:CXX>:-g>
    $<$<COMPILE_LANGUAGE:CXX>:--specs=nano.specs>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-lto>
    $<$<COMPILE_LANGUAGE:ASM>:-mcpu=cortex-m33>
    $<$<COMPILE_LANGUAGE:ASM>:-mthumb>
    $<$<COMPILE_LANGUAGE:ASM>:-mfpu=fpv5-sp-d16>
    $<$<COMPILE_LANGUAGE:ASM>:-mfloat-abi=hard>
    "$<$<COMPILE_LANGUAGE:ASM>:SHELL:-x assembler-with-cpp>"
)

set(post_build_command )
set_property(TARGET slc PROPERTY C_STANDARD 17)
set_property(TARGET slc PROPERTY CXX_STANDARD 17)
set_property(TARGET slc PROPERTY CXX_EXTENSIONS OFF)

target_link_options(slc INTERFACE
    -mcpu=cortex-m33
    -mthumb
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard
    "-T${CMAKE_CURRENT_LIST_DIR}/../autogen/linkerfile.ld"
    --specs=nano.specs
    -Wl,-Map=$<TARGET_FILE_DIR:spi_pwm_cli>/spi_pwm_cli.map
    "SHELL:-Wl,--wrap=_free_r -Wl,--wrap=_malloc_r -Wl,--wrap=_calloc_r -Wl,--wrap=_realloc_r"
    -fno-lto
    -Wl,--gc-sections
)

# BEGIN_SIMPLICITY_STUDIO_METADATA=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END_SIMPLICITY_STUDIO_METADATA