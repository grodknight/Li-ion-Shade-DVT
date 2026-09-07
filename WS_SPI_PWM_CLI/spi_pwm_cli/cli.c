/***************************************************************************//**
 * @file
 * @brief cli bare metal examples functions
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
#include <string.h>
#include <stdio.h>
#include "cli.h"
#include "sl_cli.h"
#include "sl_cli_instances.h"
#include "sl_cli_arguments.h"
#include "sl_cli_handles.h"
#include "sl_assert.h"
// #include "sl_simple_led.h"
#include "sl_simple_led_instances.h"
#include "build_info.h"

#include "MCT8316Z.h"


void echo_str(sl_cli_command_arg_t *arguments);
void echo_int(sl_cli_command_arg_t *arguments);

#if SL_SIMPLE_LED_COUNT > 0
void led_cmd(sl_cli_command_arg_t *arguments);
#endif

#pragma region Prototypes

 void mc_sleep_cmd(sl_cli_command_arg_t *arguments);
 void mc_get_regs_cmd(sl_cli_command_arg_t *arguments);
 void mc_set_reg_cmd(sl_cli_command_arg_t *arguments);
 void mc_get_reg_cmd(sl_cli_command_arg_t *arguments);
 static void mc_motor_on_cmd(sl_cli_command_arg_t *arguments);
 static void mc_motor_off_cmd(sl_cli_command_arg_t *arguments);
 void mc_version_cmd(sl_cli_command_arg_t *arguments);
 void mc_unlock_cmd(sl_cli_command_arg_t *arguments);
 void mc_clr_fault_cmd(sl_cli_command_arg_t *arguments);
 void mc_rotation_cmd(sl_cli_command_arg_t *arguments);

#pragma endregion

#pragma region Constants

const char verString[] =
  "MCT8316Z DVT Version 1.0.3 "
  "Build number: " BUILD_NUMBER " "
  "Build: " __DATE__ " " __TIME__ "\r\n";

static const sl_cli_command_info_t cmd__echostr = \
  SL_CLI_COMMAND(echo_str,
                 "echoes string arguments to the output",
                 "Just a string...",
                 { SL_CLI_ARG_WILDCARD, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cmd__echoint = \
  SL_CLI_COMMAND(echo_int,
                 "echoes integer arguments to the output",
                 "Just a number...",
                 { SL_CLI_ARG_INT8, SL_CLI_ARG_ADDITIONAL, SL_CLI_ARG_END, });

#if SL_SIMPLE_LED_COUNT > 0
static const sl_cli_command_info_t cmd__led = \
  SL_CLI_COMMAND(led_cmd,
                 "Change an led status",
                 "led number: 0 or 1"SL_CLI_UNIT_SEPARATOR "instruction: on, off, or toggle",
                 { SL_CLI_ARG_UINT8, SL_CLI_ARG_WILDCARD, SL_CLI_ARG_END, });
#endif

static const sl_cli_command_info_t cmd__sleep = \
  SL_CLI_COMMAND(mc_sleep_cmd,
                 "Enable / Disable MCT sleep",
                 "0=sleep  1=wake",
                 { SL_CLI_ARG_UINT8, SL_CLI_ARG_WILDCARD, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cmd_MCregs = \
  SL_CLI_COMMAND(mc_get_regs_cmd,
                 "Print all MCT Regs",
                 "n/a",
                 {  SL_CLI_ARG_END });

static const sl_cli_command_info_t cmd_MCgetReg = \
  SL_CLI_COMMAND(mc_get_reg_cmd, 
                "Get a MCT Reg",
                "Reg Address",
                {SL_CLI_ARG_UINT8, SL_CLI_ARG_END});


static const sl_cli_command_info_t cmd_MCsetReg = \
  SL_CLI_COMMAND(mc_set_reg_cmd,
                "Set a MCT Reg",
                "Reg Address"SL_CLI_UNIT_SEPARATOR"Value (hex)",
                {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END});

static const sl_cli_command_info_t cmd_MCclrFault = \
  SL_CLI_COMMAND(mc_clr_fault_cmd,
                "Clear MCT fault",
                "n/a",
                { SL_CLI_ARG_END});

static const sl_cli_command_info_t cmd_MCrotation = \
  SL_CLI_COMMAND(mc_rotation_cmd,
                "Set Motor Spin Orientation",
                "0=Clockwise, 1=Counter-Clockwise",
                { SL_CLI_ARG_UINT8OPT, SL_CLI_ARG_END});

static const sl_cli_command_info_t cmd_MCunlock = \
  SL_CLI_COMMAND(mc_unlock_cmd,
                "Unlock MCT Regs",
                "n/a",
                {SL_CLI_ARG_END});
              
static const sl_cli_command_info_t cmd_MCstart = \
  SL_CLI_COMMAND(mc_motor_on_cmd,
                "DRV_OFF=0",
                "n/a",
                {SL_CLI_ARG_END});

static const sl_cli_command_info_t cmd_MCstop = \
  SL_CLI_COMMAND(mc_motor_off_cmd,
                "DRV_OFF=1",
                "n/a",
                {SL_CLI_ARG_END});

static const sl_cli_command_info_t cmd_MCversion = \
  SL_CLI_COMMAND(mc_version_cmd,
                "Show Version",
                "n/a",
                {SL_CLI_ARG_END});

#pragma endregion

void printMCversion(void)
{
  printf("Version %s\r\n",verString);
}

static sl_cli_command_entry_t a_table[] = {
  { "echo_str",   &cmd__echostr, false },
  { "echo_int",   &cmd__echoint, false },
  { "led",        &cmd__led, false },
  { "MCsleep",    &cmd__sleep, false },
  { "MCregs",     &cmd_MCregs, false },
  { "MCgetReg",   &cmd_MCgetReg, false },
  { "MCsetReg",   &cmd_MCsetReg, false },
  { "MCclrFlt",   &cmd_MCclrFault, false }, 
  { "MCsetRot",   &cmd_MCrotation, false },
  { "MCunlock",   &cmd_MCunlock, false },  
  { "MCgo",      &cmd_MCstart, false },
  { "MCstop",    &cmd_MCstop, false },
  { "Ver",       &cmd_MCversion, false },
  { NULL, NULL,   false },
};

static sl_cli_command_group_t a_group = {
  { NULL },
  false,
  a_table,
};

sl_cli_command_group_t *command_group = &a_group;

#pragma region Command Functions

/***************************************************************************//**
 * Callback for echo_str
 *
 * This function is used as a callback when the echo_str command is called
 * in the cli. It simply echoes back all the arguments provided as strings.
 ******************************************************************************/
void echo_str(sl_cli_command_arg_t *arguments)
{
  char *ptr_string;

  printf("<<echo_str command>>\r\n");

  // Read all the arguments provided as strings and print them back
  for (int i = 0; i < sl_cli_get_argument_count(arguments); i++) {
    ptr_string = sl_cli_get_argument_string(arguments, i);

    printf("%s\r\n", ptr_string);
  }
}

/***************************************************************************//**
 * Callback for echo_int
 *
 * This function is used as a callback when the echo_int command is called
 * in the cli. It simply echoes back all the arguments provided as integers.
 ******************************************************************************/
void echo_int(sl_cli_command_arg_t *arguments)
{
  int8_t argument_value;

  printf("<<echo_int command>>\r\n");

  // Read all the arguments provided as integers and print them back
  for (int i = 0; i < sl_cli_get_argument_count(arguments); i++) {
    argument_value = sl_cli_get_argument_int8(arguments, i);

    printf("%i\r\n", argument_value);
  }
}

#if SL_SIMPLE_LED_COUNT > 0
/***************************************************************************//**
 * Callback for the led
 *
 * This function is used as a callback when the led command is called
 * in the cli. The command is used to turn on, turn off and toggle leds.
 *  LED 0 off, LED 0 on
 ******************************************************************************/
void led_cmd(sl_cli_command_arg_t *arguments)
{
  uint8_t led_number;
  char *instruction;
  sl_led_t led;

  // Make sure that both the arguments were provided
  if (sl_cli_get_argument_count(arguments) < 2) {
    printf("Please provide inputs.\r\n");
    return;
  }

  // Read the provided led number and verify it is valid
  led_number = sl_cli_get_argument_uint8(arguments, 0);
  if (led_number > SL_SIMPLE_LED_COUNT - 1) {
    printf("Invalid led. Only led(s) available: 0 to %d\r\n", SL_SIMPLE_LED_COUNT - 1);
    return;
  }

// Get a handle to the appropriate LED
#if SL_SIMPLE_LED_COUNT > 1  // Check if more than one LED is available
  led = (led_number == 0) ? sl_led_led0 : sl_led_led1;
#else
  led = sl_led_led0; // Only one LED is available, so always use sl_led_led0
#endif

  // Get the instruction provided
  instruction = sl_cli_get_argument_string(arguments, 1);

  if (strcmp(instruction, "on") == 0) {
    // led on instruction provided
    sl_led_turn_on(&led);
  } else if (strcmp(instruction, "off") == 0) {
    // led off instruction provided
    sl_led_turn_off(&led);
  } else if (strcmp(instruction, "toggle") == 0) {
    // led toggle instruction provided
    sl_led_toggle(&led);
  } else {
    // led off instruction provided
    printf("Incorrect instruction. Please use on, off or toggle\r\n");
  }
}
#endif

static void mc_motor_on_cmd(sl_cli_command_arg_t *arguments)
{
  (void)arguments;  // unused parameter
  motorOn();
}

static void mc_motor_off_cmd(sl_cli_command_arg_t *arguments)
{
  (void)arguments;  // unused parameter
  motorOff();
}

void mc_version_cmd(sl_cli_command_arg_t *arguments)
{
  (void)arguments;  // unused parameter
  printMCversion();
}

void mc_get_regs_cmd(sl_cli_command_arg_t *arguments)
{
  (void)arguments;  // unused parameter
  MCT8316_ReadAllRegs();
}

void mc_set_reg_cmd(sl_cli_command_arg_t *arguments)
{
  uint8_t reg;
  uint8_t value;

  // Make sure that both the arguments were provided
  if (sl_cli_get_argument_count(arguments) < 2) {
    printf("Provide Reg Adr and Value in hex.\r\n");
    return;  
  }

  reg   = sl_cli_get_argument_uint8(arguments, 0);
  value = sl_cli_get_argument_uint8(arguments, 1);

  mct8316z_write_reg(reg, value);
  
}

void mc_get_reg_cmd(sl_cli_command_arg_t *arguments)
{
  uint8_t reg;
  uint8_t value;

  // Make sure arguments were provided
  if (sl_cli_get_argument_count(arguments) < 1) {
    printf("Provide Reg Adr in decimal\r\n");
    return;  
  }
  reg   = sl_cli_get_argument_uint8(arguments, 0);

  mct8316z_read_reg(reg, &value); 

}

void mc_clr_fault_cmd(sl_cli_command_arg_t *arguments)
{
  (void)arguments;  // unused parameter
  uint8_t value;

  mct8316z_read_reg(MCT_REG_CTRL2, &value); 

  printf("Clear Fault\r\n");
  value  |=  STATUS_REGISTER_FAULT_FAULT_CONDITION_DETECTED;
  mct8316z_write_reg(MCT_REG_CTRL2, value);
  
}

void mc_rotation_cmd(sl_cli_command_arg_t *arguments)
{
  if (sl_cli_get_argument_count(arguments) < 1) {
    printf("Rotation %s", isClockwise() ? "CW\r\n" : "CCW\r\n");
    return;  
  }

  uint8_t arg1 = sl_cli_get_argument_uint8(arguments, 0);

  if(arg1 == 0)
  {
    printf("Set Clockwise\r\n");
    setClockwise(true);
  }
  else if (arg1 == 1)
  {
    printf("Set Counter-Clockwise\r\n");
    setClockwise(false);
  }
  else
  {
    printf("Invalid argument. Use 0 for Clockwise or 1 for Counter-Clockwise.\r\n");
  }

}

void mc_sleep_cmd(sl_cli_command_arg_t *arguments) {
   uint8_t value;

 // Make sure that both the arguments were provided
  if (sl_cli_get_argument_count(arguments) < 1) {
      printf("Please provide 0 or 1.\r\n");
  }
    value = sl_cli_get_argument_uint8(arguments, 0);
    if(value == 0)
        sl_gpio_clear_pin(PB6);

    else
        sl_gpio_set_pin(PB6);

 }

void mc_unlock_cmd(sl_cli_command_arg_t *arguments)
{
  (void)arguments;  // unused parameter
  printf("Unlocking Regs.\r\n");

  mct8316z_UnlockRegs();
  
}
#pragma endregion

void cli_app_init(void)
{
  bool status;

  status = sl_cli_command_add_command_group(sl_cli_cli1_handle, command_group);
  EFM_ASSERT(status);

}

/***************************************************************************//**
 * Ticking function
 ******************************************************************************/
void cli_app_process_action(void)
{
}


#if 0 // Add PWM CODE
// Add PWM CODE
// ADD CODE FOR PWM, USE FOR NOW

#include "sl_pwm.h"
#include "sl_gpio.h"

/** PWM polarity selection */
SL_ENUM(sl_pwm_polarity_t) {
  /** PWM polarity active high */
  PWM_ACTIVE_HIGH = 0,
  /** PWM polarity active low */
  PWM_ACTIVE_LOW = 1,
};

/**
 * PWM driver instance.
 * Allocated by the application. The application must
 * not modify the contents of this handle and should not depend on its values.
 */
typedef struct sl_pwm_instance {
  /** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */
  TIMER_TypeDef *timer; /**< TIMER instance */
  uint8_t channel;      /**< TIMER channel */
  uint8_t port;         /**< GPIO port */
  uint8_t pin;          /**< GPIO pin */
  uint8_t location;     /**< GPIO location */
  /** @endcond */
} sl_pwm_instance_t;

/**
 * PWM driver configuration
 */
typedef struct sl_pwm_config {
  int frequency;              /**< PWM frequency */
  sl_pwm_polarity_t polarity; /**< PWM polarity */
} sl_pwm_config_t;

/**************************************************************************//**
 * @brief
 *   Initialize PWM driver.
 *
 * @param[in] pwm
 *   PWM driver instance
 *
 * @param[in] config
 *   Driver configuration
 *
 * @return
 *   SL_STATUS_OK if there are no errors.
 *****************************************************************************/
sl_status_t sl_pwm_init(sl_pwm_instance_t *pwm, sl_pwm_config_t *config);

/**************************************************************************//**
 * @brief
 *   Deinitialize PWM driver.
 *
 * @param[in] pwm
 *   PWM driver instance
 *
 * @return
 *   SL_STATUS_OK if there are no errors.
 *****************************************************************************/
sl_status_t sl_pwm_deinit(sl_pwm_instance_t *pwm);

/**************************************************************************//**
 * @brief
 *   Start generating PWM waveform
 *
 * @param[in] pwm
 *   PWM driver instance
 *****************************************************************************/
void sl_pwm_start(sl_pwm_instance_t *pwm);

/**************************************************************************//**
 * @brief
 *   Stop generating PWM waveform
 *
 * @param[in] pwm
 *   PWM driver instance
 *****************************************************************************/
void sl_pwm_stop(sl_pwm_instance_t *pwm);

/**************************************************************************//**
 * @brief
 *   Set duty cycle for PWM waveform.
 *
 * @param[in] pwm
 *   PWM driver instance
 *
 * @param[in] percent
 *   Percent of the PWM period waveform is in the state defined
 *   as the active polarity in the driver configuration
 *****************************************************************************/
void sl_pwm_set_duty_cycle(sl_pwm_instance_t *pwm, uint8_t percent);

/**************************************************************************/
/**
 * @brief
 *   Set duty cycle for PWM waveform.
 *
 * @param[in] pwm
 *   PWM driver instance
 *
 * @return
 *   Percent of the PWM period waveform is in the state defined
 *   as the active polarity in the driver configuration
 *****************************************************************************/
uint8_t sl_pwm_get_duty_cycle(sl_pwm_instance_t *pwm);
int main( void ) * {  //  sl_pwm_led0 => pwmMot
     sl_pwm_instance_t sl_pwm_led0 = {
      .timer    = TIMER3,
      .channel  = 1,
      .port     = SL_GPIO_PORT_D,
      .pin      = 2,
      .location = 0,
    };
 
    sl_pwm_config_t pwm_led0_config = {
      .frequency = 10000,
      .polarity  = PWM_ACTIVE_HIGH,
    };
	
    // Initialize PWM
    sl_pwm_init(&sl_pwm_led0, &pwm_led0_config);
    // Set duty cycle to 40%
    sl_pwm_set_duty_cycle(&sl_pwm_led0, 40);
    // Enable PWM output
    sl_pwm_start(&sl_pwm_led0);
  }
#endif